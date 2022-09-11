package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node {
    int idx;
    int cost;

    Node(int idx, int cost) {
        this.idx = idx;
        this.cost = cost;
    }
}

public class n1504 {
    static int N, E;
    static ArrayList<ArrayList<Node>> edge;
    static int[] dist;
    static final int INF = 200000000;

    public static int dijk(int start, int end) {
        Arrays.fill(dist, INF);

        PriorityQueue<Node> que = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        que.offer(new Node(start, 0));
        dist[start] = 0;

        while(!que.isEmpty()) {
            Node curNode = que.poll();

            if (dist[curNode.idx] < curNode.cost) {
                continue;
            }

            for (int i = 0; i < edge.get(curNode.idx).size(); i++) {
                Node nxtNode = edge.get(curNode.idx).get(i);

                if (dist[nxtNode.idx] > curNode.cost + nxtNode.cost) {
                    dist[nxtNode.idx] = curNode.cost + nxtNode.cost;
                    que.offer(new Node(nxtNode.idx, dist[nxtNode.idx]));
                }
            }
        }
        return dist[end];
    }

    public static void main(String[] args) throws IOException {
        // INPUT
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        edge = new ArrayList<ArrayList<Node>>();
        dist = new int[N+1];
        for (int i = 0; i <= N; i++) {
            edge.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            edge.get(a).add(new Node(b, l));
            edge.get(b).add(new Node(a, l));
        }

        st = new StringTokenizer(br.readLine());
        int N1 = Integer.parseInt(st.nextToken());
        int N2 = Integer.parseInt(st.nextToken());

        int cost1 = 0;
        cost1 += dijk(1, N1);
        cost1 += dijk(N1, N2);
        cost1 += dijk(N2, N);

        int cost2 = 0;
        cost2 += dijk(1, N2);
        cost2 += dijk(N2, N1);
        cost2 += dijk(N1, N);

        int ans = (cost1 >= INF && cost2 >= INF) ? -1 : Math.min(cost1, cost2);
        System.out.println(ans);

    }
}

package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class n11725 {
    private static boolean[] visit = new boolean[100001];
    private static int[] parent = new int[100001];
    private static ArrayList<Integer>[] connection = new ArrayList[100001];

    private static void dfs(int node) {
        visit[node] = true;

        for (int i = 0; i < connection[node].size(); i++) {
            int next_node = connection[node].get(i);
            if (!visit[next_node]) {
                parent[next_node] = node;
                dfs(next_node);
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int node = Integer.parseInt(br.readLine());

        for (int i = 1; i <= node; i++) {
            connection[i] = new ArrayList<Integer>();
        }

        int a, b;
        for (int i = 0; i < node-1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            connection[a].add(b);
            connection[b].add(a);
        }

        dfs(1);

        for (int i = 2; i <= node; i++) {
            System.out.println(parent[i]);
        }
    }
}

package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class n5430 {
    final static int FRONT = 0;
    final static int BACK = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String command = br.readLine();
            int n = Integer.parseInt(br.readLine());

            String arr = br.readLine();
            arr = arr.substring(1, arr.length()-1);
            Deque<Integer> que = new ArrayDeque<>();
            if (n == 0) {
                if (command.contains("D")) {
                    System.out.println("error");
                }
                else System.out.println("[]");
                continue;
            }
            else {
                StringTokenizer st = new StringTokenizer(arr, ",");
                for (int i = 0; i < n; ++i) que.addLast(Integer.parseInt(st.nextToken()));
            }

            int idx = 0;
            int pointer = FRONT;
            boolean iserror = false;
            while (command.length() > idx) {
                if (command.charAt(idx) == 'R') pointer = (pointer+1)%2;
                else if (command.charAt(idx) == 'D') {
                    if (que.isEmpty()) {
                        iserror = true;
                        System.out.println("error");
                        break;
                    }

                    if (pointer == FRONT) {
                        que.pollFirst();
                    }
                    else if (pointer == BACK){
                        que.pollLast();
                    }
                }
                ++idx;
            }

            if (iserror) continue;

            System.out.print("[");
            if (pointer == FRONT) {
                while (que.size() > 1) System.out.print(que.pollFirst() + ",");
            }
            else if (pointer == BACK){
                while (que.size() > 1) System.out.print(que.pollLast() + ",");
            }
            if (!que.isEmpty()) System.out.print(que.pollFirst());
            System.out.println("]");

        }
    }
}

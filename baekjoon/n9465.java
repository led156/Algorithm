package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n9465 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            /* INPUT */
            int n = Integer.parseInt(br.readLine());

            int[][] board = new int[2][n];
            for (int i = 0; i < 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }


            /* SOLUTION */
            int[][] dp = new int[2][n+1];
            dp[0][1] = board[0][0];
            dp[1][1] = board[1][0];
            for (int i = 2; i <= n; i++) {
                dp[0][i] = Math.max(dp[1][i-1], dp[1][i-2]) + board[0][i-1];
                dp[1][i] = Math.max(dp[0][i-1], dp[0][i-2]) + board[1][i-1];
            }


            System.out.println(Math.max(dp[0][n], dp[1][n]));
        }
    }
}
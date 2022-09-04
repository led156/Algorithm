package baekjoon;

import java.util.Scanner;

public class n11660 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int num;
        int[][] sum = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                num = sc.nextInt();
                sum[i+1][j+1] = num + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }
        }

        int x1, y1, x2, y2;
        for (int i = 0; i < M; i++) {
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();

            System.out.println(sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
        }




    }
}

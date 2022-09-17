package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n1041 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());


        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        long maxs = Math.max(A, B);
        long C = Long.parseLong(st.nextToken());
        maxs = Math.max(maxs, C);
        long D = Long.parseLong(st.nextToken());
        maxs = Math.max(maxs, D);
        long E = Long.parseLong(st.nextToken());
        maxs = Math.max(maxs, E);
        long F = Long.parseLong(st.nextToken());
        maxs = Math.max(maxs, F);

        if (N == 1) {
            System.out.println(A+B+C+D+E+F-maxs);
            return ;
        }

        long n1 = Math.min(A, F);
        long n2 = Math.min(B, E);
        long n3 = Math.min(C, D);
        long min1 = Math.min(n1, Math.min(n2, n3));
        long min2 = Math.min(n1+n2, Math.min(n1+n3, n2+n3));
        long min3 = n1+n2+n3;


        long ans = min3*4;
        ans += min1*(4*(N-2)*(N-1) + (N-2)*(N-2));
        ans += min2*(4*(N-1)+4*(N-2));

        System.out.println(ans);
    }
}

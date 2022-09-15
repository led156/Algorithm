package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class n1351 {
    static Long N, P, Q;
    static HashMap<Long, Long> dp = new HashMap<Long, Long>();

    static Long Dp(Long i) {
        if (dp.containsKey(i))
            return dp.get(i);
        else {
            Long value = Dp((i/P)) + Dp((i/Q));
            dp.put(i, value);
            return value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        P = Long.parseLong(st.nextToken());
        Q = Long.parseLong(st.nextToken());

        //dp = new HashMap<Integer, Integer>();
        dp.put(Long.valueOf(0), Long.valueOf(1));

        System.out.println(Dp(N));
    }
}

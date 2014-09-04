import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskGame solver = new TaskGame();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskGame {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        TreeSet<Integer> candidates = new TreeSet<Integer>();
        for (int i = 1; i <= n; i++) {
            candidates.add(n / i + 1);
        }
        candidates.add(1);

        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < n; ++i) {
            ans.append('F');
        }
        int us = 0;
        int[] um = new int[n+1];
        int[] dp = new int[n+1];
        for (int candidate : candidates) {
            if (candidate + candidate > n) break;
            for (int i = 0; i < candidate; ++i) {
                dp[i] = 0;
            }
            for (int i = candidate; i <= n; ++i) {
                ++us;
                for (int j = 0; j <= i - j - candidate; ++j) {
                    int v = (dp[j] ^ dp[i - j - candidate]);
                    um[v] = us;
                }

                for (int j = 0; ; ++j) {
                    if (um[j] != us) {
                        dp[i] = j;
                        break;
                    }
                }
            }

            if (dp[n] == 0) {
                ans.setCharAt(candidate - 1, 'S');
            }
        }
        out.println(ans.toString());
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine().trim();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

}


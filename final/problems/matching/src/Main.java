import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
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
		TaskMatching solver = new TaskMatching();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskMatching {

    public static final int MOD = (int)1e9 + 7;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int smallN = in.nextInt();
        int bigN = in.nextInt();
        int m = in.nextInt();
        boolean[][] g = new boolean[bigN][smallN];
        for (int i = 0; i < m; ++i) {
            int small = in.nextInt() - 1;
            int big = in.nextInt() - 1;
            g[big][small] = true;
        }

        long[][] dp = new long[bigN + 1][(int) Mask3Bits.getMaxMask(smallN)];
        ArrayUtils.fill(dp, -1);
        out.println(rec(0, 0, dp, bigN, smallN, g));
    }

    private long rec(int v, int mask, long[][] dp, int bigN, int smallN, boolean[][] g) {
        if (dp[v][mask] != -1) {
            return dp[v][mask];
        }
        if (v == bigN) {
            long res = 1;
            for (int i = 0; i < smallN; ++i) {
                if (Mask3Bits.getBit(mask, i) == 1) {
                    res = 0;
                    break;
                }
            }
            dp[v][mask] = res;
            return res;
        }
        long res = 0;
        int newMask = mask;
        for (int i = 0; i < smallN; ++i) {
            if (g[v][i]) {
                int bit = Mask3Bits.getBit(mask, i);
                if (bit != 2) {
                    res += rec(v + 1, Mask3Bits.setBit(mask, i, 2), dp, bigN, smallN, g);
                    if (res >= MOD) {
                        res -= MOD;
                    }
                }
                if (bit == 0) {
                    newMask = Mask3Bits.setBit(newMask, i, 1);
                }
            }
        }
        res += rec(v + 1, newMask, dp, bigN, smallN, g);
        if (res >= MOD) {
            res -= MOD;
        }
        dp[v][mask] = res;
        return res;
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

class Mask3Bits {
    public static int[] p3 = new int[20];
    static {
        p3[0] = 1;
        for (int i = 1; i < p3.length; ++i) {
            p3[i] = p3[i-1] * 3;
        }
    }

    public static int getMaxMask(int size) {
        return p3[size];
    }

    public static int getBit(int mask, int k) {
        return (int) (mask / p3[k] % 3);
    }

    public static int setBit(int mask, int k, int value) {
        return mask + p3[k] * (value - getBit(mask, k));
    }

}

class ArrayUtils {

    public static void fill(long[][] a, int value) {
        for (int i = 0; i < a.length; ++i) {
            Arrays.fill(a[i], value);
        }
    }

}


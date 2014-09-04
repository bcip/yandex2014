import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
public class GameBrute {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		WeirdGame solver = new WeirdGame();
		solver.solve(1, in, out);
		out.close();
	}
}

class WeirdGame {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        for (int n = 3; n <= 1000; n += 2) {
            out.println(n + ": " + getIt(n));
        }
    }

    private int getIt(int n) {
        int[] gr = new int[n+1];
        Arrays.fill(gr, -1);
        for (int i = 1; i <= n; ++i) {
            int gra = getGrandi(n, i, gr);
            if (gra == 0) {
                return i;
            }
        }
        return -1;
    }

    private int getGrandi(int n, int i, int[] gr) {
        if (n < i) {
            return 0;
        }
        if (gr[n] != -1) return gr[n];
        TreeSet<Integer> dict = new TreeSet<Integer>();
        for (int start = 0; start < n; ++start) {
            int left = start;
            int right = n - (start + i);
            dict.add(getGrandi(left, i, gr) ^ getGrandi(right, i, gr));
        }
        for (int j = 0; ; ++j) {
            if (!dict.contains(j)) {
                gr[n] = j;
                return j;
            }
        }
    }
}

class InputReader {
    private BufferedReader reader;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

}


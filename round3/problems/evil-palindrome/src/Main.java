import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		EvilPalindromAFBruteForward solver = new EvilPalindromAFBruteForward();
		solver.solve(1, in, out);
		out.close();
	}
}

class EvilPalindromAFBruteForward {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String numberAsString = in.nextString();
        char[] n = numberAsString.toCharArray();
        int step = in.nextInt();

        if (step < 0) {
            out.println(-1);
            return;
        }

        for (int i = 0; i < step; ++i) {
            n = getNextPalindrome(n);
        }
        for (char c : n) {
            out.print(c);
        }
        out.println();
    }

    private char[] getNextPalindrome(char[] n) {
        if (n[0] == '-') {
            return new char[] {'0'};
        }
        char[] b = n.clone();
        int middle = n.length / 2 + n.length % 2;
        int middle2 = middle - 1;
        if (n.length % 2 == 1) --middle2;
        for (int i = middle, j = middle2; i < n.length; ++i, --j) {
            b[i] = b[j];
        }

        --middle;
        boolean ok = false;
        char[] a = n.clone();
        for (int i = middle; i >= 0; --i) {
            if (a[i] < '9') {
                ++a[i];
                for (int j = i + 1; j <= middle; ++j) {
                    a[j] = '0';
                }
                middle = n.length / 2 + n.length % 2;
                for (int k = middle, j = middle2; k < n.length; ++k, --j) {
                    a[k] = a[j];
                }
                ok = true;
                break;
            }
        }

        if (compare(a, b) < 0) {
            if (compare(n, a) < 0) {
                return a;
            }
            if (compare(n, b) < 0) {
                return b;
            }
        }

        if (compare(n, b) < 0) {
            return b;
        }
        if (compare(n, a) < 0) {
            return a;
        }

        if (!ok) {
            char[] res = new char[n.length + 1];
            Arrays.fill(res, '0');
            res[0] = res[res.length-1] = '1';
            return res;
        }

        return null;
    }

    private int compare(char[] a, char[] b) {
        if (a.length != b.length) return a.length - b.length;
        for (int i = 0; i < a.length; ++i) {
            if (a[i] != b[i]) return a[i] - b[i];
        }
        return 0;
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


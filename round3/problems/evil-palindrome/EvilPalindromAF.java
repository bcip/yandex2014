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
public class EvilPalindromAF {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		EvilPalindrome solver = new EvilPalindrome();
		solver.solve(1, in, out);
		out.close();
	}
}

class EvilPalindrome {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String numberAsString = in.nextString();
        char[] n = numberAsString.toCharArray();
        int step = in.nextInt();

        if (!isPalindrome(n)) {
            n = getNextPalindrome(n);
            if (step > 0) {
                --step;
            }
            if (step == 0) {
                for (char c : n) {
                    out.print(c);
                }
                out.println();
                return;
            }
        }

        if (step > 0) {
            n = getNextKPalindrome(n, step);
        } else {
            n = getPrevKPalindrome(n, -step);
        }
        if (n == null) {
            out.println(-1);
        } else {
            for (char c : n) {
                out.print(c);
            }
            out.println();
        }
    }

    private char[] getPrevKPalindrome(char[] n, int step) {
        StringBuilder builder = new StringBuilder("");

        int middle = n.length / 2;
        if (n.length % 2 == 0) --middle;
        for (int i = 0; i <= middle; ++i) builder.append(n[i]);
        BigInteger nn = new BigInteger(builder.toString());

        BigInteger all10 = BigInteger.ONE;
        for (int i = 0; i < builder.length()-1; ++i) all10 = all10.multiply(BigInteger.TEN);

        char[] result = recBack(nn, builder.length(), n.length % 2 == 1, step, all10);
        return result;
    }

    private char[] recBack(BigInteger nn, int length, boolean hasCenter, int step, BigInteger all10) {
        if (nn.compareTo(BigInteger.ZERO) <= 0) {
            if (nn.compareTo(BigInteger.ZERO) == 0 && step == 0) {
                return new char[] {'0'};
            }
            return null;
        }

        BigInteger d = nn.subtract(all10);

        if (d.compareTo(BigInteger.valueOf(step)) >= 0) {
            nn = nn.subtract(BigInteger.valueOf(step));
            return createAnswer(nn, hasCenter);
        }
        BigInteger newN = all10.subtract(BigInteger.ONE);
        if (hasCenter) {
            return recBack(newN, length - 1, false, step - d.intValue() - 1, all10.divide(BigInteger.TEN));
        } else {
            return recBack(newN.multiply(BigInteger.TEN).add(BigInteger.valueOf(9)), length, true, step - d.intValue() - 1, all10);
        }
    }

    private char[] getNextKPalindrome(char[] n, int step) {
        StringBuilder builder = new StringBuilder("");

        int middle = n.length / 2;
        if (n.length % 2 == 0) --middle;
        for (int i = 0; i <= middle; ++i) builder.append(n[i]);
        BigInteger nn = new BigInteger(builder.toString());

        BigInteger all9 = BigInteger.ZERO;
        for (int i = 0; i < builder.length(); ++i) all9 = all9.multiply(BigInteger.TEN).add(BigInteger.valueOf(9));

        char[] result = recFront(nn, builder.length(), n.length % 2 == 1, step, all9);
        return result;
    }

    private char[] recFront(BigInteger nn, int length, boolean hasCenter, int step, BigInteger all9) {
        BigInteger d = all9.subtract(nn);
        if (d.compareTo(BigInteger.valueOf(step)) >= 0) {
            nn = nn.add(BigInteger.valueOf(step));
            return createAnswer(nn, hasCenter);
        }
        BigInteger newN = all9.add(BigInteger.ONE);
        if (!hasCenter) {
            return recFront(newN, length + 1, true, step - d.intValue() - 1, all9.multiply(BigInteger.TEN).add(BigInteger.valueOf(9)));
        } else {
            return recFront(newN.divide(BigInteger.TEN), length, false, step - d.intValue() - 1, all9);
        }
    }

    private char[] createAnswer(BigInteger nn, boolean hasCenter) {
        char[] s = nn.toString().toCharArray();
        char[] c = new char[s.length * 2 - (hasCenter ? 1 : 0)];
        for (int i = 0; i < s.length; ++i) {
            c[i] = s[i];
        }
        for (int i = c.length - 1, j = 0; i > j; --i, ++j) {
            c[i] = c[j];
        }
        return c;
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

    private boolean isPalindrome(char[] n) {
        for (int i = 0, j = n.length-1; i < j; ++i, --j) {
            if (n[i] != n[j]) return false;
        }
        return true;
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


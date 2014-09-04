import java.io.InputStreamReader;
import java.io.IOException;
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
public class EvilPalindromAFBrute {
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
        if (numberAsString.length() > 5) {
            // I cannot solve that :)
            return;
        }
        int n = Integer.parseInt(numberAsString);
        int step = in.nextInt();
        if (Math.abs(step) > 10) {
            return;
        }
        if (step > 0) {
            for (int i = 0; i < step; ++i) {
                n = getNext(n);
            }
        } else {
            step = Math.abs(step);
            for (int i = 0; i < step; ++i) {
                n = getPrevious(n);
            }
        }
        if (n < 0) {
            out.println(-1);
        } else {
            out.println(n);
        }
    }

    private int getPrevious(int n) {
        --n;
        if (n < 0) return -1;
        while (!isPalindrome(n)) {
            --n;
            if (n < 0) return -1;
        }
        return n;
    }

    private int getNext(int n) {
        if (n < 0) return 0;
        ++n;
        while (!isPalindrome(n)) {
            ++n;
        }
        return n;
    }

    private boolean isPalindrome(int n) {
        String s = String.valueOf(n);
        for (int i = 0, j = s.length()-1; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
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


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
public class aliens_af {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskUFO solver = new TaskUFO();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskUFO {
    private static final int MAX_VALUE = 1000001;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] quantity = new int[MAX_VALUE];
        int numberOfDifferent = 0;
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            ++quantity[x];
            if (quantity[x] == 1) ++numberOfDifferent;
        }
        for (;; ++numberOfDifferent) {
            int cur = 0;
            int dim = (1 << (numberOfDifferent - 1));
            for (int i = 0; i < MAX_VALUE; ++i) {
                cur += (quantity[i] + dim - 1) / dim;
            }
            if (cur <= numberOfDifferent) {
                out.println(numberOfDifferent);
                return;
            }
        }
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


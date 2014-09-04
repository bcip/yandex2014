import java.io.PrintStream;
import java.io.BufferedReader;
import java.util.Comparator;
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
		TaskMatrix solver = new TaskMatrix();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskMatrix {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        int k = in.nextInt();
        double[][] a = new double[k + 3][k + 3];
        a[0][0] = 0.5;
        a[1][0] = 0.5;
        a[0][k+1] = 0.5;
        for (int i = 1; i <= k+1; ++i) {
            a[i+1][i] = 0.5;
            a[1][i] = 0.5;
        }
        a[k+2][k+1] = 0.5;
        a[k+2][k+2] = 1;

        a = MatrixUtils.pow(a, n);
        out.printf("%.12f\n", a[k+2][0]);
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

    public long nextLong() {
        return Long.parseLong(nextString());
    }

}

class MatrixUtils {

    private static double[][] buildDoubleOne(int n) {
        double[][] r = new double[n][n];
        for (int i = 0; i < n; ++i) {
            r[i][i] = 1;
        }
        return r;
    }

    public static double[][] pow(double[][] aa, long p) {
        double[][] a = aa.clone();
        int n = a.length;
        double[][] r = buildDoubleOne(n);
        for (long i = p; i > 0; i /= 2) {
            if (i % 2 == 1) r = mul(r, a);
            a = mul(a, a);
        }
        return r;
    }

    private static double[][] mul(double[][] a, double[][] b) {
        int n = a.length;
        double[][] r = new double[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int p = 0; p < n; ++p) {
                    r[i][j] += a[i][p] * b[p][j];
                }
            }
        }
        return r;
    }

}


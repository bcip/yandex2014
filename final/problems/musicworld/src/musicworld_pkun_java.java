import java.io.*;
import java.util.StringTokenizer;

public class musicworld_pkun_java {

    private static final int MOD = 1000000007;
    private BufferedReader in;
    private StringTokenizer tokenizer;
    private PrintWriter out;

    public static void main(String[] args) throws IOException {
        new musicworld_pkun_java().run();
    }

    int modPow(int a, int b) {
        if (b == 0) return 1;
        if ((b & 1) == 1) return (int) ((modPow(a, b - 1) * (long) a) % MOD);
        int temp = modPow(a, b / 2);
        return (int) ((temp * (long) temp) % MOD);
    }

    void solve() throws IOException {
        Function x = new Function(1, 1, 0);
        Function f = x;
        int n = nextInt();
        for (int it = 0; it < n; it++) {
            int k = nextInt();
            int g[] = new int[k + 1];
            int sum = 0;
            for (int i = 0; i <= k; i++) {
                g[i] = nextInt();
                sum += g[i];
            }
            sum = modPow(sum, MOD - 2);
            for (int i = 0; i <= k; i++)
                g[i] = (int) ((g[i] * (long) sum) % MOD);
            Function p = new Function(0, 0, 0);
            for (int i = k; i >= 0; i--)
                p = p.multiply(x).add(new Function(g[i], 0, 0));
            f = f.substitute(p);
        }
        long result = f.secondDerivative;
        result = (result * (MOD + 1) / 2) % MOD;
        out.println(result);
    }

    public void run() {
        try {
            boolean oj;
            try {
                oj = System.getProperty("LOCAL") == null;
            } catch (Exception e) {
                oj = true;
            }
            Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("musicworld.in");
            Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("musicworld.out");
            in = new BufferedReader(reader);
            tokenizer = null;
            out = new PrintWriter(writer);
            solve();
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    class Function {
        final long value;
        final long derivative;
        final long secondDerivative;

        Function(long value, long derivative, long secondDerivative) {
            this.value = value % MOD;
            this.derivative = derivative % MOD;
            this.secondDerivative = secondDerivative % MOD;
        }

        Function substitute(Function f) {
            assert f.value == 1;
            return new Function(
                    value,
                    derivative * f.derivative,
                    (secondDerivative * f.derivative) % MOD * f.derivative + derivative * f.secondDerivative
            );
        }

        Function add(Function f) {
            return new Function(
                    value + f.value,
                    derivative + f.derivative,
                    secondDerivative + f.secondDerivative
            );
        }

        Function multiply(Function f) {
            return new Function(
                    value * f.value,
                    derivative * f.value + f.derivative * value,
                    secondDerivative * f.value + 2 * derivative * f.derivative + value * f.secondDerivative
            );
        }

        @Override
        public String toString() {
            return "Function{" +
                    "value=" + value +
                    ", derivative=" + derivative +
                    ", secondDerivative=" + secondDerivative +
                    '}';
        }
    }

}

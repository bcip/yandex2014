import java.io.*;
import java.util.*;
import java.math.*;

public class Main_fast {
	static BufferedReader reader;
	static StringTokenizer tokenizer = null;

	static String nextToken() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(nextToken());
	}

	static int[] read_perm(int n) {
		int p[] = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = nextInt();
			--p[i];
		}
		int cnt[] = new int[n + 1];
		Arrays.fill(cnt, 0);
		int tot = 0;
		for (int i = 0; i < n; ++i) {
			if (p[i] == -1) {
				continue;
			}
			int a = i, c = 0;
			while (p[a] != -1) {
				int nx = p[a];
				p[a] = -1;
				++c;
				a = nx;
			}
			if (cnt[c] == 0) ++tot;
			++cnt[c];
		}
		int res[] = new int[2 * tot];
		int cur = 0;
		for (int i = 0; i <= n; ++i) {
			if (cnt[i] == 0) continue;
			res[2 * cur] = i;
			res[2 * cur + 1] = cnt[i];
			++cur;
		}
		return res;
	}
	static int gcd(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) a %= b; else
			b %= a;
		}
		return a + b;
	}
	public static void main(String[] args) {
		reader = new BufferedReader(new InputStreamReader(System.in));
		int n = nextInt();
		
		int X[] = read_perm(n);
		int Y[] = read_perm(n);
		int Z[] = read_perm(n);
		
		long ans = 0;
		for (int i = 0; i < X.length; i += 2) {
			for (int j = 0; j < Y.length; j += 2) {
				int g = gcd(X[i], Y[j]);
				long t = (long)X[i] * Y[j] / g;
				g *= X[i + 1] * Y[j + 1];
				for (int z = 0; z < Z.length; z += 2) {
					ans += (long)g * gcd((int)(t % Z[z]), Z[z]) * Z[z + 1];
				}
			}
		}
		
		System.out.println(ans);
	}
}
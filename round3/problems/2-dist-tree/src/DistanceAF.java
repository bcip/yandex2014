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
public class DistanceAF {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TreeTask solver = new TreeTask();
		solver.solve(1, in, out);
		out.close();
	}
}

class TreeTask {
    Tree tree;
    long[] dp;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        tree = new Tree();
        int n = in.nextInt();
        tree.readTreeEdges(n, n-1, in, false);
        dp = new long[n];
        out.println(dfs(0, -1));
    }

    private long dfs(int v, int p) {
        dp[v] = 0;
        int numberOfChildren = 0;
        for (int i = tree.first[v]; i != -1; i = tree.next[i]) {
            if (tree.to[i] != p) {
                dfs(tree.to[i], v);
                ++numberOfChildren;
                dp[v] += dp[tree.to[i]];
            }
        }
        dp[v] += (numberOfChildren * 1L * (numberOfChildren - 1)) / 2;
        if (p != -1) {
            dp[v] += numberOfChildren;
        }
        return dp[v];
    }

}

class Tree {
    public int[] first;
    public int[] next;
    public int[] to;
    int numberOfEdges;
    public int n, m;

    public Tree() {}

    public void readTreeEdges(int n, int m, InputReader in, boolean givenFromZero) {
        this.n = n;
        this.m = m;
        numberOfEdges = 0;
        first = new int[n];
        Arrays.fill(first, -1);
        next = new int[2 * m];
        to = new int[2 * m];
        for (int i = 0; i < m; ++i) {
            int f = in.nextInt();
            int t = in.nextInt();
            if (!givenFromZero) {
                --f;
                --t;
            }
            AddEdge(f, t);
        }
    }

    private void AddEdge(int a, int b) {
        next[numberOfEdges] = first[a];
        first[a] = numberOfEdges;
        to[numberOfEdges] = b;
        ++numberOfEdges;

        next[numberOfEdges] = first[b];
        first[b] = numberOfEdges;
        to[numberOfEdges] = a;
        ++numberOfEdges;
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


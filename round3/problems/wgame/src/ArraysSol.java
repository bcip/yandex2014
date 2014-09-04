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
public class ArraysSol {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskGame solver = new TaskGame();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskGame {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        //TreeSet<Integer> candidates = new TreeSet<Integer>();
        int[] candidates = new int[n + 5];
        int count = 0;
        candidates[count++] = 1;
        for (int i = 1; i <= n; i++) {
            //candidates.add(n / i + 1);
            int value = n / i + 1;
            if (value + value <= n) {
                candidates[count++] = value;
            }
        }
        //candidates.add(1);
        //Arrays.sort(candidates, 0, count);
        candidates = ArrayUtils.sortAndUnique(candidates);

        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < n; ++i) {
            ans.append('F');
        }
        int us = 0;
        int[] um = new int[n+1];
        int[] dp = new int[n+1];
        for (int candidate : candidates) {
            if (candidate == 0) continue;
            for (int i = 0; i < candidate; ++i) {
                dp[i] = 0;
            }
            for (int i = candidate; i <= n; ++i) {
                ++us;
                for (int j = 0; j <= i - j - candidate; ++j) {
                    int v = (dp[j] ^ dp[i - j - candidate]);
                    um[v] = us;
                }

                for (int j = 0; ; ++j) {
                    if (um[j] != us) {
                        dp[i] = j;
                        break;
                    }
                }
            }

            if (dp[n] == 0) {
                ans.setCharAt(candidate - 1, 'S');
            }
        }
        out.println(ans.toString());
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

class ArrayUtils {

    public static int[] sortAndUnique(int[] a) {
        int[] b = a.clone();
        Arrays.sort(b);
        ArrayList<Integer> temp = new ArrayList<Integer>();
        temp.add(b[0]);
        int size = 1;
        for (int i = 1; i < b.length; ++i) {
            if (temp.get(size-1) != b[i]) {
                temp.add(b[i]);
                ++size;
            }
        }
        return CollectionUtils.toArray(temp);
    }

}

class CollectionUtils {
    public static int[] toArray(Collection<Integer> collection) {
        int[] result = new int[collection.size()];
        int index = 0;
        for (int element : collection) {
            result[index++] = element;
        }
        return result;
    }

}


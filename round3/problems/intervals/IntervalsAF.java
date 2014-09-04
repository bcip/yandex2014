import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class IntervalsAF {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Intervals solver = new Intervals();
		solver.solve(1, in, out);
		out.close();
	}
}

class Intervals {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), D = in.nextInt();
        int[] a = new int[n];
        Map<Integer, TreeSet<Integer>> dict = new HashMap<Integer, TreeSet<Integer>>();
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            int minusD = a[i] - D;
            int plusD = a[i] + D;
            addToDict(minusD, i, dict);
            addToDict(plusD, i, dict);
        }
        Set<Interval> intervalsSet = new HashSet<Interval>();
        for (int i = 0; i < n; ++i) {
            if (!dict.containsKey(a[i])) continue;
            TreeSet<Integer> set = dict.get(a[i]);
            Integer posPrev = set.lower(i);
            Integer posNext = set.higher(i);
            if (posPrev != null) {
                intervalsSet.add(new Interval(posPrev, i));
            }
            if (posNext != null) {
                intervalsSet.add(new Interval(i, posNext));
            }
        }
        List<Interval> intervals = new ArrayList<Interval>();
        intervals.addAll(intervalsSet);
        Collections.sort(intervals);

        int size = intervals.size();
        if (size == 0) {
            out.println(0);
            return;
        }
        int[] max = new int[size];
        max[size-1] = intervals.get(size-1).right;
        for (int i = size-2; i >= 0; --i) {
            max[i] = Math.min(intervals.get(i).right, max[i+1]);
        }
        long result = 0;
        int prevLength = 0;
        for (int i = 0; i < size; ++i) {
            int curLength = intervals.get(i).left - prevLength + 1;
            prevLength = intervals.get(i).left + 1;
            result += curLength * 1L * (n - max[i]);
        }
        out.println(result);
    }

    class Interval implements Comparable<Interval> {
        int left, right;

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Interval interval = (Interval) o;

            if (left != interval.left) return false;
            if (right != interval.right) return false;

            return true;
        }

        public int hashCode() {
            int result = left;
            result = 31 * result + right;
            return result;
        }

        Interval(int left, int right) {
            this.left = left;
            this.right = right;
        }

        public int compareTo(Interval o) {
            if (left != o.left) return left - o.left;
            return right - o.right;
        }
    }

    private void addToDict(int x, int pos, Map<Integer, TreeSet<Integer>> dict) {
        TreeSet<Integer> set;
        if (!dict.containsKey(x)) {
            set = new TreeSet<Integer>();
        } else {
            set = dict.get(x);
        }
        set.add(pos);
        dict.put(x, set);
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


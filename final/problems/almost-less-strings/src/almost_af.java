import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Alex Fetisov
 */
public class almost_af {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskAlmostEquals solver = new TaskAlmostEquals();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskAlmostEquals {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        final String[] initSet = new String[n];
        final String[] modifiedSet = new String[n];
        Integer[] initOrder = new Integer[n];
        Integer[] modifiedOrder = new Integer[n];
        boolean[] eq = new boolean[n];
        for (int i = 0; i < n; ++i) {
            initOrder[i] = modifiedOrder[i] = i;
            initSet[i] = in.nextString();
            boolean found = false;
            for (int j = 0; j < initSet[i].length(); ++j) {
                if (initSet[i].charAt(j) != 'a') {
                    modifiedSet[i] = initSet[i].substring(0, j) + "a" + initSet[i].substring(j+1);
                    found = true;
                    break;
                }
            }
            if (!found) {
                modifiedSet[i] = initSet[i];
                eq[i] = true;
            }
        }
        Arrays.sort(initOrder, new Comparator<Integer>() {
            @Override
            public int compare(Integer first, Integer second) {
                return initSet[second].compareTo(initSet[first]);
            }
        });
        Arrays.sort(modifiedOrder, new Comparator<Integer>() {
            @Override
            public int compare(Integer first, Integer second) {
                return modifiedSet[second].compareTo(modifiedSet[first]);
            }
        });
        int ptr = 0;
        long res = 0;
        for (int i : modifiedOrder) {
            while (ptr < n && initSet[initOrder[ptr]].compareTo(modifiedSet[i]) > 0) ++ptr;
            res += ptr;
            if (!eq[i]) --res;
        }
        out.println(res);
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


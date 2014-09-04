import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class stack_ek {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	double[] winSkipOnes = new double[1025];
	double[] winSkipTwos = new double[1025];
	double[] removeSkipOnes = new double[2049];
	double[] removeSkipTwos = new double[2049];
	double probability;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int probability = in.readInt();
		this.probability = probability / 100d;
		int[] stack = IOUtils.readIntArray(in, count);
		Arrays.fill(winSkipOnes, -1);
		Arrays.fill(winSkipTwos, -1);
		Arrays.fill(removeSkipOnes, -1);
		Arrays.fill(removeSkipTwos, -1);
		double[] result = new double[count + 1];
		double answer = Double.POSITIVE_INFINITY;
		Arrays.fill(result, Double.POSITIVE_INFINITY);
		result[count] = 0;
		for (int i = count; i > 0; i--) {
			int current = stack[i - 1];
			boolean good = true;
			for (int j = i - 1; j > 0; j--) {
				result[j] = Math.min(result[j], Math.min(removeSkipOnes(current), removeSkipTwos(current)) + result[i]);
				if (current > stack[j - 1]) {
					good = false;
					break;
				}
				current += stack[j - 1];
			}
			if (good) {
				answer = Math.min(answer, Math.min(winSkipOnes(current), winSkipTwos(current)) + result[i]);
				result[0] = Math.min(result[0], Math.min(removeSkipOnes(current), removeSkipTwos(current)) + result[i]);
			}
		}
		answer = Math.min(answer, Math.min(winSkipOnes(0), winSkipTwos(0)) + result[0]);
		if (Double.isInfinite(answer) || Double.isNaN(answer)) {
			throw new RuntimeException();
		}
		out.printLine(answer);
	}

	private double removeSkipTwos(int current) {
		if (current >= removeSkipTwos.length) {
			return Double.POSITIVE_INFINITY;
		}
		if (removeSkipTwos[current] != -1) {
			return removeSkipTwos[current];
		}
		if ((current & 1) == 0) {
			if (probability != 1) {
				removeSkipTwos[current] = probability * removeSkipTwos(current + 1) + (1 - probability) * removeSkipTwos(current + 2);
			} else {
				removeSkipTwos[current] = removeSkipTwos(current + 1);
			}
		} else {
			removeSkipTwos[current] = 1 / probability - 1 + removeSkipTwos(current + 1);
		}
		if ((current & (current - 1)) == 0) {
			removeSkipTwos[current] = Math.min(removeSkipTwos[current], 1);
		}
		return removeSkipTwos[current];
	}

	private double winSkipTwos(int current) {
		if (current >= winSkipTwos.length) {
			return Double.POSITIVE_INFINITY;
		}
		if (winSkipTwos[current] != -1) {
			return winSkipTwos[current];
		}
		if ((current & 1) == 0) {
			if (probability != 1) {
				winSkipTwos[current] = probability * winSkipTwos(current + 1) + (1 - probability) * winSkipTwos(current + 2);
			} else {
				winSkipTwos[current] = winSkipTwos(current + 1);
			}
		} else {
			winSkipTwos[current] = 1 / probability - 1 + winSkipTwos(current + 1);
		}
		if (current == 1024) {
			winSkipTwos[current] = Math.min(winSkipTwos[current], 0);
		}
		return winSkipTwos[current];
	}

	private double removeSkipOnes(int current) {
		if (current >= removeSkipOnes.length || probability == 1) {
			return Double.POSITIVE_INFINITY;
		}
		if (removeSkipOnes[current] != -1) {
			return removeSkipOnes[current];
		}
		if ((current & 1) == 0) {
			removeSkipOnes[current] = 1 / (1 - probability) - 1 + removeSkipOnes(current + 2);
		} else {
			removeSkipOnes[current] = 1 + removeSkipOnes(current - 1);
		}
		if ((current & (current - 1)) == 0) {
			removeSkipOnes[current] = Math.min(removeSkipOnes[current], 1);
		}
		return removeSkipOnes[current];
	}

	private double winSkipOnes(int current) {
		if (current >= winSkipOnes.length || probability == 1) {
			return Double.POSITIVE_INFINITY;
		}
		if (winSkipOnes[current] != -1) {
			return winSkipOnes[current];
		}
		if ((current & 1) == 0) {
			winSkipOnes[current] = 1 / (1 - probability) - 1 + winSkipOnes(current + 2);
		} else {
			winSkipOnes[current] = 1 + winSkipOnes(current - 1);
		}
		if (current == 1024) {
			winSkipOnes[current] = Math.min(winSkipOnes[current], 0);
		}
		return winSkipOnes[current];
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

}


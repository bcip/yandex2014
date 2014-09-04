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
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	double[] result = new double[1025];
	double[] skipOnes = new double[1025];
	double[] removeResult = new double[2049];
	double[] removeSkipOnes = new double[2049];
	double probability;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int percent = in.readInt();
		probability = percent / 100d;
		int[] stack = IOUtils.readIntArray(in, count);
		Arrays.fill(result, -1);
		Arrays.fill(skipOnes, -1);
		Arrays.fill(removeResult, -1);
		Arrays.fill(removeSkipOnes, -1);
		double[] answer = new double[count + 1];
		Arrays.fill(answer, Double.POSITIVE_INFINITY);
		answer[count] = 0;
		double result = Double.POSITIVE_INFINITY;
		for (int i = count; i > 0; i--) {
			int current = 0;
			answer[i - 1] = Math.min(answer[i - 1], answer[i] + 1);
			for (int j = i - 1; j >= 0; j--) {
				if (current > stack[j])
					break;
				current += stack[j];
				answer[j] = Math.min(answer[j], answer[i] + getRemove(current));
				if (j == 0)
					result = Math.min(result, answer[i] + get(current));
			}
		}
		result = Math.min(result, answer[0] + get(0));
		out.printLine(result);
	}

	private double get(int total) {
		if (result[total] != -1)
			return result[total];
		if (total == 1024)
			return result[total] = 0;
		if ((total & 1) == 0)
			return result[total] = probability * get(total + 1) + (1 - probability) * get(total + 2);
		else
			return result[total] = Math.min(getSkip(total - 1) + 1, get(total + 1) + 1 / probability - 1);
	}

	private double getSkip(int total) {
		if (skipOnes[total] != -1)
			return skipOnes[total];
		if (total == 1024)
			return skipOnes[total] = 0;
		if (probability == 1)
			return skipOnes[total] = Double.POSITIVE_INFINITY;
		return skipOnes[total] = 1 / (1 - probability) - 1 + getSkip(total + 2);
	}

	private double getRemove(int total) {
		if (removeResult[total] != -1)
			return removeResult[total];
		removeResult[total] = Double.POSITIVE_INFINITY;
		if (total != 2048) {
			if ((total & 1) == 0)
				removeResult[total] = probability * getRemove(total + 1) + (1 - probability) * getRemove(total + 2);
			else
				removeResult[total] = Math.min(getRemoveSkip(total - 1) + 1, getRemove(total + 1) + 1 / probability - 1);
		}
		return removeResult[total] = Math.min(removeResult[total], Integer.bitCount(total));
	}

	private double getRemoveSkip(int total) {
		if (removeSkipOnes[total] != -1)
			return removeSkipOnes[total];
		removeSkipOnes[total] = Double.POSITIVE_INFINITY;
		if (total != 2048 && probability != 1)
			removeSkipOnes[total] = 1 / (1 - probability) - 1 + getRemoveSkip(total + 2);
		return removeSkipOnes[total] = Math.min(removeSkipOnes[total], Integer.bitCount(total));
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


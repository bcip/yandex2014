import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.Queue;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
import java.util.Collection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Comparator;
import java.util.AbstractSet;
import java.util.AbstractCollection;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class dice_ek {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	int[][] permutations = {
		{0, 1, 4, 5, 3, 2},
		{2, 3, 1, 0, 4, 5},
		{4, 5, 2, 3, 1, 0},
		{0, 1, 3, 2, 4, 5}
	};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int[] cube = IOUtils.readIntArray(in, 6);
		List<char[]> planeList = new ArrayList<>();
		while (!in.isExhausted()) {
			planeList.add(in.readString().toCharArray());
		}
		char[][] plane = new char[planeList.size()][];
		for (int i = 0; i < plane.length; i++) {
			plane[i] = planeList.get(i);
		}
		int[] current = new int[6];
		Queue<State> queue = new ArrayDeque<>();
		boolean[][] seen = new boolean[plane.length][plane[0].length];
		for (int i = 0; i < plane.length && queue.size() == 0; i++) {
			for (int j = 0; j < plane[0].length; j++) {
				if (plane[i][j] != '0') {
					seen[i][j] = true;
					queue.add(new State(0, 2, 3, 4, 5, i, j));
					current[0] = plane[i][j] - '0';
					break;
				}
			}
		}
		while (!queue.isEmpty()) {
			State state = queue.poll();
			for (State next : state.positions()) {
				if (MiscUtils.isValidCell(next.row, next.column, plane.length, plane[0].length) && plane[next.row][next.column] != '0' && !seen[next.row][next.column]) {
					if (current[next.position] != 0 && current[next.position] != plane[next.row][next.column] - '0') {
						out.printLine("No");
						return;
					}
					current[next.position] = plane[next.row][next.column] - '0';
					queue.add(next);
					seen[next.row][next.column] = true;
				}
			}
		}
		Cube start = new Cube(cube);
		Cube target = new Cube(current);
		Queue<Cube> cubes = new ArrayDeque<>();
		cubes.add(start);
		Set<Cube> set = new EHashSet<>();
		while (!cubes.isEmpty()) {
			Cube cur = cubes.poll();
			if (target.equals(cur)) {
				out.printLine("Yes");
				return;
			}
			for (int[] permutation : permutations) {
				Cube next = new Cube(ArrayUtils.multiplyPermutations(cur.planes, permutation));
				if (!set.contains(next)) {
					set.add(next);
					cubes.add(next);
				}
			}
		}
		out.printLine("No");
	}

	static class Cube {
		int[] planes;

		Cube(int[] planes) {
			this.planes = planes;
		}

		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Cube cube = (Cube) o;

			if (!Arrays.equals(planes, cube.planes)) return false;

			return true;
		}

		public int hashCode() {
			return Arrays.hashCode(planes);
		}
	}

	static class State {
		int position;
		int toLeft;
		int toRight;
		int toTop;
		int toBottom;

		int row;
		int column;

		State(int position, int toLeft, int toRight, int toTop, int toBottom, int row, int column) {
			this.position = position;
			this.toLeft = toLeft;
			this.toRight = toRight;
			this.toTop = toTop;
			this.toBottom = toBottom;
			this.row = row;
			this.column = column;
		}

		State right() {
			return new State(toRight, position, position ^ 1, toTop, toBottom, row, column + 1);
		}

		State left() {
			return new State(toLeft, position ^ 1, position, toTop, toBottom, row, column - 1);
		}

		State bottom() {
			return new State(toBottom, toLeft, toRight, position, position ^ 1, row + 1, column);
		}

		State top() {
			return new State(toTop, toLeft, toRight, position ^ 1, position, row - 1, column);
		}

		State[] positions() {
			return new State[]{right(), left(), bottom(), top()};
		}
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

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
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

class MiscUtils {

	public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

}

class EHashSet<E> extends AbstractSet<E> {
    private static final Object VALUE = new Object();
    private final Map<E, Object> map;

	public EHashSet() {
		this(4);
	}

	public EHashSet(int maxSize) {
		map = new EHashMap<E, Object>(maxSize);
	}

	public EHashSet(Collection<E> collection) {
		this(collection.size());
		addAll(collection);
	}

	public boolean contains(Object o) {
        return map.containsKey(o);
	}

	public boolean add(E e) {
		if (e == null)
			return false;
		return map.put(e, VALUE) == null;
	}

	public boolean remove(Object o) {
		if (o == null)
			return false;
		return map.remove(o) != null;
	}

	public void clear() {
        map.clear();
	}

	public Iterator<E> iterator() {
        return map.keySet().iterator();
	}

	public int size() {
		return map.size();
	}
}

class ArrayUtils {

	public static int[] multiplyPermutations(int[] first, int[] second) {
		int count = first.length;
		int[] result = new int[count];
		for (int i = 0; i < count; i++) {
			result[i] = first[second[i]];
		}
		return result;
	}

}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private HashEntry<E, V>[] data;
	private int capacity;
	private Set<Entry<E, V>> entrySet;

	static {
		Random random = new Random(System.currentTimeMillis());
		for (int i = 0; i < 10; i++)
			shifts[i] = 1 + 3 * i + random.nextInt(3);
	}

	public EHashMap() {
		this(4);
	}

	private void setCapacity(int size) {
		capacity = Integer.highestOneBit(4 * size);
        //noinspection unchecked
        data = new HashEntry[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			@Override
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry<E, V> last = null;
                    private HashEntry<E, V> current = null;
                    private HashEntry<E, V> base = null;
                    private int lastIndex = -1;
					private int index = -1;

					public boolean hasNext() {
                        if (current == null) {
                            for (index++; index < capacity; index++) {
                                if (data[index] != null) {
                                    base = current = data[index];
                                    break;
                                }
                            }
                        }
                        return current != null;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
                        last = current;
                        lastIndex = index;
                        current = current.next;
                        if (base.next != last)
                            base = base.next;
						return last;
					}

					public void remove() {
						if (last == null)
							throw new IllegalStateException();
                        size--;
                        if (base == last)
                            data[lastIndex] = last.next;
                        else
                            base.next = last.next;
					}
				};
			}

			@Override
			public int size() {
				return size;
			}
		};
	}

	public EHashMap(Map<E, V> map) {
		this(map.size());
		putAll(map);
	}

	public Set<Entry<E, V>> entrySet() {
		return entrySet;
	}

	public void clear() {
		Arrays.fill(data, null);
		size = 0;
	}

	private int index(Object o) {
		return getHash(o.hashCode()) & (capacity - 1);
	}

	private int getHash(int h) {
		int result = h;
		for (int i : shifts)
			result ^= h >>> i;
		return result;
	}

	public V remove(Object o) {
		if (o == null)
			return null;
		int index = index(o);
        HashEntry<E, V> current = data[index];
        HashEntry<E, V> last = null;
        while (current != null) {
            if (current.key.equals(o)) {
                if (last == null)
                    data[index] = current.next;
                else
                    last.next = current.next;
                size--;
                return current.value;
            }
            last = current;
            current = current.next;
        }
        return null;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
        HashEntry<E, V> current = data[index];
        if (current != null) {
            while (true) {
                if (current.key.equals(e)) {
                    V oldValue = current.value;
                    current.value = value;
                    return oldValue;
                }
                if (current.next == null)
                    break;
                current = current.next;
            }
        }
        if (current == null)
            data[index] = new HashEntry<E, V>(e, value);
        else
            current.next = new HashEntry<E, V>(e, value);
        size++;
        if (2 * size > capacity) {
            HashEntry<E, V>[] oldData = data;
            setCapacity(size);
            for (HashEntry<E, V> entry : oldData) {
                while (entry != null) {
                    HashEntry<E, V> next = entry.next;
                    index = index(entry.key);
                    entry.next = data[index];
                    data[index] = entry;
                    entry = next;
                }
            }
        }
		return null;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
        HashEntry<E, V> current = data[index];
		while (current != null) {
			if (current.key.equals(o))
                return current.value;
            current = current.next;
        }
		return null;
	}

	public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return true;
            current = current.next;
        }
        return false;
	}

	public int size() {
		return size;
	}

	private static class HashEntry<E, V> implements Entry<E, V> {
		private final E key;
		private V value;
        private HashEntry<E, V> next;

        private HashEntry(E key, V value) {
            this.key = key;
            this.value = value;
        }


        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }
    }
}


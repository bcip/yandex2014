import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class cube_af {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskCube solver = new TaskCube();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskCube {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        cube = new Cube(in);
        List<String> field = new ArrayList<String>();
        String t;
        while (true) {
            try {
                t = in.nextString();
            } catch (Exception e) {
                break;
            }
            if (t == null) break;
            field.add(t);
        }
        f = new int[field.size()][field.get(0).length()];
        int startX = -1, startY = -1;
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field.get(i).length(); ++j) {
                char c = field.get(i).charAt(j);
                f[i][j] = c - '0';
                if (f[i][j] == cube.sides[5]) {
                    startX = i;
                    startY = j;
                }
            }
        }
        N = field.size();
        M = field.get(0).length();
        Cube temp = new Cube(cube);
        for (int i = 0; i < 4; ++i) {
            cube = new Cube(temp);
            cube.mask = (1 << (cube.sides[5] - 1));
            was = new HashSet<State>();
            if (dfs(startX, startY)) {
                out.println("Yes");
                return;
            }
            temp.rotate();
        }
        temp.mirror();
        for (int i = 0; i < 4; ++i) {
            cube = new Cube(temp);
            cube.mask = (1 << (cube.sides[5] - 1));
            was = new HashSet<State>();
            if (dfs(startX, startY)) {
                out.println("Yes");
                return;
            }
            temp.rotate();
        }
        temp.mirror();
        temp.rotate();
        temp.mirror();
        for (int i = 0; i < 4; ++i) {
            cube = new Cube(temp);
            cube.mask = (1 << (cube.sides[5] - 1));
            was = new HashSet<State>();
            if (dfs(startX, startY)) {
                out.println("Yes");
                return;
            }
            temp.rotate();
        }
        out.println("No");
    }

    int N, M;
    HashSet<State> was;

    class State {
        int x, y;
        Cube c;

        State(int x, int y, Cube c) {
            this.x = x;
            this.y = y;
            this.c = c;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (x != state.x) return false;
            if (y != state.y) return false;
            if (c != null ? !c.equals(state.c) : state.c != null) return false;

            return true;
        }

        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            result = 31 * result + (c != null ? c.hashCode() : 0);
            return result;
        }
    }

    boolean dfs(int x, int y) {
        State cur = new State(x, y, cube);
        if (was.contains(cur)) return false;
        was.add(cur);
        if (cube.mask == MASK) {
            return true;
        }

        // go left
        if (y > 0 && f[x][y-1] == cube.sides[2]) {
            cube.mask |= (1 << (cube.sides[2]-1));
            cube.left();
            if (dfs(x, y-1)) return true;
            cube.right();
        }

        // go right
        if (y < M-1 && f[x][y+1] == cube.sides[3]) {
            cube.mask |= (1 << (cube.sides[3]-1));
            cube.right();
            if (dfs(x, y+1)) return true;
            cube.left();
        }

        // go up
        if (x > 0 && f[x-1][y] == cube.sides[1]) {
            cube.mask |= (1 << (cube.sides[1]-1));
            cube.up();
            if (dfs(x-1, y)) return true;
            cube.down();
        }

        // go down
        if (x < N-1 && f[x+1][y] == cube.sides[0]) {
            cube.mask |= (1 << (cube.sides[0]-1));
            cube.down();
            if (dfs(x+1, y)) return true;
            cube.up();
        }
        return false;
    }

    final int MASK = (1 << 6) - 1;

    Cube cube;
    int[][] f;

    class Cube {
        // 0 - face
        // 1 - back
        // 2 - left
        // 3 - right
        // 4 - top
        // 5 - bottom

        int[] sides;
        int mask = 0;

        void mirror() {
            int t = sides[0];
            sides[0] = sides[1];
            sides[1] = t;
        }

        Cube(InputReader in) {
            sides = new int[6];
            for (int i = 0; i < 6; ++i) {
                sides[i] = in.nextInt();
            }
        }

        Cube(Cube c) {
            sides = c.sides.clone();
        }

        void right() {
            int[] oldSides = sides.clone();
            sides[4] = oldSides[2];
            sides[2] = oldSides[5];
            sides[5] = oldSides[3];
            sides[3] = oldSides[4];
        }

        void left() {
            right(); right(); right();
        }

        void up() {
            int[] oldSides = sides.clone();
            sides[4] = oldSides[0];
            sides[0] = oldSides[5];
            sides[5] = oldSides[1];
            sides[1] = oldSides[4];
        }

        void down() {
            up(); up(); up();
        }

        void rotate() {
            int[] oldSides = sides.clone();
            sides[0] = oldSides[2];
            sides[2] = oldSides[1];
            sides[1] = oldSides[3];
            sides[3] = oldSides[0];
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Cube cube = (Cube) o;

            if (!Arrays.equals(sides, cube.sides)) return false;

            return true;
        }

        public int hashCode() {
            int hash = 0;
            for (int i = 0; i < 6; ++i) {
                hash = hash * 6 + sides[i];
            }
            return hash;
        }
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


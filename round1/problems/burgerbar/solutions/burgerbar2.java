import java.util.*;

class burgerbar2 {
    static int go(boolean[] got, int[] needed, int last, int used) {
        if (used >= 6) {
            return used;
        }
        boolean good = true;
        for (int i = 0; i < needed.length; ++i) {
            if (!got[needed[i]]) {
                good = false;
            }
        }
        if (good) {
            return used;
        }
        int result = 1000;
        for (int i = last + 1; i <= 50; ++i) {
            boolean[] ngot = new boolean[51];
            for (int j = 0; j <= 50; ++j) {
                ngot[j] = got[j];
                if (j >= i) {
                    ngot[j] |= got[j - i];
                }
            }
            result = Math.min(result, go(ngot, needed, i, used + 1));
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] needed = new int[n];
        for (int i = 0; i < n; ++i) {
            needed[i] = scanner.nextInt();
        }
        boolean[] got = new boolean[51];
        for (int i = 1; i <= 50; ++i) {
            got[i] = false;
        }
        got[0] = true;
        System.out.println(go(got, needed, 0, 0));
    }
}

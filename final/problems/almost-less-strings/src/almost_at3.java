import java.util.Arrays;
import java.util.Scanner;


public class almost_at3 {
	
	static int upper_bound(String[] s, String w) {
		int l = 0;
		int r = s.length - 1;
		int ans = s.length;
		
		while (l <= r) {
			int m = (l + r) / 2;
			if (s[m].compareTo(w) > 0) {
				r = m - 1;
				ans = m;
			} else {
				l = m + 1;
			}
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = Integer.parseInt(cin.next());
		String[] s = new String[n];
		for (int i = 0; i < n; ++i) {
			s[i] = cin.next();
		}
		cin.close();
		
		Arrays.sort(s);
		
		long ans = 0;
		
		for (int i = 0; i < n; ++i) {
			String w = s[i];
			for (int j = 0; j < s[i].length(); ++j)
				if (s[i].charAt(j) != 'a') {
					w = s[i].substring(0, j) + 'a' + s[i].substring(j + 1);
					break;
				}
			ans += n - upper_bound(s, w);
			if (s[i].compareTo(w) != 0) --ans;
		}
		
		System.out.println(ans);
	}

}

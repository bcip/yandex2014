import java.util.Scanner;


public class almost_at4 {
	int n, num,i,j,k,cur;
	String[] s;
	int[] a = new int[1000100];
	int[][] b = new int[1000100][27];
	int[][] cnt = new int[1000100][27]; 
	String t; 
	long ans = 0;
	
	int dfs(int i) { 
		for (int j=25; j>=0; j--) { 
			int cur=0; 
		    if (b[i][j]!=0) cur=dfs(b[i][j]); 
		    cnt[i][j]=cnt[i][j+1]+cur; 
		} 
		return cnt[i][0]+a[i]; 
	} 

	void solve() {
		Scanner cin = new Scanner(System.in);
		n = Integer.parseInt(cin.next());
		s = new String[n];
		for (int i = 0; i < n; ++i) {
			s[i] = cin.next();
		}
		cin.close();

		for (int i = 0; i < n; ++i) {
			for (j=k=0; j<s[i].length(); j++) { 
				cur=s[i].charAt(j)-'a'; 
				if (b[k][cur]==0) b[k][cur]=++num; 
				k=b[k][cur]; 
		    } 
		    a[k]++; 
		} 
		dfs(0); 
		for (i=0; i<n; i++) { 
		    boolean can=true; 
		    for (j=k=0; j<s[i].length(); j++) { 
		      if (can && s[i].charAt(j)!='a') { 
		    	  cur=0; can=false;  
		      } else cur=s[i].charAt(j)-'a'; 
		      ans+=cnt[k][cur+1]; 
		      k=b[k][cur]; 
		      if (k==0) break; 
		    } 
		    if (k > 0) ans+=cnt[k][0]; 
		    if (!can) ans--; 
		  } 
		
		System.out.println(ans);
	}
	
	public static void main(String[] args) {		
		new almost_at4().solve();
	}

}

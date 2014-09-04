#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif


using namespace std;

const int MAXN1 = 10;
const int MOD = 1000000007;

int dp[1<<MAXN1];
int g[110];
int ndp[1<<MAXN1];

void madd(int& a, int b) {
	if ((a += b) >= MOD) a -= MOD;
}

void clean(int* a, int mask) {
	a[0] = 0;
	for (int i = mask; i; i = (i-1)&mask)
		a[i] = 0;
}

void copy(int* a, int* b, int mask) {
	a[0] = b[0];
	for (int i = mask; i; i = (i-1)&mask)
		a[i] = b[i];
}


int main(){
	int n1, n2, m;
	while (scanf("%d%d%d",&n1,&n2,&m) == 3) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d",&a,&b);
			--a,--b;
			g[b] |= (1<<a);
		}

		int ans = 0;

		for (int lft = 0; lft < (1<<n1); lft++) {
			clean(dp, lft);
			dp[0] = 1;
			for (int i = 0; i < n2; i++) {
				if (g[i] & ~lft)
					clean(ndp, lft);
				else
				    copy(ndp, dp, lft);

				for (int j = 0; j < n1; j++) {
					if (!(lft & (1<<j))) continue;
					if (!(g[i] & (1<<j))) continue;
					int omask = lft ^ (1<<j);
					madd(ndp[1<<j], dp[0]);
					for (int k = omask; k; k = (k - 1) & omask)
						madd(ndp[k ^ (1<<j)], dp[k]);
				}				
				copy(dp, ndp, lft);
//				eprintf("%d %d %d %d\n", dp[0], dp[1], dp[2], dp[3]);
			}
			
			madd(ans, dp[lft]);
//			eprintf("ans[%d] = %d\n", lft, dp[lft]);
		}
		printf("%d\n", ans);
	}
}
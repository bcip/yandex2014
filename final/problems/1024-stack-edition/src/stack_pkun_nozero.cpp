//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "stack"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
	~__timestamper(){
        TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

double time1, time2;

void push(vector<double>& v) {
	v[1] = min(v[1], v[0] + time1);
	v[1] = min(v[1], v[0] + 1.0 + time2);
	for (int i = 1; i <= 10; i++)
		v[i+1] = min(v[i+1], v[i] + time2 * (1<<i) / 2);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n, _p;
    while (scanf("%d%d",&n,&_p) == 2) {
	    vector<int> v(n);
    	double p = _p / 100.0;
	    for (int i = 0; i < n; i++) {
	    	scanf("%d",&v[i]);
	    	v[i] = __builtin_ctz(v[i]);
		}

		time2 = 1 - p;
		if (_p != 100)
			time2 = min(time2 , p / (1 - p));
		time1 = (1 - p) / p;

		vector<double> dp(12, 1e100);
		dp[v.back()] = 0.0;

		push(dp);

		for (int i = (int)v.size() - 2; i >= 0; i--) {
			vector<double> ndp(12, 1e100);
			ndp[v[i]] = *min_element(dp.begin(), dp.end())+1;
			ndp[v[i]+1] = dp[v[i]];
			push(ndp);
			dp = ndp;			
		}
    	
    	printf("%.12lf\n", dp[10]);
    }

      
  return 0;
}
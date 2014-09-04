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


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n, _p;
    while (scanf("%d%d",&n,&_p) == 2) {
	    vector<int> v(n);
    	double ans = 0;
    	double p = _p / 100.0;
	    for (int i = 0; i < n; i++) {
	    	scanf("%d",&v[i]);
		}

		for (int i = 0; i + 1 < (int)v.size(); i++) {
			if (v[i] < v[i+1] || v[i] == 1024) {
				ans += (int)v.size() - i - 1;
				v.erase(v.begin() + i + 1, v.end());
			} else if (v[i] == v[i+1]){
				ans += (int)v.size() - i - 2;
				v.erase(v.begin() + i + 2, v.end());
			}
		}

		while (true) {
			while (v.size() >= 2 && v[v.size()-1] == v[v.size()-2]) {
				v[v.size()-2] += v[v.size()-1];
				v.pop_back();
			}
			if (v.size() == 1 && v[0] == 1024) break;
			if (!v.empty() && v.back() == 1) {
				ans += (1 - p) / p;
				v.push_back(1);
				continue;
			}
			ans += 1 - p;
			v.push_back(2);
		}
    	
    	printf("%.12lf\n", ans);
    }

      
  return 0;
}
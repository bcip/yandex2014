#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k;
double p;
double scratch[13], dp[2][13];
int mas[100002];
inline void upd() {
	rept(i, 11) dp[0][i] = 1e100;
	dp[0][0] = *min_element(dp[1], dp[1] + 12) + 1.0 / p;
	dp[0][0] = min(dp[0][0], dp[1][0]);
	dp[0][1] = dp[1][1];
	dp[0][1] = min(dp[0][1], *min_element(dp[1], dp[1] + 12) + 1 + scratch[1]);
	dp[0][1] = min(dp[0][1], dp[0][0] + scratch[0]);
	double me = *min_element(dp[1], dp[1] + 12);
	FOR(i, 2, 11) {
		dp[0][i] = min(dp[1][i], dp[0][i - 1] + scratch[i - 1]);
		dp[0][i] = min(dp[0][i], me + 1 + scratch[i]);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%lf", &n, &p);
	p /= 100;
	scratch[0] = 1.0 / p - 1;
	if (p < 1.0) scratch[1] = min(1.0 / (1 - p) - 1, scratch[0] * 2); else
	scratch[1] = scratch[0] * 2;
	if (p < 1.0) {
		scratch[1] = min(scratch[1], p * (1.0 / p - 1));
	}
	FOR(i, 2, 11) {
		scratch[i] = scratch[i - 1] * 2;
	}
	if (!n) {
		printf("%.9lf\n", scratch[10]);
		exit(0);
	}

	rept(i, n) {
		scanf("%d", &a);
		rept(j, 11) {
			if ((1 << j) == a) {
				mas[i] = j;
				break;
			}
		}
	}

	rept(i, 2) rept(j, 12) dp[i][j] = 1e100;
	reverse(mas, mas + n);
	dp[1][mas[0]] = 0.0;
	upd();
	rep(i, n - 1) {
		rept(j, 12) dp[1][j] = 1e100;
		dp[1][mas[i]] = *min_element(dp[0], dp[0] + 12) + 1;
		dp[1][mas[i] + 1] = dp[0][mas[i]];
		upd();
	}
	printf("%.9lf\n", dp[0][10]);
}

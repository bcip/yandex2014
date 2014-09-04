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
int mas[102];
bool dp[2][300002];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rept(i, n) {
		scanf("%d", &mas[i]);
	}
	sort(mas, mas + n, greater<int>());
	int now = 0, nx = 1;
	rept(i, n) {
		swap(now, nx);
		C(dp[nx]);
		dp[nx][mas[i]] = 1;
		rept(j, 300001) {
			if (!dp[now][j]) continue;
			dp[nx][j % mas[i]] = 1;
			if (i != n - 1) dp[nx][j] = 1;
		}
	}
	if (mas[n - 1] == mas[n - 2]) dp[nx][mas[n - 1]] = 0;

	int ans = 0;
	rept(i, 300001) ans += dp[nx][i];
	printf("%d\n", ans);
}

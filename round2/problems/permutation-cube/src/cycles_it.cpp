#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

using namespace std;

vector<pair<int, int> > get_cycles(vector<int> p) {
	vector<int> qnt(p.size() + 1, 0);
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == -1) continue;
		int cur = i, len = 0;
		while (p[cur] >= 0) {
			int nxt = p[cur];
			p[cur] = -1;
			cur = nxt;
			len++;
		}
		qnt[len]++;
	}
	vector<pair<int, int> > result;
	for (int i = 0; i < qnt.size(); i++)
	if (qnt[i] > 0)
		result.push_back(make_pair(i, qnt[i]));
	return result;
}

inline int gcd(int a, int b) {
	for (; b; swap(a, b)) a %= b;
	return a;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> x(n), y(n), z(n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]), x[i]--;
	for (int i = 0; i < n; i++) scanf("%d", &y[i]), y[i]--;
	for (int i = 0; i < n; i++) scanf("%d", &z[i]), z[i]--;
	vector<pair<int, int> > a, b, c;
	a = get_cycles(x);
	b = get_cycles(y);
	c = get_cycles(z);
	ll ans = 0;

	for (int i = 0; i < (int)a.size(); ++i) {
		for (int j = 0; j < (int)b.size(); ++j) {
			ll gg = gcd(a[i].first, b[j].first);
			ll t = (ll)a[i].first * b[j].first / gg;
			gg *= a[i].second * b[j].second;
			for (int k = 0; k < (int)c.size(); ++k) {
				ans += gg * gcd(t % c[k].first, c[k].first) * c[k].second;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
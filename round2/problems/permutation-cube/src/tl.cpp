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
	for (int i = 1; i < qnt.size(); i++)
		result.push_back(make_pair(qnt[i], i));
	return result;
}

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}


int main() {
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
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			for (int k = 0; k < c.size(); k++) {
				ll qnt = (ll)a[i].first * b[j].first * c[k].first;
				ans += qnt * 
					    a[i].second * b[j].second * c[k].second / 
					lcm(a[i].second, lcm(b[j].second, c[k].second));
			}
	cout << ans << endl;

	return 0;
}
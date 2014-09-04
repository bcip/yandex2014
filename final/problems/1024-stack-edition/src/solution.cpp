#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int used[1 << 11], n;
int pp;
double dp[1 << 11], p;

double f(int mask) {
	if (mask == (1 << 10)) return 0.0;
	if (used[mask]) return dp[mask];
	used[mask] = true;
	// dp[mask] = dp[mask + 1] * p + (1 - p) * (dp[mask] + 1)
	// dp[mask] = dp[mask + 1] + (1 - p) / p
	if (mask & 1) return dp[mask] = f(mask + 1) + (1.0 - p) / p;
	else 		  return dp[mask] = p * f(mask + 1) + (1 - p) * f(mask + 2);
}

int main() {
	cin >> n >> pp;
	p = pp / 100.0;
	vector<int> s(n);
	for (int i = 0; i < s.size(); i++) scanf("%d", &s[i]);
	int mask = s[0];
	int add = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] < s[i] || mask == 1024) { // special case
			add = (int)s.size() - i;
			s.resize(i);
			break;
		} else mask += s[i];
	}
	printf("%.13lf\n", f(mask) + add);
}
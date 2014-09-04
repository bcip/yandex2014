#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int check(string s, string d) {
	for (int i = 0; i < s.length(); ++i) if (s[i] != 'a') {
		s[i] = 'a'; break;
	}
	return s < d;
}

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) ans += check(s[i], s[j]) + check(s[j], s[i]);
	
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
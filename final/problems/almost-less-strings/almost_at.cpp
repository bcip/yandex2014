#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

string make(string s) {
	for (int i = 0; i < s.length(); ++i) if (s[i] != 'a') {
		s[i] = 'a'; break;
	}
	return s;
}

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(s.begin(), s.end());
	
	long long ans = 0;
	
	for (int i = 0; i < n; ++i) {
		string w = make(s[i]);
		ans += n - (upper_bound(s.begin(), s.end(), w) - s.begin());
		if (w != s[i]) --ans;
	}
	
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(false);
	solve();
	return 0;
}
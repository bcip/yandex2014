#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int pp;
double p;
map<vector<int>, double> dp;

inline int adjust(vector<int> &s) {
	int sum = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] < s[i] || sum == 1024) {
			int was = s.size();
			s.resize(i);
			return (int)was - i;
		} else sum += s[i];
	}
	while (s.size() >= 2 && s[s.size() - 1] == s[s.size() - 2]) {
		s.pop_back();
		int val = 2 * s.back();
		s.pop_back();
		s.push_back(val);
	}
	return 0;
}

template <class T>
inline ostream& operator << (ostream &o, const vector<T> &v) {
	o << "{";
	for (int i = 0; i < v.size(); i++) {
		if (i) o << ", ";
		o << v[i];
	} 
	o << "}";
	return o;
}

double f(const vector<int> &s, double prob) {
	if (prob < 1e-9) return 0.0;
	if (s.size() == 1 && s[0] == 1024) return 0.0;
	//if (dp.find(s) != dp.end()) return dp[s] * prob;
	vector<int> a = s, b = s;
	a.push_back(1); b.push_back(2);
	int ad_a = adjust(a);
	int ad_b = adjust(b);
	return dp[s] = p * (f(a, prob * p) + ad_a) + (1 - p) * (f(b, prob * (1 - p)) + ad_b);
}

int main() {
	cin >> n >> pp;
	p = pp / 100.0;
	vector<int> s(n);
	for (int i = 0; i < s.size(); i++) scanf("%d", &s[i]);
	int add = adjust(s);
	printf("%.13lf\n", f(s, 1.0) + add);
}
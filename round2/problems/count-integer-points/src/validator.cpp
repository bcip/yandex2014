#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <cassert>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

bool good(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.first * b.second - a.second * b.first) != 0;
}

int main() {
	registerValidation();
	inf.readInt(1, 2000);
	inf.readEoln();
	vector<pii> v;
	for (int i = 0; i < 3; i++) {
		if (i) inf.readSpace();
		int a = inf.readInt(1, 1000);
		inf.readSpace();
		int b = inf.readInt(1, 1000);
		v.push_back(mp(a, b));
	}
	inf.readEoln();
	inf.readEof();
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < i; j++)
			assert(good(v[i], v[j]));

	return 0;
}
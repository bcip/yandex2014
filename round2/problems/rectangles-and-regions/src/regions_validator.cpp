#include "testlib.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	registerValidation();
	int n = inf.readInt(1, 2000); inf.readSpace();
	int m = inf.readInt(1, 2000); inf.readEoln();
	for (int i = 0; i < n; ++i) {
		string s = inf.readString(pattern("[0-1]+"));
		ensure(s.size() == m);
	}
	int k = inf.readInt(1, 500000); inf.readEoln();
	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		x1 = inf.readInt(1, n); inf.readSpace();
		y1 = inf.readInt(1, m); inf.readSpace();
		x2 = inf.readInt(x1, n); inf.readSpace();
		y2 = inf.readInt(y1, m); inf.readEoln();
	}
	inf.readEof();
}
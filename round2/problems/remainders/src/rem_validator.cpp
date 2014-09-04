#include "testlib.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	registerValidation();
	int n = inf.readInt(2, 100); inf.readEoln();
	for (int i = 0; i < n; ++i) {
		inf.readInt(1, 300000);
		if (i < n - 1) inf.readSpace(); else
		inf.readEoln();
	}
	inf.readEof();
}
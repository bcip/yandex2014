#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 0);
	int size = atoi(argv[1]);
	int p = rnd.next(1, 100);
	printf("%d %d\n", size, p);
	vector<int> s;
	for (int i = 0; i < size; i++)
		s.push_back(1 << rnd.next(0, 10));
	for (int i = 0; i < (int)s.size(); i++) {
		if (i) printf(" ");
		printf("%d", s[i]);
	}
	puts("");
}
#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 0);
	assert(argc >= 4);
	int tail = atoi(argv[1]);
	int p = atof(argv[2]);
	assert(strcmp(argv[3], "prefix") == 0);
	vector<int> prefix;
	for (int i = 4; i < argc; i++) prefix.push_back(atoi(argv[i]));
	for (int i = 0; i < prefix.size(); i++) 
		assert(__builtin_popcount(prefix[i]) == 1);
	int size = tail + prefix.size();
	printf("%d %d\n", tail + (int)prefix.size(), p);
	vector<int> s = prefix;
	if (tail) {
		if (s.size() && s.back() != 1024) {
			s.push_back(s.back() * 2);
			tail--;
		}
	}
	assert(s.size() <= 100000);
	for (int i = 0; i < tail; i++)
		s.push_back(1 << rnd.next(0, 10));
	assert(size == s.size());
	for (int i = 0; i < s.size(); i++) {
		if (i) printf(" ");
		printf("%d", s[i]);
	}
	puts("");
}
#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

vector<int> fibonachi(int n) {
	assert(n >= 2);
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	n -= 2;
	while (v[int(v.size()) - 2] + v.back() <= n) {
		int a = v[int(v.size()) - 2];
		int b = v.back();
		v.push_back(a + b);
		n -= a + b;
	}
	if (n > 0) v.push_back(n);

	return v;
}

vector<int> gsmall(int n) {
	vector<int> result;
	int c = rnd.next(1, 3);
	for (int i = 0; i < n / c; i++)
		result.push_back(c);
	if (n % c > 0) result.push_back(n % c);
	return result;
}

vector<int> giant(int n) {
	vector<int> result(1, n);
	return result;
}

vector<int> random(int n) {
	vector<int> v;
	while (n > 0) {
		int c = rnd.next(1, n);
		v.push_back(c);
		n -= c;
	}
	return v;
}

vector<int> gsqrt(int n) {
	vector<int> v;
	for (int i = 1; n > 0; ++i) {
		v.push_back(min(n, i));
		n -= i;
	}
	return v;
}

vector<int> make_permutation(const vector<int> &cycles, int n) {
	vector<int> p(n);
	int start = 0;
	for (int i = 0; i < cycles.size(); i++) {
		for (int j = 0; j < cycles[i]; j++) {
			p[start + j] = start + (j + 1) % cycles[i];
		}
		start += cycles[i];
	}

	vector<int> sh(n);
	for (int i = 0; i < n; ++i) {
		sh[i] = i;
	}
	shuffle(sh.begin(), sh.end());

	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		res[sh[i]] = sh[p[i]];
	}
	return res;
}

inline int sum(const vector<int> &v) {
	int res = 0;
	for (int i = 0; i < v.size(); i++) res += v[i];
	return res;
}

vector<int> generate(string type, int n) {
	vector<int> cycles;
	if (type == "fib") cycles = fibonachi(n);
	else if (type == "small") cycles = gsmall(n);
	else if (type == "giant") cycles = giant(n);
	else if (type == "random") cycles = random(n);
	else if (type == "sqrt") cycles = gsqrt(n);
	else assert(0);
	//cerr << cycles << endl;
	assert(sum(cycles) == n);
	return make_permutation(cycles, n);
}

void output_permutation(const vector<int> &p) {
	for (int i = 0; i < p.size(); i++) {
		if (i) printf(" ");
		printf("%d", p[i] + 1);
	}
	puts("");
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 0);
	int n = atoi(argv[1]);

	string a[3];
	a[0] = argv[2],
		a[1] = argv[3],
		a[2] = argv[4];
	printf("%d\n", n);
	for (int i = 0; i < 3; i++)
		output_permutation(generate(a[i], n));


	return 0;
}
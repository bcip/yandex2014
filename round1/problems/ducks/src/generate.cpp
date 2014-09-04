#include <cstdio>
#include <string>

#include "oi.h"

using namespace std;

oi::Random RG;

int rand_int (int a, int b) { return a + (RG.rand() % (b - a + 1)); }

const int MaxN = 100000;
const int MaxA = 100000000;
const string task = "ducks";

int n, ducks[MaxN];


void print_test(string name) {
	fprintf(stderr, "Printing test nr %s.\n", name.c_str());
	freopen(name.c_str(), "w", stdout);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d", ducks[i]);
		if (i == n - 1)
			printf("\n");
		else
			printf(" ");
	}
}

void przykladowy() {
	n = 5;
	ducks[0] = 42;
	ducks[1] = 1;
	ducks[2] = 3;
	ducks[3] = 3;
	ducks[4] = 6;
	print_test("001");
}

void losowy(int N, int A, string nr, int seed) {
	RG.setSeed(seed);
	n = N;
	for (int i = 0; i < n; ++i)
		ducks[i] = RG.rand() % A + 1;
	print_test(nr);
}


int main() {
	przykladowy();

	losowy(20, 100, "002", 301);
	losowy(100, 6, "003", 302);
	losowy(2, 100000000, "004", 303);
	losowy(10000, 1000000, "005", 304);
	losowy(99999, 10000000, "006", 305);
	losowy(100000, 100000000, "007", 306);
	losowy(100000, 100000000, "008", 307);
	losowy(12345, 99999999, "009", 308);
	losowy(100000, 100000, "010", 309);
	losowy(100000, 100000000, "011", 310);

	return 0;
}

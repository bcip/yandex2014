#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <string>
#include <algorithm>
#include "oi.h"

using namespace std;

oi::Random RG;

int rand_int (int a, int b) { return a + (RG.rand() % (b - a + 1)); }

const int MaxN = 10000;
const int MaxA = 10000;
const string task = "moneysplit";

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

void mniejlosowy(int N, int A, int nowych, string name, int seed) {
	RG.setSeed(seed);
	int dost[20000];
	vector<int> akt;
	fill(dost, dost + 20000, 0);
	dost[0] = 1;
	akt.push_back(0);
	n = N;
	for (int i = 0; i < n; ++i)
		if (i == 0 || RG.rand() % (n - i) < nowych) {
			int dod;
			do {
				dod = RG.rand() % A + 1;
			} while (dost[dod]);
			for (int j = akt.size() - 1; j >= 0; --j) {
				akt.push_back(akt[j] ^ dod);
				dost[akt.back()] = true;
			}
			ducks[i] = dod;
			--nowych;
		} else {
			int cho;
			do {
				cho = rand_int(1, akt.size() - 1);
			} while (akt[cho] >= A);
			ducks[i] = akt[cho];
		}
	print_test(name);
}


int main() {
	przykladowy();

	losowy(20, 100, "002", 501);
	losowy(100, 6, "003", 502);
	losowy(2, 10000, "004", 503);
	losowy(1000, 100, "005", 504);
	losowy(9999, 1000, "006", 505);
	losowy(10000, 10000, "007", 506);
	losowy(10000, 10000, "008", 507);
	losowy(1245, 9999, "008", 508);
	losowy(10000, 1000, "010", 509);
	losowy(10000, 10000, "011", 510);

	mniejlosowy(10000, 10000, 9, "012", 511);
	mniejlosowy(10000, 10000, 11, "013", 512);
	mniejlosowy(10000, 10000, 5, "014", 513);
	mniejlosowy(10000, 10000, 13, "015", 514);
	mniejlosowy(10000, 10000, 4, "016", 515);

	return 0;
}

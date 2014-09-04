#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <string>

#include "oi.h"

using namespace std;

oi::Random RG;

int rand_int (int a, int b) { return a + (RG.rand() % (b - a + 1)); }

const int MaxN = 20;
const int MaxA = 50;
const string task = "burgerbar";

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

int liczba(const vector<int> &sm, int mask) {
	int wyn = 0;
	for (int i = 0; i < sm.size(); ++i)
		if (mask & (1 << i))
			wyn += sm[i];
	return wyn;
}

void mniejlosowy(int N, int gen, int A, string nr, int seed) {
	vector<int> gn;
	for (int i = 0; i < gen; ++i)
		gn.push_back(rand_int(1, min(2 * A / gen, A)));
	n = N;
	for (int i = 0; i < n; ++i) {
		int pom;
		do {
			pom = rand_int(1, (1 << gen) - 1);
		} while (liczba(gn, pom) > A);
		ducks[i] = liczba(gn, pom);
	}
	print_test(nr);
}


int main() {
	przykladowy();

	losowy(6, 15, "002", 1101);
	losowy(8, 24, "003", 1102);
	losowy(11, 50, "004", 1103);
	losowy(16, 50, "005", 1104);
	losowy(20, 50, "006", 1105);

	mniejlosowy(15, 4, 50, "007", 1106);
	mniejlosowy(20, 5, 50, "008", 1107);
	mniejlosowy(20, 10, 50, "009", 1108);
	mniejlosowy(20, 8, 50, "010", 1109);
	mniejlosowy(20, 3, 50, "011", 1110);
	mniejlosowy(20, 5, 50, "012", 1111);
	mniejlosowy(20, 9, 50, "013", 1112);
	mniejlosowy(20, 5, 50, "014", 1113);
	mniejlosowy(20, 4, 50, "015", 1114);
	mniejlosowy(20, 6, 50, "016", 1115);

	losowy(6, 50, "017", 1116);
	losowy(6, 50, "018", 1117);
	losowy(20, 50, "019", 1118);
	losowy(9, 50, "020", 1119);
	losowy(20, 50, "021", 1120);
	losowy(11, 50, "022", 1121);
	losowy(19, 50, "023", 1122);
	losowy(6, 50, "024", 1123);
	losowy(12, 50, "025", 1124);
	losowy(7, 50, "026", 1125);
	
	return 0;
}

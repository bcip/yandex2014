#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#define scanf(Args...) (scanf(Args)?:0)

const int MAXN = 10000;
const int MM = 16 * 1024;
const int MOD = 1e9+7;

int n, a[MAXN + 1];
unsigned ile[2][MM];

void normalizuj(unsigned &x) {
	while (x >= MOD)
		x -= MOD;
}

int main() {
	scanf("%d", &n);
	ile[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int lol = i % 2;
		scanf("%d", &a[i]);
		for (int q = 0; q < MM; ++q)
			normalizuj(ile[lol][q] = ile[1 - lol][q] + 2 * ile[1 - lol][q ^ a[i]]);
	}
	unsigned wynik = ile[n % 2][0];
	printf("%u\n", wynik);
}

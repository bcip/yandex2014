#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#define scanf(Args...) (scanf(Args)?:0)
using namespace std;

const int MAXN = 20;
const int MaxA = 50;
const int Log = 6;

int n, a[MAXN], wynik = Log;
vector<int> track;

void sprawdz() {
	bool plecak[MaxA + 1];
	fill(plecak, plecak + MaxA + 1, false);
	plecak[0] = true;
	for (int i = 0; i < track.size(); ++i)
		for (int q = MaxA - track[i]; q >= 0; --q)
			plecak[q + track[i]] |= plecak[q];
	
	bool dopsz = true;
	for (int i = 0; i < n; ++i)
		if (!plecak[a[i]])
			dopsz = false;
	if (dopsz)
		wynik = min(wynik, int(track.size()));
}

void n_po_k(int N, int K) {
	while (1) {
		if (K == 0)
			sprawdz();
		if (K == 0 || K > N)
			return;
		
		track.push_back(N);
		n_po_k(N - 1, K - 1);
		track.pop_back();
		
		--N;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for (int i = 1; i < Log && wynik == Log; ++i)
		n_po_k(MaxA, i);

	printf("%d\n", wynik);
}

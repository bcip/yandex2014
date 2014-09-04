#include <cstdio>
#include <algorithm>
#define scanf(Args...) (scanf(Args)?:0)
using namespace std;

const int MaxN = 100000;

int wyn[MaxN + 1];
int pitches[MaxN + 1];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", pitches + i);
	sort(pitches + 1, pitches + n + 1);
	wyn[2] = pitches[2] - pitches[1];
	wyn[1] = 1000000000;
	for (int i = 3; i <= n; ++i)
		wyn[i] = min(wyn[i - 2] + pitches[i] - pitches[i - 1], wyn[i - 3] + pitches[i] - pitches[i - 2]);
	printf("%d\n", wyn[n]);
}

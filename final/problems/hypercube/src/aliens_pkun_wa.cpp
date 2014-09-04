#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1100000;

int cnt[MAXN];

bool check(int x) {
	int res = 0;
	if (x >= 30) return true;
	int tmp = (1<<(x-1));
	for (int i = 0; i < MAXN; i++)
		res += (cnt[i] + tmp - 1) / tmp;
	return res == x; 
}

int main(){
	int diff = 0;
	int k;
	scanf("%d",&k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d",&x);
		cnt[x]++;
		diff += cnt[x] == 1;
	}
	while (!check(diff))
		diff++;
	printf("%d\n", diff);
	return 0;
}
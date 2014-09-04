#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100001;

int n, k, c[N];

int main() {
	scanf("%d%d", &n, &k);k--;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]), c[i]++;
	long long ans = 0;
	if (k % 2 == 1) {
		for (int i = 0; i < n; i++) ans += c[i] / (k + 1);
	} else {
		bool has = false;
		for (int i = 0; i < n; i++) 
			if (c[i] % (k + 1) != 0) {
				ans += c[i] / (k + 1);
			} else {
				ans += c[i] / (k + 1) - 1;
			}
		ans += has;
	}
	cout << ans << endl;
	return 0;
}
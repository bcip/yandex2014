#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

const int N = 222;

int used[N][N][N];

int main() {
	int n;
	scanf("%d", &n);
        if (n >= 200) while(true);
	vector<int> x(n), y(n), z(n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]), x[i]--;
	for (int i = 0; i < n; i++) scanf("%d", &y[i]), y[i]--;
	for (int i = 0; i < n; i++) scanf("%d", &z[i]), z[i]--;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (used[i][j][k]) continue;
				ans++;
				for (int u = i, v = j, t = k; 
					!used[u][v][t]; 
					u = x[u], v = y[v], t = z[t]) {
						used[u][v][t] = true;
				}
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				assert(used[i][j][k] == true);
	cout << ans << endl;
}
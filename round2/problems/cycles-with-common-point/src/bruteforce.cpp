#include <stdlib.h>
//#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;
const int V = 501;

int n, k, c[N];

vector<int> G[V];
int used[V], dst[V][V], curv = 1;

inline void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

int main() {
	scanf("%d%d", &n, &k); k--;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) {
		add_edge(0, curv);
		for (int j = 0; j < c[i] - 1; j++) {
			add_edge(curv, curv + 1);
			curv++;
			assert(curv < V);
		}
		add_edge(curv, 0);
		curv++;
		assert(curv < V);
	}

	memset(dst, 63, sizeof(dst));

	for (int i = 0; i < curv; i++) dst[i][i] = 0;

	for (int i = 0; i < curv; i++)
		for (int j = 0; j < G[i].size(); j++)
			dst[i][G[i][j]] = dst[G[i][j]][i] = 1;

	for (int t = 0; t < curv; t++)
		for (int i = 0; i < curv; i++)
			for (int j = 0; j < curv; j++)
				dst[i][j] = min(dst[i][j], dst[i][t] + dst[t][j]);

	int ans = 0;
	for (int s = 0; s < curv; s++) {
		if (dst[0][s] > k) continue;
		vector<int> black;
		black.push_back(s);
		memset(used, 0, sizeof(used));
		for (int i = 0; i < curv; i++)
			if (dst[s][i] <= k) 
				used[i] = true;
		for (int i = 0; i < curv; i++) {
			if (used[i]) continue;
			black.push_back(i);
			for (int j = 0; j < curv; j++)
				if (dst[i][j] <= k) {
					used[j] = true;
				}
		}
		ans = max(ans, (int)black.size());
	}
	cout << ans << endl;


	return 0;
}
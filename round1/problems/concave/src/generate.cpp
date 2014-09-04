#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

#define ID string("")

#include "oi.h"

oi::Random RG;

const int MAX_N = (int) 1e4;
const int MX = (int) 1e8;

int rand_int (int a, int b) { return a + (RG.rand() % (b - a + 1)); }

void gen(int n, int mx, int repeat, bool pack)
{
    static int id = 1;
    ++id;
    char aaaa[10];
    sprintf (aaaa,"%03d",id);
    freopen(aaaa,"w",stdout);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(rand_int(1, mx));
    }
    sort(v.begin(), v.end());
    if (repeat) {
        int z = 0;
        while (n < MAX_N && z < repeat) {
            ++n;
            ++z;
            v.push_back(v.back());
        }
    }
    while (pack && n < MAX_N) {
        long long sum = 0;
        for (int i = max(0, n - 3); i < n; ++i) {
            sum += v[i];
        }
        if (sum <= MX) {
            v.push_back((int) sum);
            ++n;
        } else {
            break;
        }
    }
    RG.randomShuffle(v.begin(), v.end());
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", v[i]);
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaaa);
}

int main() {
    RG.setSeed(0xdeadbeef);
    gen(1, 10000, 0, false);
    gen(2, 10000, 0, false);
    gen(3, 10000, 0, false);
    gen(4, 10000, 0, false);
    for (int i = 500; i <= 10000; i += 500) {
        gen(i, 10000 - i + 500, rand_int(0, 4), true);
    }
    for (int i = 1; i <= 12; ++i) {
        gen(i, MX, i % 4, true);
    }
    gen(1, 10000, 9999, false);
    for (int i = 1; i <= 10; ++i) {
        gen(1, 100, i, true);
    }
}

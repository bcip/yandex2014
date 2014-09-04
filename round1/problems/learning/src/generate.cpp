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

int id = 1;

void gen(int n, int mn, int mx)
{
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", rand_int(mn, mx));
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}

void ge(int a0, int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0) {
    vector<int> v;
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    v.push_back(a0);
    if (a1) v.push_back(a1);
    if (a2) v.push_back(a2);
    if (a3) v.push_back(a3);
    if (a4) v.push_back(a4);
    int n = (int) v.size();
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", v[i]);
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}

int main() {
    RG.setSeed(0xdeadbeef);
    ge(1);
    ge(89);
    ge(1, 1, 1, 1, 1);
    ge(98, 98, 98, 98, 98);
    ge(99, 99, 99, 99, 99);
    ge(100, 100, 100, 100, 100);
    gen(2, 1, 100);
    gen(3, 1, 100);
    gen(4, 1, 100);
    for (int i = 1; i <= 10; ++i) {
        gen(5, 1, 100);
    }
    for (int i = 1; i <= 10; ++i) {
        gen(5, 90, 100);
    }
    for (int i = 1; i <= 10; ++i) {
        gen(5, 95, 99);
    }
}

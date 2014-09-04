#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

#define ID string("")

#include "oi.h"

typedef long long LL;

oi::Random RG;

const int MAX_N = (int) 1e4;
const int MX = (int) 1e8;

int rand_int (int a, int b) { return a + (RG.rand() % (b - a + 1)); }

int id = 1;

LL a;
LL b;

void get_ab(int v) {
    a = 1;
    b = 0;
    for (int i = 0; i < v; ++i) {
        a += b;
        b = a - b;
        if (a > (int) 1e9) {
            break;
        }
    }
}

void gen_special(int n, int k, LL msum)
{
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    printf("%d\n", k);
    printf("%d\n", n);
    vector<int> t(n);
    assert(k >= n);
    get_ab(k - n + 1);
    int cmx = min((msum - b) / a, (LL) MX);
    assert(cmx >= 1);
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            t[i] = rand_int(1, cmx);
        } else if (i % 3 == 1) {
            int l = 1;
            int r = MX;
            while (l < r) {
                int c = (l + r + 1) / 2;
                if (a * t[i - 1] + b * c <= msum && b * t[i - 1] + a * c <= msum) {
                    l = c;
                } else {
                    r = c - 1;
                }
            }
            t[i] = l;
            if (rand_int(0, 1)) {
                swap(t[i - 1], t[i]);
            }
        } else {
            t[i] = rand_int(1, 10);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", t[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}

void gen_special2(int n, int k)
{
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    printf("%d\n", k);
    printf("%d\n", n);
    vector<int> t(n);
    int z = 0;
    int a = 1;
    int b = 1;
    while (MX - b >= a) {
        t[z] = MX - b;
        t[z + 1] = a;
        t[z + 2] = 1;
        if (rand_int(0, 1)) {
            swap(t[z], t[z + 1]);
        }
        z += 3;
        a += b;
        b = a - b;
    }
    while (z < n) {
        t[z] = rand_int(1, 100);
        ++z;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", t[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}

void gen_special3(int n, int k)
{
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    printf("%d\n", k);
    printf("%d\n", n);
    vector<int> t(n);
    int a = 1;
    int b = 0;
    while (MX - b >= a + 1) {
        t[n - 1] = MX - b;
        t[n - 2] = a + 1;
        a += b;
        b = a - b;
    }
    t[0] = MX;
    t[1] = 1;
    for (int i = 2; i < n - 2; ++i) {
        t[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", t[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}


void gen_random(int n, int k)
{
    ++id;
    char aaa[10];
    sprintf (aaa,"%03d",id);
    freopen(aaa,"w",stdout);
    printf("%d\n", k);
    printf("%d\n", n);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        t[i] = rand_int(1, MX);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", t[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    fprintf(stderr, "%s\n", aaa);
}

int main() {
    RG.setSeed(0xdeadbeef);
    gen_special(10000, 1000000, (LL) 1e15);
    for (int k = 10030; k <= 10060; ++k) {
        gen_special2(10000, k);
    }
    gen_special3(5000, 1000000);
    for (int k = 10000; k <= 10050; ++k) {
        gen_special3(10000, k);
    }
    gen_special3(100, 1000000);
    gen_random(10000, 0);
    for (int i = 0; i < 10; ++i) {
        gen_random(10000, rand_int(1, 9999));
    }
    for (int i = 0; i < 10; ++i) {
        gen_random(rand_int(1, 10000), rand_int(1, 1000000));
    }
}

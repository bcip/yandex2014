#include <stdlib.h>
#include <string.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <cstdio>
#include <cmath>

int main()
{
    long long n;
    int k;
    scanf(INT64 "%d", &n, &k);
    printf("%.10f\n", n<k+2 ? 0 : (n-k-1)*pow(2, -(k+2)));
}

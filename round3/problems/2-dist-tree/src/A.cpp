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
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    long long ans=0;
    vector<int> deg(N);
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        deg[a-1]++;
        deg[b-1]++;
    }
    for(int i=0; i<N; i++)
    {
        ans+=1ll*deg[i]*(deg[i]-1)/2;
    }
    printf(INT64 "\n", ans);
}

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
#include <map>
using namespace std;

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    map<int, int> last;
    long long res=0;
    int good=n;
    for(int i=n-1; i>=0; i--)
    {
        int lookfor=a[i]+d;
        map<int, int>::iterator it=last.find(lookfor);
        if(it!=last.end())
        {
            good=min(good, it->second);
        }
        lookfor=a[i]-d;
        it=last.find(lookfor);
        if(it!=last.end())
        {
            good=min(good, it->second);
        }
        last[a[i]]=i;
        res+=n-good;
    }
    printf(INT64 "\n", res);
}

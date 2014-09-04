#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>

bool wins(int n, int l)
{
    if(3*l-2>=n) return true;
    if(!((n-l)&1)) return true;
    int grundy[7001] = {};
    for(int i=l; i<2*l && i<=n; i++)
        grundy[i]=1;
    for(int i=2*l; i<3*l-1 && i<=n; i++)
        grundy[i]=2;
    for(int i=3*l-1; i<=n-l; i++)
    {
        bool has[7001]={};
        for(int j=0; j<=i-l-j; j++)
            has[grundy[j]^grundy[i-l-j]]=1;
        for(int j=0; ; j++)
        {
            if(!has[j])
            {
                grundy[i]=j;
                break;
            }
        }
    }
    for(int i=0; i<=n-l; i++)
    {
        if(grundy[i] == grundy[n-l-i])
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int L=1; L<=n; L++)
    {
        putchar(wins(n, L) ? 'F' : 'S');
    }
    puts("");
}

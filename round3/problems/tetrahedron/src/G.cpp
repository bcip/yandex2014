#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

long long tr(int x1, int y1, int x2, int y2)
{
    return (x2-x1)*(y1+y2);
}

long long aa(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return tr(x1, y1, x2, y2)+tr(x2, y2, x3, y3)+tr(x3, y3, x1, y1);
}

int getinside(int *x, int *y, int px, int py)
{
    long long ar[3];
    for(int i=0; i<3; i++)
    {
        ar[i]=aa(x[i], y[i], x[(i+1)%3], y[(i+1)%3], px, py);
    }
    bool hasp = ar[0]>0 || ar[1]>0 || ar[2]>0;
    bool hasn = ar[0]<0 || ar[1]<0 || ar[2]<0;
    if(hasp && hasn) return -1;
    if(ar[0]>0 && ar[1]>0 && ar[2]>0) return 1;
    if(ar[0]<0 && ar[1]<0 && ar[2]<0) return 1;
    if(ar[0]!=0 && ar[1]!=0 && ar[2]!=0) return -1;
    return 0;
}

int main()
{
    int x[4], y[4], z[4];
    int xs=0, ys=0;
    for(int i=0; i<4; i++)
    {
        scanf("%d%d%d", x+i, y+i, z+i);
        xs+=x[i];
        ys+=y[i];
        x[i]*=4;
        y[i]*=4;
    }
    int res=getinside(x, y, xs, ys);
    if(res==1) puts("Standing");
    if(res==0) puts("Unstable");
    if(res==-1) puts("Falling");
}

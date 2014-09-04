#include "testlib.h"

using namespace std;

int main()
{
    registerValidation();
    
    char map[1024];
    for (int i=0;i<1024;i++) map[i]=0;
    for (int i=0;i<=10;i++) map[(1<<i)-1]=1;
    int N=inf.readInt(0, 100000, "N");
    inf.readSpace();
    int p=inf.readInt(1, 100, "p");
    inf.readEoln();

    for (int i=0;i<N;i++)
    {
        int k=inf.readInt(1,1024,"s_i");
        if (map[k-1]==0) quitf (_fail,"%d is not a power of two!",k);
        if (i<N-1) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}

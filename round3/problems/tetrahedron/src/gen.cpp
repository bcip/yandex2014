#include "testlib.h"
#include <iostream>
#include <cstdio>

using namespace std;

int gen_random (int k)
{
    int x1=rnd.next(0,k);
    int y1=rnd.next(0,k);
    
    int x2=(x1+rnd.next(1,k))%(k+1);
    int y2=(y1+rnd.next(1,k))%(k+1);

    int x3,y3;
    do
    {
    x3=rnd.next(0,k);y3=rnd.next(0,k);
    } while (((x1-x2)*(y3-y2)-(y1-y2)*(x3-x2))==0);

    int x4,y4,z4;
    
    z4=rnd.next (1,k/2); 
    x4=rnd.next (0,k);
    y4=rnd.next (0,k);

    printf ("%d %d 0\n%d %d 0\n%d %d 0\n%d %d %d\n",x1-k/2,y1-k/2,x2-k/2,y2-k/2,x3-k/2,y3-k/2,x4-k/2,y4-k/2,z4);
return (0);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv);
   
    gen_random(2000);    
   
    return 0;
}

#include "testlib.h"

using namespace std;

int map[50000];

int main()
{
    registerValidation();
    
    int N=inf.readInt(1,30000,"N");
    inf.readEoln();
    
    int m;
    for (int i=0;i<N;i++) map[i]=0;
    
    for (int i=0;i<N;i++)
     {
      m=inf.readInt (1,N);
      if (map[m-1]!=0) quitf (_fail,"Double number %d in the first permutation",m);
      map[m-1]=1; 
      if (i<N-1) inf.readSpace();
       else inf.readEoln();
     }

    for (int i=0;i<N;i++)
     {
      m=inf.readInt (1,N);
      if (map[m-1]!=1) quitf (_fail,"Double number %d in the second permutation",m);
      map[m-1]=2; 
      if (i<N-1) inf.readSpace();
       else inf.readEoln();
     }


    for (int i=0;i<N;i++)
     {
      m=inf.readInt (1,N);
      if (map[m-1]!=2) quitf (_fail,"Double number %d in the third permutation",m);
      map[m-1]=3; 
      if (i<N-1) inf.readSpace();
       else inf.readEoln();
     }
     inf.readEof();


    return 0;
}

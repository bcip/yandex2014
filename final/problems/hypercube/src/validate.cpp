#include "testlib.h"
using namespace std;

int main()
{
    registerValidation();
    
    int N=inf.readInt(1,1000000,"N");
    inf.readEoln();

    for (int i=0;i<N;i++)
     {
      char num[10];
      sprintf (num,"i[%d]",i);
      inf.readInt (1,1000000,num);
      if (i<N-1) inf.readSpace();
     }  
    inf.readEoln();
    inf.readEof();
    return 0;
}

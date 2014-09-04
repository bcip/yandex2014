#include "testlib.h"
/**
 * Validates that input contains the only integer between 1 and 100, inclusive.
 * Also validates that file ends with EOLN and EOF.
 */


using namespace std;

int main()
{
    registerValidation();
    
    int N=inf.readInt(1, 100000, "N");
    inf.readSpace();
    int K=inf.readInt(2, 100000, "K");
    inf.readEoln();

    for (int i=0;i<N;i++)
     {
     int k=inf.readInt(K,1000000000,"s_i");
     if (i<N-1) inf.readSpace();
     }

     inf.readEoln();
     inf.readEof();

     return 0;
}

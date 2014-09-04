#include "testlib.h"
/**
 * Validates that input contains the only integer between 1 and 100, inclusive.
 * Also validates that file ends with EOLN and EOF.
 */


using namespace std;

int main()
{
    registerValidation();
    
    int x1=inf.readInt(-1000,1000,"x1");
    inf.readSpace();
    int y1=inf.readInt(-1000,1000,"y1");
    inf.readSpace();
    int z1=inf.readInt(0,0,"z1");
    inf.readEoln();
    int x2=inf.readInt(-1000,1000,"x2");
    inf.readSpace();
    int y2=inf.readInt(-1000,1000,"y2");
    inf.readSpace();
    int z2=inf.readInt(0,0,"z2");
    inf.readEoln();
    int x3=inf.readInt(-1000,1000,"x3");
    inf.readSpace();
    int y3=inf.readInt(-1000,1000,"y3");
    inf.readSpace();
    int z3=inf.readInt(0,0,"z3");
    inf.readEoln();
    int x4=inf.readInt(-1000,1000,"x4");
    inf.readSpace();
    int y4=inf.readInt(-1000,1000,"y4");
    inf.readSpace();
    int z4=inf.readInt(1,1000,"z4");
    inf.readEoln();
    inf.readEof();
    if (((x1-x2)*(y3-y2)-(y1-y2)*(x3-x2))==0)
     quitf (_fail,"Triangle is degenerated!!");
    

    return (0);
}

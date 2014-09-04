#include "testlib.h"
/**
 * Validates that the input contains the only token token.
 * This token can contain only lowercase latin letters a-z. The length should be between 1 and 100, inclusive.
 * Also validates that file ends with EOLN and EOF.
 */


using namespace std;

int main()
{
    registerValidation();
		
	int n = inf.readInt(1, 1000000);
	inf.readEoln();
	
	int totalLen = 0;
	
	for (int i = 0; i < n; ++i) {
		string s = inf.readToken("[a-z]{1,1000000}");
                inf.readEoln();
		totalLen += s.length();
	}
    inf.readEof();

	if (totalLen > 1000000) quitf(_fail, "total length more than 1000000"); 
	
    return 0;
}

#include "testlib.h"

using namespace std;

const int MAXN = 100000;
const int MAXK = 5;
const int MAXC = 1000;

int main(){
	registerValidation();
	int n = inf.readInt(1, MAXN);
	inf.readEoln();
	for (int i = 0; i < n; i++) {
		int k = inf.readInt(1, MAXK);
		int sum = 0;
		for (int j = 0; j <= k; j++){
			inf.readSpace();
			sum += inf.readInt(1, MAXC);			
		}
		ensure(sum);
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
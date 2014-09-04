#include "testlib.h"
#include <cassert>

using namespace std;

int main(int argc, char** argv){
	registerGen(argc, argv, 1);
	int n;
	assert(sscanf(argv[1],"%d",&n) == 1);
	printf("%d\n",n);
	for (int i = 0; i < n; i++){
		int k = rnd.next(1, 5);
		printf("%d", k);
		for (int i = 0; i <= k; i++)
			printf(" %d", rnd.next(1, 1000));
		printf("\n");
	}
}
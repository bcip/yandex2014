#include "testlib.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 0);
	// 0	1	   2   3	 4
	// gen <type> <N> <K> <MAX_C>
	assert (argc >= 5);
	string type(argv[1]);
	int n = atoi(argv[2]);
	int k = atoi(argv[3]);
	int max_c = atoi(argv[4]);
	assert(argc > 4);
	if (type == "random") {
		// complete random
		cout << n << " " << k << endl;
		for (int i = 0; i < n; i++) {
			if (i) cout << " ";
			cout << rnd.next(k, max_c);
		}
		cout << endl;
	} else if (type == "good") {
		assert(argc > 5);
		int num_of_k = atoi(argv[5]);
		cout << n << " " << k << endl;
		vector<int> c;
		for (int i = 0; i < num_of_k; i++) {
			c.push_back(rnd.next(1, max_c / k) * k);
		}
		for (int i = num_of_k; i < n; i++) {
			while (true) {
				int q = rnd.next(k, max_c);
				if (q % k == 0) continue;
				c.push_back(q);
				break;
			}
		}
		shuffle(c.begin(), c.end());
		for (int i = 0; i < c.size(); i++) {
			if (i) printf(" ");
			printf("%d", c[i]);
		}
		puts("");
	}

	return 0;
}
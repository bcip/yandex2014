#include "testlib.h"
#include <algorithm>
#include <iostream>
#include <cassert>

#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

inline pii operator + (const pii &a, const pii &b) {
	return mp(a.x + b.x, a.y + b.y);
}

inline pii operator - (const pii &a, const pii &b) {
	return mp(a.x - b.x, a.y - b.y);
}

inline pii operator * (const pii &a, int x) {
	return mp(a.x * x, a.y * x);
}

inline bool operator == (const pii &a, const pii &b) {
	return (a.x == b.x) && (a.y == b.y);
}

pair<int, int> rnd_vec(int vec) {
	return pair<int, int>(rnd.next(1, vec), rnd.next(1, vec));
}

bool col(pair<int, int> a, pair<int, int> b) {
	return a.first * b.second == b.first * a.second;
}

void generate(pii &a, pii &b, pii &c, string type, int vec) {
	if (type == "random") {
		a = rnd_vec(vec);
		b = rnd_vec(vec);
		c = rnd_vec(vec);		
	} else if (type == "sum") {
                assert(vec <= 500);
		a = rnd_vec(vec);
		b = rnd_vec(vec);
		c = a + b;
	} else if (type == "big_sides") {
		a = rnd_vec(vec / 30);
		b = rnd_vec(vec / 30);
		c = a + b;
		a = a * 30;
		b = b * 30;
	} else if (type == "big_sum") {
		a = rnd_vec(vec / 30);
		b = rnd_vec(vec / 30);
		c = a + b;
		c = c * 10;
	}

	if (rnd.next(0, 1)) swap(a, b);
	if (rnd.next(0, 1)) swap(b, c);
	if (rnd.next(0, 1)) swap(a, c);
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 0);
	string type(argv[1]);
	int N = atoi(argv[2]);
	int vec = 1000;
	if (argc >= 4) vec = atoi(argv[3]);

	pair<int, int> a, b, c;
	do {
		generate(a, b, c, type, vec);
		if (!(col(a, b) || col(b, c) || col(a, c))) {
			break;
		}
	} while (true);
	cout << N << endl;
	cout << a.first << " " << a.second << " " <<
			b.first << " " << b.second << " " <<
			c.first << " " << c.second << endl;
}
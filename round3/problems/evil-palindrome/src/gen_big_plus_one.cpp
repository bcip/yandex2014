#include "testlib.h"
#include <iostream>
#include <string>


using namespace std;

void gen(string* s) {
  *s = "";
  int len = rnd.next(50000, 100000);
  (*s).push_back((char) (rnd.next(1, 9) + '0'));
  for (int i = 1; i < len; ++i) {
    (*s).push_back((char) (rnd.next(0, 9) + '0'));
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  string s = "";
  gen(&s);
  cout << s << ' ' << 1 << endl;
  return 0;
}

#include "testlib.h"
#include <iostream>
#include <string>


using namespace std;

void gen(string* s) {
  *s = "";
  if (rnd.next(0, 10) < 2) {
    (*s).push_back('-');
  }
  int len = rnd.next(25000, 50000);
  (*s).push_back((char) (rnd.next(1, 9) + '0'));
  for (int i = 1; i < len; ++i) {
    (*s).push_back((char) (rnd.next(0, 9) + '0'));
  }
  int cnt = (*s).length()-1;
  for (int i = cnt; i >= 0; --i) {
    (*s).push_back((*s)[i]);
  }
  if ((*s)[(*s).length()-1] == '-') {
    (*s) = (*s).substr(0, (*s).length()-1);
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  string s = "";
  gen(&s);
  int step = rnd.next(-1000000000, 1000000000);
  if (step == 0) ++step;
  cout << s << ' ' << step << endl;
  return 0;
}

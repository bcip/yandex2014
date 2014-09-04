#include "testlib.h"
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

const int MAXN = 100000;
const int MAX_STEP = 1000000000;

int main() {
  registerValidation();
  string n = inf.readWord();
  if (n[0] == '-') {
    ensure(n.length() >= 2 && n.length() <= MAXN + 1);
  } else {
    ensure(n.length() >= 1 && n.length() <= MAXN);
  }
  int start = 0;
  if (n[0] == '-') start = 1;
  for (int i = start; i < n.length(); ++i) {
    ensure(n[i] >= '0' && n[i] <= '9');
  }
  if (n[start] == '0') {
    ensure(n == "0");
  }
  inf.readSpace();

  int step = inf.readInt(-MAX_STEP, MAX_STEP);
  ensure(step != 0);
  inf.readEoln();
  inf.readEof();
  return 0;
}


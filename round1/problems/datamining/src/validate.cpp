#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "oi.h"
using namespace std;

const int MAXK = (int) 1e6;
const int MAXN = (int) 1e4;
const int MX = (int) 1e8;

int main() {
  oi::Scanner in(stdin, oi::EN);
  in.readInt(0, MAXK);
  in.readEoln();
  int n = in.readInt(2, MAXN);
  in.readEoln();
  for (int i = 0; i < n; ++i) {
      in.readInt(1, MX);
      if (i < n - 1) {
          in.readSpace();
      }
  }
  in.readEoln();
  in.readEof();
  printf("OK  n = %5d\n", n);
  return 0;
}

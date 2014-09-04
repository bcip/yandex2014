#include "oi.h"
using namespace std;

const int MAXN = (int) 5;
const int MX = (int) 100;

int main() {
  oi::Scanner in(stdin, oi::EN);
  int n = in.readInt(1, MAXN);
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

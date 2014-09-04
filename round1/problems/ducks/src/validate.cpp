#include "oi.h"

#include <stdio.h>

#include <set>
#include <utility>

using namespace std;

const int MaxN = 100000;
const int MaxA = 100000000;

int main() {
  oi::Scanner in(stdin, oi::EN);
  
  int n = in.readInt(2, MaxN);
  in.readEoln();

  for (int i = 0; i < n; ++i) {
	  in.readInt(1, MaxA);
	  if (i == n - 1)
		  in.readEoln();
	  else
		  in.readSpace();
  }
  in.readEof();

  printf("OK  n = %d\n", n);
  return 0;
}

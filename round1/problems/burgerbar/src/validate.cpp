#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "oi.h"

#include <stdio.h>

#include <set>
#include <utility>

using namespace std;

const int MaxN = 20;
const int MaxA = 50;

int main() {
  oi::Scanner in(stdin, oi::EN);
  
  int n = in.readInt(1, MaxN);
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

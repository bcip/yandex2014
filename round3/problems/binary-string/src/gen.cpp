#include "testlib.h"
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <iostream>


using namespace std;

const long long MAXN = 1000000000000000000L;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  long long n = rnd.next(MAXN) + 1;
  int k = rnd.next(1, 100);
  printf(INT64 " %d\n", n, k);
  return 0;
}

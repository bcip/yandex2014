#include <stdlib.h>
#include <string.h>
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
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int i,j,k,n;
long long r;
char st[1000100];
string s[1000100],t;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s[i]=st;
  }
  sort(s,s+n);
  for (i=0; i<n; i++) {
    t=s[i];
    for (j=0; j<t.length(); j++) if (t[j]!='a') {
      t[j]='a';
      break;
    }
    k=upper_bound(s,s+n,t)-s;
    r+=n-k-int(k<=i);
  }
  printf(INT64 "\n",r);
  return 0;
}

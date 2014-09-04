#include <stdlib.h>
#include <string.h>
#include <algorithm>
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
using namespace std;
int n,num,i,j,k,cur,a[1000100],b[1000100][27],cnt[1000100][27];
string s[1000100],t;
char st[1000100];
long long r;
int dfs(int i) {
  for (int j=25; j>=0; j--) {
    int cur=0;
    if (b[i][j]!=0) cur=dfs(b[i][j]);
    cnt[i][j]=cnt[i][j+1]+cur;
  }
  return cnt[i][0]+a[i];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s[i]=st;
    for (j=k=0; j<s[i].length(); j++) {
      cur=s[i][j]-'a';
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
    a[k]++;
  }
  dfs(0);
  for (i=0; i<n; i++) {
    bool can=true;
    for (j=k=0; j<s[i].length(); j++) {
      if (can && s[i][j]!='a') {
        cur=0; can=false; 
      } else cur=s[i][j]-'a';
      r+=cnt[k][cur+1];
      k=b[k][cur];
      if (k==0) break;
    }
    if (k) r+=cnt[k][0];
    if (!can) r--;
  }
  printf(INT64 "\n",r);
  return 0;
}

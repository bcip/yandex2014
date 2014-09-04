#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

const int mod = inf+7;

int mul (int a, int b)
{
  return (a*1ll*b)%mod;
}

inline void add (int& a, int b)
{
  a+=b;
  if (a>=mod)
    a-=mod;
}

int deg (int v, int d)
{
  int ret=1;
  while (d)
  {
    if (d&1)
      ret=mul(ret,v);
    d>>=1, v=mul(v,v);
  }
  return ret;
}

int inv (int v)
{
  assert(v);
  return deg(v,mod-2);
}

vi operator + (const vi& a, const vi& b)
{
  assert(a.size()==b.size());
  vi res=vi(a.size(),0);
  for (int i=0; i<(int)a.size(); i++)
    add(res[i],a[i]), add(res[i],b[i]);
  return res;
}

const int maxp=2;
int C[maxp+10][maxp+10];

vi operator * (const vi& a, const vi& b)
{
  assert(a.size()==b.size());
  vi ret=vi(a.size(),0);
  for (int i=0; i<(int)a.size(); i++)
    for (int j=0; i+j<(int)a.size(); j++)
      add(ret[i+j],mul(C[i+j][i],mul(a[i],b[j])));
  return ret;
}

vi operator * (int c, const vi& a)
{
  vi ret=vi(a.size(),0);
  for (int i=0; i<(int)a.size(); i++)
    ret[i]=mul(c,a[i]);
  return ret;
}
 
int A[123123][8];
int K[123123];

int main()
{
  int n, sum=0, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<maxp+10; i++)
    for (C[i][0]=1, j=1; j<maxp+10; j++)
      add(C[i][j],C[i-1][j-1]), add(C[i][j],C[i-1][j]);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    for (scanf("%d", &K[i]), sum=0, j=0; j<=K[i]; j++)
      scanf("%d", &A[i][j]), sum+=A[i][j];  
    sum=inv(sum);
    for (j=0; j<=K[i]; j++)
      A[i][j]=mul(A[i][j],sum);
  }
  vi func=vi(maxp+1,1);
  for (i=n-1; i>=0; i--)
  {
    vi bf=func;
    vi d=vi(maxp+1,0);
    d[0]=1;
    func=vi(maxp+1,0);
    for (j=0; j<=K[i]; j++, d=d*bf)
      func=func+(A[i][j]*d);
  }
  int res=(mod+func[2]-func[1])%mod;
  printf("%d\n", mul(res,inv(2)));
  TIMESTAMP(end);
  return 0;
}

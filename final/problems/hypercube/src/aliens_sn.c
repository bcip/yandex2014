#include <stdio.h>

#define MAXN 1000001
#define LOG 21

main()
{
int i,N,a,cur_max;
int map[MAXN];
int nz[MAXN];
int n_nz=0;
int ans=0,edges;

for (i=0;i<MAXN;i++) map[i]=0;

scanf ("%d",&N);

for (i=0;i<N;i++) 
 {
  scanf ("%d",&a);

  if (map[a]==0) {ans++;nz[n_nz++]=a;}

  map[a]++;
 }

if (ans<LOG)
{
do
{
cur_max=1<<(ans-1);
edges=0;
for (i=0;i<n_nz;i++)
 {
 edges+=(map[nz[i]]-1)/cur_max+1;
 if (edges>ans) {ans++;break;}
 }
} while (i!=n_nz);
}

printf ("%d\n",ans);

return (0);
}
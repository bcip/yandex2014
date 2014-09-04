#include "testlib.h"
#include <cstdio>

// Usage: generate [s length start] [i length start] [r length start] x (any text)


using namespace std;

int main(int argc, char **argv)
{

registerGen(argc, argv, 1);

int N=0,j=1,len,a;

int data[1000000];

while (j<argc)
{
if (argv[j][0]=='s')  // sequential: s length start
 {
  j++;
  sscanf (argv[j++],"%d",&len);
  sscanf (argv[j++],"%d",&a);

  for (int i=N; i<N+len;i++) 
    data[i]=a++;
 N+=len;
 }

else if (argv[j][0]=='i') // identical: i length value
 {
   j++;
   sscanf (argv[j++],"%d",&len);
   sscanf (argv[j++],"%d",&a);
   for (int i=N; i<N+len;i++) 
    data[i]=a;
   N+=len;
 }

else if (argv[j][0]=='r') // random: r length min max
 {
   int min,max;
   j++;
   sscanf (argv[j++],"%d",&len);
   sscanf (argv[j++],"%d",&min);
   sscanf (argv[j++],"%d",&max);
   for (int i=N; i<N+len;i++) 
    data[i]=rnd.next(min,max);
   N+=len;
 }

else break;
}

shuffle (data,data+N-1);

printf ("%d\n",N);
for (int i=0;i<N;i++)
 {
  printf ("%d",data[i]);
  if (i<N-1) printf (" ");
 }
printf ("\n");
return (0);
}
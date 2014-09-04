#include "testlib.h"
#include <cstdio>

using namespace std;

int hexaminos[35][14] = {
{5,2,2,4,3,0,0,0,0,6,5,7,-1,-1},
{4,3,2,4,0,0,0,6,3,7,0,0,5,0},
{4,3,2,6,0,0,0,4,3,0,0,0,7,5},
{4,3,6,0,0,0,2,4,3,5,7,0,0,0},
{4,3,6,0,0,0,2,4,3,5,0,7,0,0},
{4,3,6,0,0,0,2,4,3,5,0,0,7,0},
{4,3,6,0,0,0,2,4,3,5,0,0,0,7},
{4,3,0,6,0,0,2,4,3,5,0,7,0,0},
{4,3,0,6,0,0,2,4,3,5,0,0,7,0},
{4,3,6,2,0,0,0,4,7,5,0,0,0,3},
{4,3,6,2,0,0,0,4,7,5,0,3,0,0},
{6,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1},
{5,2,1,1,1,1,1,1,0,0,0,0,-1,-1},
{5,2,1,1,1,1,1,0,1,0,0,0,-1,-1},
{5,2,1,1,1,1,1,0,0,1,0,0,-1,-1},
{5,2,1,1,1,1,0,0,0,0,1,1,-1,-1},
{4,3,1,1,1,1,1,0,0,0,1,0,0,0},
{4,3,1,1,1,1,0,1,0,0,0,1,0,0},
{4,3,1,1,1,0,0,0,1,1,0,0,0,1},
{4,3,1,1,1,0,0,0,1,1,0,0,1,0},
{4,3,1,1,1,0,0,0,1,0,0,0,1,1},
{4,2,1,1,1,1,1,1,0,0,-1,-1,-1,-1},
{4,2,1,1,1,1,1,0,1,0,-1,-1,-1,-1},
{4,2,1,1,1,1,1,0,0,1,-1,-1,-1,-1},
{4,2,1,1,1,1,0,1,1,0,-1,-1,-1,-1},
{4,2,1,1,1,0,1,0,1,1,-1,-1,-1,-1},
{4,2,1,1,1,0,0,1,1,1,-1,-1,-1,-1},
{3,3,1,1,1,1,1,0,1,0,0,-1,-1,-1},
{3,3,1,1,1,1,1,0,0,1,0,-1,-1,-1},
{3,3,1,1,1,1,0,1,1,0,0,-1,-1,-1},
{3,3,1,1,1,0,1,0,1,1,0,-1,-1,-1},
{3,3,1,1,0,1,1,1,0,1,0,-1,-1,-1},
{3,3,1,1,0,1,1,1,0,0,1,-1,-1,-1},
{3,3,1,1,0,0,1,1,1,1,0,-1,-1,-1},
{3,2,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1}
};

void print_test (int *cube, int *figure)
{
for (int i=0;i<6;i++)
 {
  printf ("%d",cube[i]);
  if (i<5) printf(" ");
 }
printf ("\n");
int rotate=rnd.next(0,7);

int h1=0,h2=1,w1=0,w2=1,h,w;

if (rotate&1)
  {w1=figure[0]-1;w2=-1;}

if (rotate&2)
  {h1=figure[1]-1;h2=-1;}

h=figure[1];w=figure[0];

if (rotate&4)
for (int j=0;j<w;j++) 
 {
  for (int i=0;i<h;i++)
   printf ("%d",figure[2+(h1+h2*i)*w+(w1+w2*j)]);
   printf ("\n");
  }
else
for (int i=0;i<h;i++) 
 {
  for (int j=0;j<w;j++)
   printf ("%d",figure[2+(h1+h2*i)*w+(w1+w2*j)]);
   printf ("\n");
  }

return;
}

void generate_test (int id, int is_OK)
{
int current=0;

int cube[6];
int figure[14];


for (int i=0;i<6;i++) cube[i]=i+1;
shuffle (cube,cube+5);

for (int i=0;i<14;i++) 
 {
  int k=hexaminos[id][i];
  
  if ( (i<2) || (k<=0) ) 
   figure[i]=k;
  else 
   if (k==1) 
    figure[i]=cube[current++];
   else figure[i]=cube[k-2]; // generate OK answer
 }

if (id<11) // good figure --- already generated as OK
 {
  if (is_OK==2)  // small swap to catch the trick
   {current=cube[1];cube[1]=cube[0];cube[0]=current;}

  if (is_OK<0)  // if not needed --- break the cube
   {current=cube[1];cube[1]=cube[2];cube[2]=current;}

  if (is_OK==0) // if not defined --- shuffle the cube again
   shuffle (cube,cube+5);
 }
print_test (cube,figure);
}




int main(int argc, char **argv)
{
int is_ok,id;
registerGen(argc, argv, 1);

if (argv[1][0]=='r') 
 generate_test (rnd.next(0,34),0);

if (argv[1][0]=='f')
 {
  sscanf (argv[2],"%d",&id);
  sscanf (argv[3],"%d",&is_ok);
  generate_test (id,is_ok);
 }

if (argv[1][0]=='g')
 {
  generate_test (rnd.next(0,10),1);
 }

if (argv[1][0]=='b')
 {
  generate_test (rnd.next(0,10),-1);
 }

return (0);
}

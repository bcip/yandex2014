#include <stdio.h>
#include <string.h>

#define N_RAZV 11

int razv[11][12]= 
{
{1,2,1,0,0,0,0,3,2,3,-1,-1},
{2,3,0,0,0,1,2,1,0,0,3,0},
{2,1,0,0,0,3,2,0,0,0,1,3},
{1,0,0,0,2,3,2,3,1,0,0,0},
{1,0,0,0,2,3,2,3,0,1,0,0},
{1,0,0,0,2,3,2,3,0,0,1,0},
{1,0,0,0,2,3,2,3,0,0,0,1},
{0,1,0,0,2,3,2,3,0,1,0,0},
{0,1,0,0,2,3,2,3,0,0,1,0},
{1,2,0,0,0,3,1,3,0,0,0,2},
{1,2,0,0,0,3,1,3,0,2,0,0}
};

int cmp_int (int *a, int *b)
{
 return ((*a)-(*b));
}

int read_data (int *cube,int *figure,int *h, int *w)
{
int i,a,x=0,y=0,j=0;
char s[20];
for (i=0;i<3;i++)
 {
  scanf ("%d",&a);
  cube[i]=a*a;
  scanf ("%d",&a);
  cube[i]+=a*a;
 }

qsort (cube,3,sizeof(int),cmp_int);
 
while (1)
{
if (scanf ("%s",s)<1) break;
if (x==0) x=strlen(s);

if (strlen(s)!=x) break;

for (i=0;i<strlen(s);i++) figure[j++]=s[i]-'0';
y++;
}
*h=y;*w=x;
return (1);
}

int check (int h, int w, int *figure, int *cube)
{
int i,j,ii,jj,k,val;
int res[12],l[4];

for (k=0;k<N_RAZV;k++)
{
for (i=0;i<4;i++) 
 {
  l[i]=0;
  for (j=0;j<3;j++)
   res[3*i+j]=0;
 }

for (i=0;i<h;i++)
 for (j=0;j<w;j++)
  {
   if (h>w) val=h*j+i;
    else val=w*i+j;
   if (razv[k][val])
      {
       if (figure[w*i+j]) {res[razv[k][val]-1]+=figure[w*i+j]*figure[w*i+j];l[0]++;}
       if (figure[w*i+(w-1-j)]) {res[3+razv[k][val]-1]+=figure[w*i+(w-1-j)]*figure[w*i+(w-1-j)];l[1]++;}
       if (figure[w*(h-1-i)+j]) {res[6+razv[k][val]-1]+=figure[w*(h-1-i)+j]*figure[w*(h-1-i)+j];l[2]++;}
       if (figure[w*(h-1-i)+(w-1-j)]) {res[9+razv[k][val]-1]+=figure[w*(h-1-i)+(w-1-j)]*figure[w*(h-1-i)+(w-1-j)];l[3]++;}
      } 
   }
for (i=0;i<4;i++)
{
//fprintf (stderr,"l[%d] at k=%d = %d\n",i,k,l[i]);
  if (l[i]==6) // found
   {

//    fprintf (stderr,"Found %d %d !\n",k,i);

    qsort (res+3*i,3,sizeof(int),cmp_int);
/*

    for (ii=0;ii<12;ii++) fprintf (stderr,"%d ",res[ii]);
    fprintf (stderr,"\n");
    for (ii=0;ii<3;ii++) fprintf (stderr,"%d ",cube[ii]);
    fprintf (stderr,"\n\n");
*/
     for (j=0;j<3;j++)
      if (res[3*i+j]!=cube[j]) return (0);
    return (1);
   }
}
}
return (0);
}

main()
{
int cube[3];
int figure[12];
int x,y;

read_data (cube,figure,&x,&y);

if (check (x,y,figure,cube)) printf ("Yes\n");
 else printf ("No\n");
 
return (0);
}

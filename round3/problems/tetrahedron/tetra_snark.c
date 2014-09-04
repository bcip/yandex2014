#include <stdio.h>
#include <stdlib.h>

int square (int x1,int y1, int x2, int y2, int x3, int y3)
{
//fprintf (stderr,"%d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
return (abs ((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)));
}


main()
{
int x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,xr,yr;
int s1,s2,s3,s4;

scanf ("%d %d %d %d %d %d %d %d %d %d %d %d\n",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4);
if (z1 || z2 || z3) return (1);

xr=(x1+x2+x3+x4);
yr=(y1+y2+y3+y4);

if ((s1=square (4*x1,4*y1,4*x2,4*y2,xr,yr))==0) {printf ("Unstable\n");return(0);}
if ((s2=square (4*x2,4*y2,4*x3,4*y3,xr,yr))==0) {printf ("Unstable\n");return(0);}
if ((s3=square (4*x1,4*y1,4*x3,4*y3,xr,yr))==0) {printf ("Unstable\n");return(0);}

//fprintf (stderr,"%d %d %d\n",s1,s2,s3);

if (s1+s2+s3==square(4*x1,4*y1,4*x2,4*y2,4*x3,4*y3)) printf ("Standing\n");
else printf ("Falling\n");

return (0);
}
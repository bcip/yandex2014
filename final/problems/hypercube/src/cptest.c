/*
Copy a test (with line feeds and cr/lf breaking buffer fixed)
*/
#include <stdio.h>
#include <string.h>

#define SIZE 10

unsigned char buf[SIZE];

main()
{
int i,flag;
while (fgets (buf,SIZE,stdin)!=NULL)
{

if (buf[strlen(buf)-1]==13) // cr and no lf --- eliminate CR
{
for (i=strlen(buf)-1;i>=0;i--) {if (buf[i]<=32) buf[i]=0; else break;}
printf ("%s",buf);flag=1;continue;
} //
else
if (buf[strlen(buf)-1]!=10) {printf ("%s",buf);flag=1;continue;}

// Line is closed correctly

flag=0;

for (i=strlen(buf)-1;i>=0;i--) {if (buf[i]<=32) buf[i]=0; else break;}
printf ("%s\n",buf);
}
if (flag) printf ("\n");
return (0);
}
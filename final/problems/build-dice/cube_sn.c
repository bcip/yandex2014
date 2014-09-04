#include <stdio.h>
#include <string.h>

int move[4][8]={
{4,5,2,3,1,0,0,1},
{5,4,2,3,0,1,0,-1},
{0,1,5,4,2,3,1,0},
{0,1,4,5,3,2,-1,0},
};

int rot[6]={2,3,1,0,4,5};

int field[8][8];
int cube[6];
int cubex,cubey;

int read_data ()
{
int i,a,x=0,y=0,j;
char s[20];

for (i=0;i<6;i++)
  scanf ("%d",cube+i);
  
for (i=0;i<8;i++)
 for (j=0;j<8;j++)
   field[i][j]=0;

j=0;
while (1)
{
if (scanf ("%s",s)<1) break;
if (x==0) x=strlen(s);

if (strlen(s)!=x) break;

for (i=0;i<strlen(s);i++) 
 {
  field[i+1][y+1]=(s[i]-'0');
  if (field[i+1][y+1]==cube[5]) {cubex=i+1;cubey=y+1;}
 }
y++;
}
return (1);
}

int n_ok;

int check_move(int curx,int cury,int *cube_local,int label)
{
int i,j,k,l;
int temp[6];
  field[curx][cury]+=label;
  for (j=0;j<4;j++)
   {
    if ( (k=field[curx+move[j][6]][cury+move[j][7]]) < label )
     if (k>0)
     {
      for (i=0;i<6;i++)
       temp[i]=cube_local[move[j][i]];
        
       if (temp[5]==k%10) 
        {
         n_ok++;
         check_move (curx+move[j][6],cury+move[j][7],temp,label);
        }
      }
    }
return(0);
}

main()
{
int i,j,k,temp[6];

read_data ();

for (k=0;k<2;k++)
{
if (k>0) {i=cube[0];cube[0]=cube[1];cube[1]=i;}
for (i=0;i<4;i++)
 {
  n_ok=0;
  check_move (cubex,cubey,cube,(1<<(4*k+i))*10);

  if (n_ok==5) {printf ("Yes\n");return(0);}

  for (j=0;j<6;j++)
   temp[j]=cube[rot[j]];
  for (j=0;j<6;j++)
   cube[j]=temp[j];
 }  
}  

printf ("No\n");
return (0);
}

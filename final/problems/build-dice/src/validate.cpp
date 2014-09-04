#include "testlib.h"
using namespace std;

int x=0,y=0;

int res_link;

void check_link (string a[6],int x1, int y1)
{
if (x1>0) if ((a[y1])[x1-1]>'0') {(a[y1])[x1-1]='!';res_link++;check_link (a,x1-1,y1);}
if (y1>0) if ((a[y1-1])[x1]>'0') {(a[y1-1])[x1]='!';res_link++;check_link (a,x1,y1-1);}
if (x1<(x-1)) if ((a[y1])[x1+1]>'0') {(a[y1])[x1+1]='!';res_link++;check_link (a,x1+1,y1);}
if (y1<(y-1)) if ((a[y1+1])[x1]>'0') {(a[y1+1])[x1]='!';res_link++;check_link (a,x1,y1+1);}
return;
}



int main()
{
    registerValidation();
    
    string a[6];
    int n_used=0;
    int v[6], r[6];
    
    
    for (int i=0;i<6;i++) 
     {
     r[i]=v[i]=0;
     inf.readInt(1,6);
     if (i<5) inf.readSpace();
     }
    
    inf.readEoln();
    
    while (!inf.eof())
    {
    a[y]=inf.readToken("[0-6]{1,6}");
    if (x==0) x=a[y].length();
     else if (x!=a[y].length()) quitf (_fail,"Not a rectangle!");
    inf.readEoln();
    int l=0;
    for (int i=0;i<x;i++) 
     if ((a[y])[i]!='0') 
      { l++;v[i]++;
        if (r[(a[y])[i]-'1']) 
          quitf (_fail,"Duplicate %c!",(a[y])[i]);
        else r[(a[y])[i]-'1']++;
      }
    if (l==0) quitf (_fail,"Empty row!");
    n_used+=l;
    y++;
    }
    if (n_used!=6) quitf (_fail,"%d elements used instead of 6!",n_used);  
    
    for (int i=0;i<x;i++)
     if (v[i]==0) quitf (_fail,"Empty column!");

    for (int i=0;i<x;i++)
      if ((a[0])[i]!='0') 
       {
        (a[0])[i]='!'; res_link=1;
        check_link (a,i,0);
        break;
       }
     
    if (res_link!=6) 
     {
/*
      for (int i=0;i<y;i++)
       {
        for (int j=0;j<x;j++)
         fprintf (stderr,"%c",a[i][j]);  
         fprintf (stderr,"\n");
        }
*/      
      quitf (_fail,"Not linked! %d",res_link);
     }
    inf.readEof();
    return 0;
}

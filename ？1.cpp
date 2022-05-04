#include<stdio.h>
int main()
{
   int x=10,y=9,a,b,c;
   a=(--x==y++)?--x:++y;
   b=x++;
   c=y;
   printf("%d %d %d %d %d",x,y,a,b,c);
}

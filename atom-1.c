#include<stdio.h>
void f(int n)
{
  if(n>=10) f(n/10);
  printf("%d\n",n);
}
int main()
{
  f(12345);
}

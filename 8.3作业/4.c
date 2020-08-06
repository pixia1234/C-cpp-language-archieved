#include <stdio.h>
int put(int*,int);
int put2(int*,int);
int main()
{
  int n[10],m[10],i;
  for(i=0;i<10;i++)
  {
    scanf("%d",&n[i]);
    m[i]=n[i];
  }
  int num=10,ans=0;
  while(num>=1)
  {
    ans+=put(n,num);
    num--;
  }
  printf("%d\n",ans );
  num=10,ans=0;
  while(num>=1)
  {
    ans+=put2(m,num);
    num--;
  }
  printf("%d\n",ans );
  return 0;
}
int put(int *n,int num)
{
  int *p,*q;
  q=n;
  for(p=n;p<n+num-1;p++) if(*p+*(p+1)>*q+*(q+1)) q=p;
  if((*p+*n)>(*q+*(q+1)))
  {
    *n+=*p;
    return *n;
  }
  *q+=*(q+1);
  p=q+1;
  while(p<n+num-1) 
  {
    *p=*(p+1);
    p++;
  }
  return *q;
}
int put2(int *n,int num)
{
  int *p,*q;
  q=n;
  for(p=n;p<n+num-1;p++) if(*p+*(p+1)<*q+*(q+1)) q=p;
  if(*p+*n<*q+*(q+1))
  {
    *n+=*p;
    return *n;
  }
  *q+=*(q+1);
  p=q+1;
  while(p<n+num-1) 
  {
    *p=*(p+1);
    p++;
  }
  return *q;
}

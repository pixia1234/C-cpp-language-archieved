#include <stdio.h>
void sort(int *,int);
int main(int argc, char const *argv[]) {
  int n[10]={5,7,4,2,1,5,8,4,3,2},i;
  sort(n,10);
  for(i=0;i<10;i++) printf("%d ", n[i]);
  return 0;
}
void sort(int *num,int n)
{
  int *p,flag;
  do
  {
    flag=0;
    for(p=num;p<num+n;p++)
    {
      if(*p>*(p+1))
      {
        int temp;
        temp=*p;
        *p=*(p+1);
        *(p+1)=temp;
        flag=1;
      }
    }
  }while(flag);

}

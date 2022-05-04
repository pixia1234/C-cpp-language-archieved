#include<stdio.h>
//3）应用指针，向由大到小顺序排列数组中插入或删除一个元素。
int main()
{
  int num[7]={100,60,40,30,10,1};
  int a,*p,i;
  scanf("%d",&a);
  if(a<num[5])
  {
    num[6]=a;
    for(i=0;i<=6;i++) printf("%d ",num[i]);
    return 0;
  }
  p=num;
  for(i=1;i<=6;i++)
  {
    if(*p<=a) break;
    p++;
  }
  if(*p==a)
  {
    while(p-num<=5)
    {
      *p=*(p+1);
      p++;
    }
    for(i=0;i<=4;i++) printf("%d ",num[i]);
    return 0;
  }
  else
  {
    int *q;
    q=num+7;
    while(q>p)
    {
      *q=*(q-1);
      q--;
    }
    *p=a;
  }
  for(i=0;i<=6;i++) printf("%d ",num[i]);
}

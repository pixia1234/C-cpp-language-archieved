#include<stdio.h>
//2）应用指针，输出数组中的元素。
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,0},*p,i;
    p=a;
    for(i=1;i<=10;i++)
    printf("%d ",*p++);
    return 0;
}

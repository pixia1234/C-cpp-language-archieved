#include<stdio.h>
int fact(int m)
{
	if(m==0||m==1) return 1;
	return (m*fact(m-1));
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",fact(a));
	return 0;
}

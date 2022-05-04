/*
有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数
*/ 
//偷了点懒 
#include<stdio.h> 
int main()
{
	int n,m,num[100001],i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	for(i=1;i<=m;i++) printf("%d ",num[n-m+i]);
	for(i=1;i<=n-m;i++) printf("%d ",num[i]);
	return 0; 
}


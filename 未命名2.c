#include<stdio.h>
int main()
{
	int n=10,i,ans=1;
	for(i=1;i<=n;i++) ans*=i;//i+=2
	printf("%d",ans);
	return 0;
}


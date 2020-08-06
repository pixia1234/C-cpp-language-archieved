#include<stdio.h>
int main()
{
	int n=10,i;
	double r=1.07,ans=1;
	for(i=1;i<=10;i++) ans*=r;
	printf("%.4f",ans);
	return 0;
}


//ื๗าต1
#include<stdio.h>
int main()
{
	int n=10,i,j; 
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n-i;j++) printf(" ");
		for(j=1;j<=2*i-1;j++) printf("*");
		for(j=1;j<=n-i;j++) printf(" ");
		printf("\n");
	}
	return 0;
}


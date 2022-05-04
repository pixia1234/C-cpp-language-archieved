#include <stdio.h>
int bin(int n,int k);
int fact(int m)
{
	int ans=1;
	while(m>0) ans*=m--;
	return ans;
}
int bin(int n,int k)
{
	return fact(n)/fact(k)/fact(n-k);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",bin(a,b));
	return 0;
}

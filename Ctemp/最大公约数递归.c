#include<stdio.h>
int gcd(int m,int n)
{
	int r;
	r=m%n;
	if(r==0) return n;
	return gcd(n,r);
 } 
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b) 
	printf("%d",gcd(a,b));
	else
	printf("%d",gcd(b,a));
	return 0;
}

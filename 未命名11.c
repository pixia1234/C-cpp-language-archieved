#include<stdio.h>
int main()
{
	double a;
	scanf("%lf",&a);
	a*=100;
	a+=0.5;
	a=(int)(a);
	a/=100;
	printf("%f",a) ;
	return 0;
}

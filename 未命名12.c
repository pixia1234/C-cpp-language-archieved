#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s,area;
	scanf("%lf %lf %lf",&a,&b,&c);
	s=(double)(a+b+c)/2;
	area=sqrt((long double)(s-a)*(s-b)*(s-c)*s);
	printf("%lf",area);
	return 0;
}


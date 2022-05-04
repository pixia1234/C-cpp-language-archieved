#include<stdio.h>
int main()
{
	double ans=0;
	int i,j;
	for(i=1;i<=100;i++) 
	{
		if(i%2) ans+=1.0/i;
		else ans-=1.0/i;
	}
	printf("%lf",ans);
	return 0;
}


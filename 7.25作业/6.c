#include<stdio.h> 
#include<math.h>
int main(){
	double y1,y2,x=0.75;
	y2=x;
	do
	{
		y1=y2;
		y2=2.0/3*y1+x/3.0/y1/y1;
	}while(fabs(y2-y1)>1e-5);
	printf("%lf\n",y2);
	return 0;
}


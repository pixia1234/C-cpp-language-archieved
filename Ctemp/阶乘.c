//mµÄ½×³Ë
#include<stdio.h>
int fact(int m);
int jie(int m)
{
	int ans=0;
	while(m>0) ans+=fact(m--);
	return ans;
}
int  fact(int m)
{
	int product = 1;
	if(m<0) return -1;
	while(m>0) product*=(m--);
	return product;
 } 
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",jie(a));
	return 0;
}

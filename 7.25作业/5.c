//最小公倍数
//不想写了。。。 
//辗转相除法 
#include<stdio.h>
int yue(int a,int b)
{
	int i;
	for(i=2;i<=(a>b?b:a);i++)
	    if(!(a%i)&&!(b%i)) 		return (i*yue(a/i,b/i)) ;
	return 1;
}
int main()
{
	int i,j,k,m,ans;
	scanf("%d%d%d",&i,&j,&k);
	m=yue(i,j);
	ans=i*j/m;
	m=yue(ans,k);
	ans=ans*k/m;
	printf("%d",ans) ;
	return 0;
}


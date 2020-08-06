/*
有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。（选作）
*/
//不就约瑟夫问题嘛（缩减版的） 
#include<stdio.h>
int main()
{
	int n,i,j,a=1;
	scanf("%d",&n);
	int pan[1001]={0};
	for(i=1;i<=n;i++)
	{
		for(j=1;j<3;)
		{
			if(pan[a]==0) j++;
			a++;
			if(a>n) a=1;
	    }
	    while(pan[a]==1) 
	    {
	    	a++;
	    	if(a>n) a=1;
		}
	    
	    pan[a]=1;
	}
	printf("%d",a);
	return 0;
}


#include<stdio.h> 
int main()
{
	int num[4],i,j;
	for(i=0;i<4;i++)
	{
		scanf("%d",&num[i]);
		printf((num[i]%2)?"奇数\n":"偶数\n"); 
	}
	for(i=0;i<4;i++)//冒泡排序
	{
		int flag=1; //应该用bool的，C语言没有 
		for(j=0;j<3;j++)
		{
			if(num[j]>num[j+1]) 
			{
				int a=num[j];
				num[j]=num[j+1];
				num[j+1]=a;
				flag=0;
			}			
		}
		if(flag) break;
	 } 
	for(i=0;i<4;i++) printf("%d ",num[i]);
	return 0;
}


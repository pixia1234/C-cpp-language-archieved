/*
问题描述：工厂在每天的生产过程中，需要一定数量的零件，
同时知道每天生产一个零件的生产单价。
在N天的生产过程中，当天生产的零件能够满足当天的需求，假设当天用不完，能够放到下一天去使用，
但要收取每个零件的保管费，不同的天收取的保管费用也不同。
问题求解：求一个N天的生产计划，即N天中每天生产的零件个数，使总费用最少。
*/
#include<stdio.h> 
int main()
{
	int n,need[1001],cost[1001],keep[1001],i,buy[1001];
	printf("请输入天数\n");
	scanf("%d",&n);
	printf("请输入所需数，生产费用，保管费\n");
	for(i=1;i<=n;i++) scanf("%d%d%d",&need[i],&cost[i],&keep[i]);
	if(n==1)
	{
		printf("%d",need[1]);
		return 0;
	}
	int cost2=100000,buyday=0;
	keep[0]=0;
	for(i=1;i<=n;i++) 
	{
		if(cost2+keep[i]<cost[i]) 
		{
			buy[buyday]+=need[i];
			buy[i]=0;
			cost2+=keep[i]; 
		}
		else
		{
			buyday=i;
			buy[buyday]=need[i];
			cost2=cost[i];
		}
	}
	for(i=1;i<=n;i++) printf("%d ",buy[i]);
}


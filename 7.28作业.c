/*
����������������ÿ������������У���Ҫһ�������������
ͬʱ֪��ÿ������һ��������������ۡ�
��N������������У���������������ܹ����㵱������󣬼��赱���ò��꣬�ܹ��ŵ���һ��ȥʹ�ã�
��Ҫ��ȡÿ������ı��ܷѣ���ͬ������ȡ�ı��ܷ���Ҳ��ͬ��
������⣺��һ��N��������ƻ�����N����ÿ�����������������ʹ�ܷ������١�
*/
#include<stdio.h> 
int main()
{
	int n,need[1001],cost[1001],keep[1001],i,buy[1001];
	printf("����������\n");
	scanf("%d",&n);
	printf("���������������������ã����ܷ�\n");
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


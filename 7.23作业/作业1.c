#include<stdio.h> 
int main()
{
	int num[4],i,j;
	for(i=0;i<4;i++)
	{
		scanf("%d",&num[i]);
		printf((num[i]%2)?"����\n":"ż��\n"); 
	}
	for(i=0;i<4;i++)//ð������
	{
		int flag=1; //Ӧ����bool�ģ�C����û�� 
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


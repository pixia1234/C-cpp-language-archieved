#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	time_t second1,second2;
	second1 = time(0);
	int n,i;
	srand(time(0));
	n=1+rand()%100;
printf("������һ��1-100��������ϵͳ���жϴ��˻���С��\n");
	do
	{
		scanf("%d",&i);
        if(i>n) printf("����\n");
        if(i<n) printf("С��\n");
        if(i==n) break;
	 } while(1);
second2=time(0);
printf("����\n�����õ�ʱ��Ϊ:%ds\n",second2-second1);
return 0;
}


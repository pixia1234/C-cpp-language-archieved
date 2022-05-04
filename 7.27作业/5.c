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
printf("请输入一个1-100的整数，系统会判断大了还是小了\n");
	do
	{
		scanf("%d",&i);
        if(i>n) printf("大了\n");
        if(i<n) printf("小了\n");
        if(i==n) break;
	 } while(1);
second2=time(0);
printf("对了\n您所用的时间为:%ds\n",second2-second1);
return 0;
}


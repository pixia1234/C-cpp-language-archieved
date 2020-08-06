#include<stdio.h>
#include<string.h>
int main(){
	char x[1001];
	int zimu=0,kongge=0,num=0,els=0,i;
	gets(x);
	for(i=0;i<strlen(x);i++)
	{
		if((x[i]>='A'&&x[i]<='Z')||(x[i]>='a'&&x[i]<='z'))	{zimu++;continue;}
		if(x[i]>='0'&&x[i]<='9') {num++;continue;}
		if(x[i]==' '){kongge++; continue;}
		els++;
	}
	printf("zimu:%d\n kongge:%d\n num:%d\n else £º%d\n",zimu,kongge,num,els);
	return 0;
}


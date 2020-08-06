//第一题
//ps：明明是个数学题，有什么编程的必要 ？？ 
#include <stdio.h>
int main(){
	int i;
	for(i=1;;i++)
	{
		if((i%2==1)&&(i%3==2)&&(i%5==4)&&(i%6==5)&&(i%7==0)) break;
	}
	printf("%d",i);//理论上来说还有其他解，不写了 
}


#include<stdio.h>//这个程序太无聊了，一个switch就弄出来了。。。 
int main(){
	int i;
	scanf("%d",&i);
	switch(i)
	{
		case 1 : printf("January\n"); break;
		case 2 : printf("February\n"); break;
		case 3 : printf("March\n"); break;
		case 4 : printf("April\n"); break;
		case 5 : printf("May\n"); break;
		case 6 : printf("June\n"); break;
		case 7 : printf("July\n"); break;
		case 8 : printf("August\n"); break;
		case 9 : printf("Septemper\n"); break;
		case 10 : printf("October\n"); break;
		case 11 : printf("November\n"); break;
		case 12 : printf("December\n"); break;
		default : printf("Unknown month"); break;
	}
	return 0;
}


#include<stdio.h>
int main(){
	char a[]={"\t?\\\x69\082"};
	printf("%s\n",a);
	printf("%d\n",strlen(a));
	printf("%d",sizeof(a));
	return 0;
}


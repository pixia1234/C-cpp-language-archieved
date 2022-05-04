#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,a=1,c=2,b[5];
	printf("%p,%p,%p,%p\n",b,&c,&a,&i);
	 for(i=0;i<9;i++)
	 {
	 	b[i]=i;
	 	printf("%d ",b[i]);
	 }
	 printf("\n%d %d %d",c,a,i);
}


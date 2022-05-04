#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int f1,f2,f3;
	f1=1;
	f2=1;
	printf("1 \t1 \t");
	for(int i=3;i<=40;i++)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
		printf("%d \t",f3);
		if(i%4==0) cout<<endl;
	 } 
}


#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
	double t=1,e=0;
	long long int n=1;
	while(t>=1e-6)
	{
		e+=t;
		t/=n++;
	}
	printf("%lf",e);
}


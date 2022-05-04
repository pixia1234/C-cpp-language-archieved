#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
	int m=12345,n=123456;
	while(m!=n)
	{
	    if(m>n) m-=n;
	    else n-=m;
	}
	cout<<m<<endl;
}


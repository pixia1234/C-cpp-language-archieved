#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,m=12345,n=123456;
	if(m<n) swap(m,n);
    while(1)
    {
    	r=m%n;
    	if(!r) break;
    	m=n;
    	n=r;
	}
	cout<<n<<endl;
}


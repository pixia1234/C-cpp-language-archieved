#include<bits/stdc++.h>
using namespace std;
int times=0,t;
bool huzhi(int a,int b){
    int n=2;
    while(a>1&&b>1)
    {
        if(a%n==0&&b%n==0) return false;
        if(a%n==0) a/=n;
        if(b%n==0) b/=n;
        n++;
    }
    return true;
}
void finding(int t){
    for(int num=1;num<=t;num++) if(t%num==0) if(huzhi(t/num,num))times++;
}
int main()
{
    int n,m;
    cin>>n>>m;
    t=m/n;
    finding(t);
    cout<<times<<endl;
}
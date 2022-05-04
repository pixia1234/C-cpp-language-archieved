#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,num=1;
    cin>>n;
    num=pow(2,n);
    int nu[200],rank[200]={0};
    for(int i=1;i<=num;i++) {cin>>nu[i];rank[i]=i;}
    n--;
    for(;n>0;n--){
        for(int i=1;i<=pow(2,n);i++)
        {
            if(nu[2*i-1]<nu[2*i]) 
            {
                nu[i]=nu[2*i];
                rank[i]=rank[2*i];
            }
            else 
            {
                nu[i]=nu[2*i-1];
                rank[i]=rank[2*i-1];
            }
        }
    }
    cout<<(nu[1]>nu[2]?rank[2]:rank[1])<<endl;
    return 0;
}
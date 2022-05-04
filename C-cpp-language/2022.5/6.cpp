#include<bits/stdc++.h>
using namespace std;
long long int num[22][22]={0};
int main()
{
    int n,m,hx,hy;
    cin>>n>>m>>hx>>hy;
    num[1][1]=1;
    hx++;hy++;
    for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
    {
        if(i==1&& j==1) continue;
        else if((abs(i-hx)==1 && abs(j-hy)==2)||(abs(i-hx)==2 && abs(j-hy)==1)||(i==hx&&j==hy))num[i][j]=0;
        else num[i][j]=num[i-1][j]+num[i][j-1];
    }
    cout<<num[n+1][m+1]<<endl;
    return 0;
}
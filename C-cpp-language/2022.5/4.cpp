#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int b[a];
        for(int j=0;j<a;j++) cin>>b[j];
        int temp=0;
        for(int j=0;j<a;j++) temp=abs(temp-b[j]);
        if (temp<2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
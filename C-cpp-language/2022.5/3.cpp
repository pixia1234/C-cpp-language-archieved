// A. Deletions of Two Adjacent Letters
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        char b;
        cin>>b;
        bool c=false;
        for(int j=0;j<a.length();j++){
            if(a[j]==b && j%2==0) {
                c=true;
                break;
            }
        }
        if(c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
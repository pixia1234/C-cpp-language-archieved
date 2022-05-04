#include <iostream>
using namespace std;
int main(){
	int n,i,x,y,out=-1;
	cin>>n;
	int tan[10010][5];
	for(i=1;i<=n;i++) cin>>tan[i][1]>>tan[i][2]>>tan[i][3]>>tan[i][4];
	cin>>x>>y;
	for(i=n;i>=1;i--){
		if(x>=tan[i][1]&&x<=tan[i][1]+tan[i][3]&&y>=tan[i][2]&&y<=tan[i][4]+tan[i][2]){
			out=i;
			break;
		}
	}
	cout<<out<<endl;
	return 0;
}
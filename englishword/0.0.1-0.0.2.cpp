#include<iostream>
#include<fstream>
#include<Windows.h>
#include <errno.h>
using namespace std;
int main(){
	SetConsoleTitle ("英语单词听写程序 0.0.1->0.0.2");
	cout<<"单词表更新程序 0.0.1->0.0.2"<<endl;
	cout<<"built by : pixia1234"<<endl;
	ifstream fin("word.list");
    if( !fin.is_open())
    {
    	cout<<"小主请把word.list文件放到我所在的文件夹呢！"<<endl;
    	system("Pause");
    	return 0; 
	}
	string a;
	fin>>a;
	if(a!="0.0.1") 
	{
		cout<<"版本不对应，无法使用呢!"<<endl;
		system("Pause");
    	return 0; 
	} 
	string b;
	ofstream fout("word2.list");
	fout<<"0.0.2"<<endl;
	while(fin>>a) 
	{
		fin>>b;
		fout<<a<<" "<<b<<" 0 0"<<endl;
	}
	char s[]={"word.list"};
	if(remove(s)!=0)
	{
		cout<<"转换莫名其妙失败了呢"<<endl;
		cout<<"请通过论坛与我pixia1234反馈" <<endl;
		printf("%s\n",strerror(errno));
		system("Pause");
    	return 0; 
	 } 
	if(rename("word2.list","word.list")==0)
	{
		cout<<"转换大完成！"<<endl;
		cout<<"如果本软件对您有用的话，请在论坛里送我一些免费的评分"<<endl;
		system("Pause");
    	return 0; 
	}
	else
	{
		cout<<"转换莫名其妙失败了呢"<<endl;
		cout<<"请通过论坛与我pixia1234反馈" <<endl;
		printf("%s\n",strerror(errno));
		system("Pause");
    	return 0; 
	 } 
}


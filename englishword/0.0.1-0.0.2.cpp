#include<iostream>
#include<fstream>
#include<Windows.h>
#include <errno.h>
using namespace std;
int main(){
	SetConsoleTitle ("Ӣ�ﵥ����д���� 0.0.1->0.0.2");
	cout<<"���ʱ���³��� 0.0.1->0.0.2"<<endl;
	cout<<"built by : pixia1234"<<endl;
	ifstream fin("word.list");
    if( !fin.is_open())
    {
    	cout<<"С�����word.list�ļ��ŵ������ڵ��ļ����أ�"<<endl;
    	system("Pause");
    	return 0; 
	}
	string a;
	fin>>a;
	if(a!="0.0.1") 
	{
		cout<<"�汾����Ӧ���޷�ʹ����!"<<endl;
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
		cout<<"ת��Ī������ʧ������"<<endl;
		cout<<"��ͨ����̳����pixia1234����" <<endl;
		printf("%s\n",strerror(errno));
		system("Pause");
    	return 0; 
	 } 
	if(rename("word2.list","word.list")==0)
	{
		cout<<"ת������ɣ�"<<endl;
		cout<<"���������������õĻ���������̳������һЩ��ѵ�����"<<endl;
		system("Pause");
    	return 0; 
	}
	else
	{
		cout<<"ת��Ī������ʧ������"<<endl;
		cout<<"��ͨ����̳����pixia1234����" <<endl;
		printf("%s\n",strerror(errno));
		system("Pause");
    	return 0; 
	 } 
}


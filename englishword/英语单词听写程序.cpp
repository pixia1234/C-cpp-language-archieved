#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<Windows.h>
#define VER "0.0.2"
#define PASSWD "pixia1234" 
using namespace std;
int etc();
int cte();
int add();
int lis();
int cho();
int set();
int set_check();
int k=0;
int beta_cho();
struct word
{
    string chi,eng;
};
word wlist[10001]; 
int beta_cho()
{
	
}
int set_check()
{
	ifstream betain("beta.passwd");
	if(!betain.is_open()) return 0;
	string a;
	betain>>a;
	if(a!=PASSWD) 	return 2; 
    return 1;
}
int set()
{
	cout<<"���ڽ��� �߼�����"<<endl;
	if(set_check()!=1){
	    cout<<"������beta����"<<endl;
    	string a;
    	cin>>a;
    	if(a==PASSWD) 
    	{
	 	    cout<<"beta�汾�����ɹ���"<<endl;
		    ofstream betaout("beta.passwd");
			if(!betaout)  //����Ƿ�򿪳ɹ�
			{
            cout <<"�����ļ�ʧ�ܣ�\n";
            return 0; 
		    }
		    betaout<<a<<endl;
		    cout<<"�����½���" <<endl;
		    return 0;
    	}
    	else 
    	{
    		system("cls");
    		cout<<"beta�������"<<endl;
    		cout<<"!!!!��\n����ʧ��" <<endl;
    		return 0; 
    	}
	}
	return beta_cho();
}
int lis()
{
	cout <<"���"<<"   "<<"����    " <<"Ӣ��" <<endl; 
	for(int i=1;i<=k;i++)
	{
		cout << i << "   " <<  wlist[i].chi << "   " << wlist[i].eng << endl;
	} 
	cout << "��������ֵ����" << endl; 
	int x;
	cin >> x;
	system("cls");
	return 0;
}
int add()
{
    cout << "�����뵥�ʵ����ģ�Ӣ�ģ��м��ÿո����" <<endl;
    cout << "����������0" << endl;
    ofstream fout("word.list",ios::app);
    string a,b;
    while(1)
    {
    	cin >> a;
    	if(a=="0") 
		{
			system("cls");
			return 0;
	    }
	    cin >>b;
	    fout <<endl<<b<<" "<<a;
	    k++;
	    wlist[k].chi=a;
	    wlist[k].eng=b;
	    cout<<"��Ӵ�ɹ���"<<endl;
    }
}
int cho()
{
	cout <<"��ѡ����Ҫ���еĲ���"<<endl;
	cout <<"1.��Ӣ����д����   2.��������дӢ��" <<endl;
	cout <<"3.�鿴���ʱ�       4.��ӵ���" <<endl;
	cout <<"5.�߼�����" <<endl; 
	cout <<"��ֱ��������������\n�˳�������ֱ���������������ַ�" <<endl;
	cout <<"����汾Ϊ��" <<VER<< endl; 
	int a;
	cin>>a;
	system("cls");
	switch(a)
	{
		case 1: return etc();
		case 2: return cte();
		case 3: return lis();
		case 4: return add();
		case 5: return set();
		default : return 1;
	}
}
int cte()
{
	cout<<"���ڽ��� ��������дӢ�Ĳ���"<<endl<<"!!!\n";
	cout<<"��ֱ������Ӣ��" <<endl;
	cout<<"�˳�������0" <<endl;
	int tim=0;
	while(1)
	{
	    srand(time(0));
		int a=1+rand()%k;	
		cout << "��" << ++tim << "��" << " ����Ϊ " << wlist[a].chi << endl;
		string ans;
		cin >> ans;
		if(k==0) 
	{
		system("cls");
		cout<<"���ʱ�������"<<endl;
		cout<<"�ѷ���ѡ�񴰿�" <<endl;
		return 0;
	}
		if(ans=="0")
		{
			system("cls");
		    return 0;
		}
		if(ans==wlist[a].eng)
		{
			cout <<"��ϲ������"<<endl;
			continue; 
		}
		else
		{
			cout <<"�ܿ�ϧ�����"<<endl;
			cout <<"��ȷ�Ĵ�Ϊ " << wlist[a].eng<<endl;;
		}
	} 
}
int etc()
{
	cout << "���ڽ��� ��Ӣ����д���Ĳ���" <<endl << "!!!\n";
	cout << "�����жϴ���ƫ��������ж��Ƿ���ȷ" <<endl;
	cout << "����ȷ������1����������0���������������������ַ�" <<endl;
	if(k==0) 
	{
		system("cls");
		cout << "���ʱ�������" << endl;
		cout << "�ѷ���ѡ�񴰿�" << endl;
		return 0;
	}
	int tim=0;
	while(1)
	{
		srand(time(0));
		int a=1+rand()%k,m;
		cout << " ��" << ++tim << "��" << "Ӣ��Ϊ" << wlist[a].eng << endl;
		cin>>m;
		cout << "      ����Ϊ" << wlist[a].chi << endl;
		cin>>a;
		if(a==1)
		{
			cout << "��ϲ������" << endl; 
			continue;
		}
		if(a==0) 
		{
		    cout << "�ܿ�ϧ�����" << endl;
			continue; 
		}
		system("cls");
		return 0;
	}
}
int main()
{
	if(set_check()!=1){
    	SetConsoleTitle ("Ӣ�ﵥ����д����    �汾��0.0.2");
    	cout << "��ӭʹ��Ӣ����д�����\n!!!!!!!!!" << endl;
    	cout << "��ǰ�汾Ϊ��" << VER <<endl;  
    }
    else
	{
		if(set_check()==2) cout<<"beta�������"<<endl;
	    cout<<"beta.passwd��ȡ��ɹ���"  <<endl;
		SetConsoleTitle ("Ӣ�ﵥ����д����    �汾��0.0.2 beta");
    	cout << "��ӭʹ��Ӣ����д�����\n!!!!!!!!!" << endl;
    	cout << "��ǰ�汾Ϊ��" << VER <<" for beta"<<endl;
		
	} 
    ifstream fin("word.list");
    if( !fin.is_open())
    {
    	cout << "�Ҳ���word.list�ļ������ʱ�" << endl; 
    	int x;
    	cout<<"�Ƿ��½�word.list�ļ���(��1ȷ�ϣ������ַ��˳�)" <<endl; 
    	cin>>x;
		if(x==1) 
		{
			ofstream fout("word.list");
			if(!fout)  //����Ƿ�򿪳ɹ�
			{
            cout <<"�����ļ�ʧ�ܣ�\n";
            return 0; 
		    }
		    fout<<VER<<endl;
		    cout<<"�����ļ���ɹ���\n";
		    do
	        {
		        x=cho();
	        } while(x!=1);
	        return 0;
	    }
		else return 0;
	}
	string a,b;
//	fin.clear();
//  fin.seekg(0, ios::beg); 
	fin>>a;	
	if(a!=VER) 
	{
		cout << "word.list�汾��ƥ��" << endl;
	 	cout << "Ϊ��ֹ���ּ�����������ֹͣ����" << endl;
		cout << "���ʱ�汾��" << a;
		cin >> a; 
		return 0;
	}
	cout << "��⵽ƥ���word.list�ļ�" << endl; 
    while(fin >> a) 
    {
    	fin >> b;
		k++;
    	wlist[k].eng=a;
    	wlist[k].chi=b;
	}
	cout << "���ʱ��ȡ��ɹ���" << endl;
	int x=1;
	do
	{
		x=cho();
	} while(x!=1);
	return 0;
}

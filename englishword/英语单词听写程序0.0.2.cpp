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
int suiji();
void exit_();
int k=0;
int total_te=0,total_wr=0; 
struct word
{
    string chi,eng;
    int te,wr;
};
word wlist[10001]; 
int lis()
{
	int chi_maxlen=0,i;
	for(i=1;i<=k;i++)
	{
		if(chi_maxlen<wlist[i].chi.length()) chi_maxlen=wlist[i].chi.length();
	}
	printf("���\t����");
	for(i=1;i<=chi_maxlen+2;i++) printf(" ");
	printf("Ӣ��\n");
	for(int i=1;i<=k;i++)
	{
		cout<<i<<"\t"<<wlist[i].chi;
		for(int j=1;j<=chi_maxlen+3-wlist[i].chi.length();j++) printf(" ");
		cout<<wlist[i].eng<<endl;
	} 
	system("Pause");
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
	    fout <<endl<<b<<" "<<a<<" 0 0";
	    k++;
	    wlist[k].chi=a;
	    wlist[k].eng=b;
	    wlist[k].te=0;
	    wlist[k].wr=0;
	    total_wr+=5;
	    total_te+=5;
	    cout<<"��Ӵ�ɹ���"<<endl;
    }
}
int randnew(int left, int right)
{
  static unsigned int seed = 0;
  seed++;
  srand((unsigned) time(NULL) + seed * seed);
  return rand() % (right - left + 1) + left;
}
int cho()
{
	cout <<"��ѡ����Ҫ���еĲ���"<<endl;
	cout <<"1.��Ӣ����д����   2.��������дӢ��" <<endl;
	cout <<"3.�鿴���ʱ�       4.��ӵ���" <<endl;
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
		default : return 1;
	}
}
int suiji()
{
    int a=0,return_=0;
    do
    {
    	return_=randnew(1,total_te); 
	}while(return_>total_wr);
	while(return_>0) return_-=(wlist[++a].wr+5);
	return a;
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
		int a=suiji();                                             //������㷨 
		cout << "��" << ++tim << "��" << " ����Ϊ " << wlist[a].chi << endl;
		string ans;
		cin >> ans;
		if(k==0) 
	{
		system("cls");
		cout<<"���ʱ�������"<<endl;
		cout<<"�ѷ���ѡ�񴰿�" <<endl;
		system("Pause"); 
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
			wlist[a].te++;
			total_te++;
		}
		else
		{
			cout <<"�ܿ�ϧ�����"<<endl;
			wlist[a].te++;
			wlist[a].wr++;
			total_te++;
			total_wr++;
			cout <<"��ȷ�Ĵ�Ϊ " << wlist[a].eng<<endl;;
		}
		
		if(tim%5==0) 
		{
		    cout<<"Ϊ��ֹ���ݶ�ʧ���Զ���������"<<endl; 
		    exit_();
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
		system("Pause");
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
   	SetConsoleTitle ("Ӣ�ﵥ����д����    �汾��0.0.2");
  	cout << "��ӭʹ��Ӣ����д�����\n!!!!!!!!!" << endl;
    cout << "��ǰ�汾Ϊ��" << VER <<endl;  
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
            system("Pause");
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
	int c,d;
//	fin.clear();
//  fin.seekg(0, ios::beg); 
	fin>>a;	
	if(a!=VER) 
	{
		cout << "word.list�汾��ƥ��" << endl;
	 	cout << "Ϊ��ֹ���ּ�����������ֹͣ����" << endl;
		cout << "���ʱ�汾��" << a;
		if(a=="0.0.1") 
		cout<<"\n��ǰ����̳����0.0.1->0.0.2����"<<endl;
		system("Pause");
		return 0;
	}
	cout << "��⵽ƥ���word.list�ļ�" << endl; 
    while(fin >> a) 
    {
    	fin >> b >> c >> d;
		k++;
    	wlist[k].eng=a;
    	wlist[k].chi=b;
    	wlist[k].te=c;
    	wlist[k].wr=d;
    	total_te+=wlist[k].te+5;
    	total_wr+=wlist[k].wr+5;
	}
	cout << "���ʱ��ȡ��ɹ���" << endl;
	int x=1;
	do
	{
		x=cho();
	} while(x!=1);
	exit_();
	return 0;
}
void exit_()
{
	ofstream fout("word.list");
	fout.seekp(0, ios::beg);
	fout<<VER<<endl;
	for(int i=1;i<=k;i++) 	    fout <<endl<<wlist[i].eng<<" "<<wlist[i].chi<<" "<<wlist[i].te<<" "<<wlist[i].wr;
	cout<<"�����ļ��ɹ���"<<endl;
	return ;
}

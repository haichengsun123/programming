#include<iostream>
#include<stdlib.h>
#include"Circlist.h"
#include<string>
using namespace std;
void main()
{	
	char ch;
	CircList<int> clist;
	  do{ 
		  clist.MakeEmpty();
		  int n,m;
		  n=clist.Createlist();
		  cout<<"����������룬��ÿ���˵ı��Ϊ��"<<endl;
		  clist.Output();
		  cout<<"�������ʼ���ݣ�m>0"<<endl;
		  cin>>m;
		  clist.Josephus(n,m);
		  cout<<"���������һ�֣��밴'y'��'Y'"<<endl;
		  cin>>ch;		  
	  }while(ch=='y'||ch=='Y');
}

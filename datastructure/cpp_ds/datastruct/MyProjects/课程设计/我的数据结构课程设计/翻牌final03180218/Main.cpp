#include <iostream.h>
#include<stdlib.h>
#include"Lqueue.h"
int main()
{
	char ch;
	do{
	Queue<int> queue;	 
    cout<<"******************************"<<endl;   
	cout<<"*     ѡ����Ŀ��             "<<endl;
	cout<<"*�����˿��Ƶ���Ŀ          ��'1' "<<endl;
	cout<<"*�鿴ÿ���Ʊ������Ĵ���    ��'2' "<<endl;
	cout<<"*�鿴���ս��              ��'3' " <<endl;
	cout<<"*������һ�ֳ���:           ��'0' " <<endl;
	cout<<"******************************"<<endl;
	int i,s;
    do{  
		cout<<"���������ѡ��";
		cout<<"1---> ����������2----�鿴���������3----�鿴�������0-----������һ�֣�"<<endl<<endl<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:
			  s=queue.CreateQueue() ;//��ֽ�ư�����Ž�����
			break;
		  case 2:
			   queue.Game(s);     //ֽ����Ϸ�����Կ���ÿ���Ʊ����Ĵ���
			    break;
		   case 3:	 
			   queue.Game();//��ӡ������
			    break;
	   }		   
	 }while(i!=0);	
	cout<<"ȷ��������һ�ֵ�������?ȷ���밴'y' ����'Y',����������"<<endl;
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
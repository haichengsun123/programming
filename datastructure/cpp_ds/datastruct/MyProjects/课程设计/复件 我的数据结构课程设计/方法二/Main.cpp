#include <iostream.h>
#include<stdlib.h>
#include"Lqueue.h"
int main()
{
	Queue<int> queue;	 
    cout<<"******************************"<<endl;   
	cout<<"*     ѡ��ѡ�       "<<endl;
	cout<<"*�����Ƶ���Ŀ��    �밴'1' "<<endl;
	cout<<"*��ӡ���          �밴'2' "<<endl;
	cout<<"*�˳�              �밴'0' "<<endl;
	cout<<"******************************"<<endl;
	int i,s;
    do{  
		cout<<"���������ѡ��";
		cout<<"1---> �����Ƶ���Ŀ��2----��ӡ�����0--->�˳���"<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:
			  s=queue.CreateQueue();
			break;
		  case 2:
			   queue.Game(s);
			   break;
	   }		   
	 }while(i!=0);	
	return 0;
}
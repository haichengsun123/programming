#include<iostream>
#include"student.h"
#include"seqlist.h"
#include<string>
using namespace std;
void main()
{
    seqlist  list(10);
	Student s;
	string d;
	float f;
	cout<<"******************************"<<endl;   
	cout<<"*��ѡ��������Ҫ�ķ���        "<<endl;
	cout<<"*��������밴��1����         "<<endl;
	cout<<"*�����³�Ա�밴��2����       "<<endl;
	cout<<"*ɾ���밴��3����             "<<endl;
	cout<<"*�����밴��4����             "<<endl;
	cout<<"*����밴��5����             "<<endl;
	cout<<"*���Ҹ�����Ϣ�밴��6����     "<<endl;
	cout<<"*�˳��밴��0����             "<<endl;
	cout<<"******************************"<<endl;
	int i;
	do
	{  
		cout<<"���������ѡ��";
		cout<<"1---> ������2----���롢3----ɾ����4--->���¡�5--->�����6-->���ҡ�0-->�˳�"<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:
			  list.Creatlist();		   
			   break;
		  case 2: 
			  list.Insertlist();
			  break;
		  case 3:
			  cout<<"��������Ҫɾ����ѧ����������";
			  cin>>d;
			  if(list.Find(d)==-1) {
				  cout<<"��ѧ������ ɾ��ʧ��"<<endl;
				  continue;
			  } 
			  if(list.Remove(d)==1) cout<<"ɾ���ɹ���"<<endl;
			  break;
		  case 4:
			  cout<<"��������Ҫ���µ�ѧ��������"; 
			  cin>>d;
			  cout<<"����������ѧ���ĳɼ���"<<endl;
			  cin>>f;
			  list.New(f,list.Find(d));		  
			   break;
		  case 5:
			  list.output();
			   break;
		  case 6:
			  cout<<"��������Ҫ���ҵ�ѧ��������"<<endl;
			  cin>>d;
			  if(list.Find(d)==-1) cout<<"�޸�ѧ��������"<<endl;
			  else  list.print(list.Find(d));
			  break;
	   }
	}while(i!=0);

}
	

#include<iostream>
#include"student.h"
#include"seqlist.h"
#include<string>
using namespace std;
int main()
{
    seqlist <Student> list(10);
	ListNode *search;
    Student s;         //����student��
    string d;  float f;
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
	while(i!=0)
	{  
		cout<<"���������ѡ��";
		cout<<"1---> ������2----���롢3----ɾ����4--->���¡�5--->�����6-->���ҡ�0-->�˳�"<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:
			   cout<<"��������Ҫ�����ı��Ԫ�صĸ���Ϊ��";
			   int n,m;	    
			   cin>>n; 
			   for(m=0;m<n;m++)
			   {
				   s.Input();
				   list.insert(s,m);
			   }
			   break;
		   case 2: 
			   s.Input();
			   cout<<"��������Ҫ�����λ��:"; 
			   int c;
			   cin>>c;
			   if(list.insert(s,c-1)==0) cout<<"����ʧ�ܣ�"<<endl;
			    else  cout<<"����ɹ���"<<endl;
			   break;
		   case 3:
			   cout<<"��������Ҫɾ����ѧ����������";
			   cin>>d;
			   if(list.find(d)<0) {
				   cout<<"��ѧ������ ɾ��ʧ��"<<endl;
			       continue;
			   } 
			   if(list.remove(d)==1) cout<<"ɾ���ɹ���"<<endl;
			    break;
		  // case 4:
			 //  cout<<"��������Ҫ���µ�ѧ��������"; 
			 //  cin>>d;
			 //cout<<"����������ѧ���ĳɼ���"<<endl;
			  // cin>>f;
			    //l.Find(d)->New(f);


			   //break;
		   //case 6:
			 //  cout<<"��������Ҫ���ҵ�ѧ��������"<<endl;
			  // cin>>d;
			   //search=l.find(d);
			   //if(search==NULL) cout<<"�޸�ѧ��������"<<endl;
			   //else  search->print();
			   //break;
		   case 5:
			   //cout<<l.Length()<<endl;
			   if(list.getlast()<0) {cout<<"         Ŀǰ��ѧ��������"<<endl;}
			   for(int a=0;a<list.getlast;a++)
			   {
				   cout<<"ѧ�� "<<list.getlast()<<endl<<"    "<<"ѧ��"<<l.Get1(a)<<endl<<"    "<<"�ɼ� "<<l.Get2(a)<<endl;
			   }
			   break;
			    
		   	  
	   }
	}
	return 0; 
}

	{
    cout<<"******************************"<<endl;   
	cout<<"*��ѡ��������Ҫ�ķ���        "<<endl;
	cout<<"*��������밴��1����         "<<endl;
	cout<<"*�����³�Ա�밴��2����       "<<endl;
	cout<<"*ɾ���밴��3����             "<<endl;
	cout<<"*������Ϣ�밴��4����     "<<endl;
	cout<<"*����밴��5����             "<<endl;
	cout<<"*�˳��밴��0����             "<<endl;
	cout<<"******************************"<<endl;
	int i;
	while(i!=0)
	{  
		cout<<"���������ѡ��";
		//cout<<"1---> ������2----���롢3----ɾ����4--->���¡�5--->�����6-->���ҡ�0-->�˳�"<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:
			   cout<<"��������Ҫ�����ı��Ԫ�صĸ���Ϊ��";
			   int n;	    
			   cin>>n; 
               list.create(n);
               //for(i=0;i<=list.getlast();i++){
	              //cout<<list.getdata(i)<<endl;}
			   break;
		   case 2: 
			   cout<<"��������Ҫ�����λ�ú�ֵ:"; 
			   int c;
			   int v;
			   cin>>c;
			   cin>>v;
			   if(list.insert(v,c)==0) cout<<"����ʧ�ܣ�"<<endl;
			      else  cout<<"����ɹ���"<<endl;
			   break;
		   case 3:
			   cout<<"������Ҫɾ�������ݣ�";
			   int d;
			   cin>>d;
			   if(list.find(d)==-1) {
				   cout<<"��ѧ������ ɾ��ʧ��"<<endl;
			       continue;
			   } 
			   if(list.remove(d)==1) cout<<"ɾ���ɹ���"<<endl;
			    break;
		   case 4:
			   cout<<"��������Ҫ���ҵ����ݣ�"<<endl;
			   cin>>d;
			   int search;
			   search=list.find(d);
			   if(search==-1) cout<<"�޸�ѧ��������"<<endl;
			   else  cout<<list.getdata(search)<<endl;
			   break;
		   case 5:
			   //cout<<l.Length()<<endl;
			   if(list.getlast()<0) {cout<<"         Ŀǰ��ѧ��������"<<endl;}
			   for(i=0;i<=list.getlast();i++){
	                cout<<list.getdata(i).GetName()<<list.getdata(i).GetID()<<list.getdata(i).GetName()<<endl;}
		   	  
	   }
	}

}
	return 0; 
}

int List::Get1(int i)
{
	if(p==NULL||p==first) return 0;
	else return p->data.ID;
}

float List::Get2(int i)
{
	ListNode *p=Find(i);
	if(p==NULL||p==first) return 0;
	else return p->data.score;
}
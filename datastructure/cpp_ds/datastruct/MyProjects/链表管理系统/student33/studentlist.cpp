#include<iostream>
#include"student.h"
#include"list.h"
#include<string>
using namespace std;
int main()
{
    ListNode *search;
    Student s,s1("wuming ",0,0.0);         //����student��
	List  l(s1);
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
				   l.Insert(s,m);
			   }
			   break;
		   case 2: 
			   s.Input();
			   cout<<"��������Ҫ�����λ��:"; 
			   int c;
			   cin>>c;
			   //l.Insert(s,c-1);
			   if(l.Insert(s,c-1)==0) cout<<"����ʧ�ܣ�"<<endl;
			    else  cout<<"����ɹ���"<<endl;
			   break;
		   case 3:
			   cout<<"��������Ҫɾ����ѧ����������";
			   cin>>d;
			   //l.Remove(d);
			   if(l.Find(d)==NULL) {
				   cout<<"��ѧ������ ɾ��ʧ��"<<endl;
			       continue;
			   } 
			   if(l.Remove(d)==1) cout<<"ɾ���ɹ���"<<endl;
			    break;
		   case 4:
			   cout<<"��������Ҫ���µ�ѧ��������"; 
			   cin>>d;
			   //ListNode *q;
				 // q=l.Find(d);
			   cout<<"����������ѧ���ĳɼ���"<<endl;
			   cin>>f;
			    l.Find(d)->New(f);
			   //q->link->Student.score=f;

			   break;
		   case 6:
			   cout<<"��������Ҫ���ҵ�ѧ��������"<<endl;
			   cin>>d;
			   search=l.Find(d);
			   if(search==NULL) cout<<"�޸�ѧ��������"<<endl;
			   else  search->print();
			   break;
		   case 5:
			   //cout<<l.Length()<<endl;
			   if(l.Length()==0) {cout<<"         Ŀǰ��ѧ��������"<<endl;}
			   for(int a=0;a<l.Length();a++)
			   {
				   cout<<"ѧ�� "<<l.Get(a)<<endl<<"    "<<"ѧ��"<<l.Get1(a)<<endl<<"    "<<"�ɼ� "<<l.Get2(a)<<endl;
			   }
			   break;
			    
		   	  
	   }
	}
	return 0; 
}
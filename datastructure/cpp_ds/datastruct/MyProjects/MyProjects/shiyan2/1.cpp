#include<iostream.h>
#include"list.h"
#include<string.h>
//using namespace std;
int main()
{
    
	seqlist<int> xxb(10); 
	int i=1;
	if(xxb.insert(i,0)==1) cout<<"����ɹ�" ;
	else cout<<"fail";
	/*int i;
    do{  
		cout<<"���������ѡ��";
		//cout<<"1---> ������2----���롢3----ɾ����4--->���¡�5--->�����6-->���ҡ�0-->�˳�"<<endl;
	   cin>>i;  
	   switch(i)
	   { 
	      case 1:
			   cout<<"��������Ҫ�����ı��Ԫ�صĸ���Ϊ��";
			   int n,m;	    
			   cin>>n; 
			   for(m=0;m<n;m++)
			   {   
				   xxb.input();
				   int s;
				   cin>>s;
				   xxb.insert(s,m);
			   }
			   break;
		   case 2: 
			   //s.Input();
			   cout<<"��������Ҫ�����λ��:"; 
			   int s;
			   int c;
			   cin>>c>>s;
			   //l.Insert(s,c-1);
               //xxb.input();
			   if(xxb.insert(s,c-1)==0) cout<<"����ʧ�ܣ�"<<endl;
			    else  cout<<"����ɹ���"<<endl;
			   break;
	   }*/
		  /* case 3:
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
	}*/
	   //}while(i!=0);
	return 0; 
}
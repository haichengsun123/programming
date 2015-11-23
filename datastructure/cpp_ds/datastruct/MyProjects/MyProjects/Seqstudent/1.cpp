#include <iostream.h>
#include<stdlib.h>
#include"student.h"
template <class type>class seqlist
{
private:
   type *data;              //˳����Ĵ������
   int  maxsize;           //˳�����������������
   int  last;                  //��ǰ�Ѵ��������λ��
public:
    seqlist(int maxsize);
    ~seqlist(){delete[] data;}
    int  length()const {return last+1;}   //�������
    void  create(int i);
    int find (type &x) const;                //��λ��������x�ڱ��е�λ��
    int  isin (type &x);                        //�ж�X�ڱ��У���find()������
    int getlast(){return last;};
    type getdata(int i){return i<0||i>last?NULL:data[i];}//ȡ����
    int insert(type x,int i);                       //�ڱ��е�i��λ�ô�����X
    int remove(type &x);               //ɾ��X
    int next(){return current<last?&data[++current]:NULL;} //��x�ĺ��
    int prior(){return current>0?&data[--current]:NULL;}  //�ҳ�x��ǰ��
    int isempty(){return last = = -1;}  // �п�
    int isfull(){return last==maxsize-1;}  // ����
};
template<class type> seqlist<type>::seqlist(int sz)
{
    if (sz>0)
       {  maxsize=sz;last=-1;
           data=new type[maxsize];
           if (data==NULL)
              {cerr<<"�ڴ����"<<endl;exit(1);}
         }
}
template<class type>int seqlist<type>::find(type &x)const 
{ 
	int i=0;
	while(i<=last&&data[i]!=x) i++;
	if(i>last) return -1;
	else return i;
}
template<class type>int  seqlist<type>::insert(type x,int i)
{
	if(i<0||i>last+1||last==maxsize-1) return 0;
	else
	{
		last++;
		for(int j=last;j>i;j--) data[j]=data[j-1];
		data[i]=x;return 1;
	}
}
template<class type>void seqlist<type>::create(int i)
{
	type x;
	for(int j=0;j<i;j++)
	{
		cout<<"���ǵ�"<<j+1<<"��"<<endl;
		cin>>x;
		data[j]=x;
		last++;
	}
}
template<class type >int  seqlist<type>::remove(type &x)
{
    int  i=find(x);
    if(i>=0)
	{
	last--;
      for(int j=i;j<=last;j++)data[j]=data[j+1];
     return 1;
      }
   return   0;
}
template<class type >int seqlist<type>::isin(type &x){
	int i=0,found=0;
	while(i<=last&&!=found)
		if(data[j]!=x) i++;
		else found=1;
	return found;
}
int main()
{
	seqlist <student> list(10);	  
	Student s,s1("wuming ",0,0.0);         //����student��
    //string d;  float f;
    cout<<"******************************"<<endl;   
	cout<<"*��ѡ��������Ҫ�ķ���        "<<endl;
	cout<<"*���������밴��1����         "<<endl;
	cout<<"*�����³�Ա�밴��2����       "<<endl;
	cout<<"*ɾ���밴��3����             "<<endl;
	cout<<"*������Ϣ�밴��4����     "<<endl;
	cout<<"*����밴��5����             "<<endl;
	cout<<"*�˳��밴��0����             "<<endl;
	cout<<"******************************"<<endl;
	/*int i;
	while(i!=0)
	{  

		cout<<"���������ѡ��";
		//cout<<"1---> ������2----���롢3----ɾ����4--->���¡�5--->�����6-->���ҡ�0-->�˳�"<<endl;
		cin>>i;  
	   switch(i)
	   { 
	      case 1:*/
			   cout<<"��������Ҫ�����ı���Ԫ�صĸ���Ϊ��";
			   int n,m;	    
			   cin>>n; 
 			   for(m=0;m<n;m++)
			   {
				   s.Input();
				   l.Insert(s,m);
			   }
	}
		   /*case 2: 
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
	                cout<<list.getdata(i)<<endl;}
		   	  
	   }
	}

}
	return 0; 
}
*/


/*ListNode *search;
    Student s,s1("wuming ",0,0.0);         //����student��
	List  l(s1);
    string d;  float f;
    cout<<"******************************"<<endl;   
	cout<<"*��ѡ��������Ҫ�ķ���        "<<endl;
	cout<<"*���������밴��1����         "<<endl;
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
			   cout<<"��������Ҫ�����ı���Ԫ�صĸ���Ϊ��";
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
}*/
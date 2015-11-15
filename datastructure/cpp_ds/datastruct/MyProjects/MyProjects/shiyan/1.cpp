class List;
class ListNode
{
friend class List;
public:
     ListNode();
	 ListNode(const Student & item);
	 ListNode * NextNoed(){return link;}
	 void InsertAfter(ListNode *p);
	 ListNode *GetNode(const Student & item,ListNode *next);
	 ListNode *RemoveAfter();
	 void print(){cout<<"ѧ�� :"<<"     "<<data.GetName()<<"     "<<"ѧ��"<<data.GetID()<<"     "<<"�ɼ�"<<data.GetScore()<<endl;}
	 void New(float & n){data.score=n;}
private:
	Student data;
	ListNode *link;
};
class List
{
public:
	List(const Student & value)
	{last=first=new ListNode(value);}
	~List();
	void MakeEmpty();
	int Length() const;
	ListNode * Find( string value);
	ListNode * FindBefore( string value);
	ListNode * Find(int i);
	int Insert(Student value,int i);
	int Remove(string i);
	string  Get(int i);
	float Get2(int i);
	int Get1(int i);
private:
	ListNode * first ,* last;
};
ListNode::ListNode():link(NULL){}
ListNode::ListNode(const Student & item):data(item),link(NULL){}
void ListNode::InsertAfter(ListNode *p)
{p->link=link;}
ListNode * ListNode::GetNode(const Student & item,ListNode * next=NULL)
{
	ListNode *newnode=new ListNode(item);
	newnode->link=next;
	return newnode;
}
ListNode * ListNode::RemoveAfter()
{
	ListNode * tempptr=link;
	if(link==NULL) return NULL;
	link=tempptr->link;
	return tempptr;
}
List::~List()
{
	MakeEmpty(); delete first;
}
void List::MakeEmpty()
{
	ListNode *q;
	while(first->link!=NULL)
	{
		q=first->link;
		first->link=q->link;
		delete q;
	}
	last=first;
}
int List::Length() const
{
	ListNode *p=first->link;int count=0;
	while(p!=NULL){p=p->link;count++;}
	return count;
}
ListNode * List::FindBefore(string  value)
{
	ListNode *p=first;
	while(p!=NULL&&first->data.name!=value&&p->link->data.name!=value)  p=p->link;
    if (p->link==NULL) return NULL;
	return p; 
}
ListNode * List::Find(string  value)
{
	ListNode *p=first;
	while(p!=NULL&&p->data.name!=value)  p=p->link;
        if(p==NULL)  return NULL;
	return p; 
}
ListNode * List::Find(int i)
{
	if(i<-1) return NULL;
	if(i==-1) return first;
    ListNode *p=first->link; int j=0;
	while(p!=NULL&&j<i){p=p->link;j++;}
	return p;
}
int List::Insert(Student  value,int i)
{ 
	ListNode *p=Find(i-1);
	if(p==NULL) return 0;
	ListNode *newnode=p->GetNode(value ,p->link);
	if(p->link==NULL) last=newnode;
	p->link=newnode; 
	return 1;
	
}
int List::Remove(string va)
{
	ListNode *p=FindBefore(va), *q;
	if(p==NULL||p->link==NULL)  return 0;
	q=p->link;
	p->link=q->link;
	Student * value=new Student(q->data);
	if(q==last)last=p;
	delete q;
	return 1;
}
string  List::Get(int i)
{
	ListNode *p=Find(i);
	if(p==NULL||p==first) return NULL ;
	else return p->data.name;
}
int List::Get1(int i)
{
	ListNode *p=Find(i);
	if(p==NULL||p==first) return 0;
	else return p->data.ID;
}

float List::Get2(int i)
{
	ListNode *p=Find(i);
	if(p==NULL||p==first) return 0;
	else return p->data.score;
}
//#include<iostream>
//#include<string>
//using namespace std;
class Student      //ѧ������Ϣ�洢��
{
friend class ListNode; //����ListNode��Ϊ��Ԫ��
friend class List; //����List��Ϊ��Ԫ��
private:           //��װѧ���ĸ�����Ϣ
     string name;
     int     ID;
     float score;
public:
	Student():name(" "),ID(0),score(0){}  //�޲ι��캯��
	Student(string m,int n,float s);      //���캯��
	Student(const Student & x);     //���ƹ��캯��
	~Student(){}                    //�������� 
	string GetName(){return name;}
        int GetID(){return ID;}
	float GetScore(){return score;}
	void Output();    //���
	void Input();     //����
};
Student::Student(const Student & x)
{
	 name=x.name;
	score=x.score;
        ID=x.ID;
}
Student::Student(string m,int n,float s)
{
	name=m;
        ID=n;
	score=s;
}
void Student::Output()
{
	cout<<"������"<<name<<"ѧ�ţ�"<<ID<<"������"<<score<<endl;
}
void Student::Input()
{
	cout<<"������ѧ��������"<<endl;
	cin>>name;
        cout<<"������ѧ����ѧ��"<<endl;
        cin>>ID;
	cout<<"������ѧ���ķ���"<<endl;
	cin>>score;
       
        
} 
#include<iostream>
//#include"student.h"
//#include"list.h"
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
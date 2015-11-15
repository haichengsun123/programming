#include<iostream>
#include<string>
using namespace std;
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
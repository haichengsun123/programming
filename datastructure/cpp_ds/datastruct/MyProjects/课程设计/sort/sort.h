#include<iostream>
using namespace std;
class Sort;          //ǰ���ඨ��
class Datalist         //������Ķ���
{
public:
	friend class Sort;
	Datalist(int n,int *a);
private:
	int currentsize;
	int *vector;
};
class Sort
{
public:
	Sort()
	{
	a=NULL;
	}
	Sort(Datalist *arr);        //���캯����arr������׵�ַ
	~Sort();                      //��������
    void insertsort(Datalist &list);    //��������
	void bubblesort(Datalist &list);               //��������
	void output(Datalist &list);
private:
	Datalist *a;
	void insert(Datalist &list,int i);//��ǰ����������кú��ñȽϴ�С�ķ�ʽ���ڸ����ݲ����������γ�һ����˳��Ķ���
	void bubble(Datalist &list,const int i,int &exchange);
	 
};
Datalist::Datalist(int n,int *a)
{  
  currentsize=n;
  vector=a;
}
Sort::Sort(Datalist arr[])
{
	a=arr;
}
Sort::~Sort()
{
delete []a;
}
void Sort::insertsort(Datalist &list)//���ؼ��������˳�����������
{
   for(int j=0;j<list.currentsize;j++)
	   insert(list,j);
}
void Sort::insert(Datalist &list,int i)
{
	int temp=list.vector[i];
	int j=i;
	while (j>0&&temp<list.vector[j-1])
   {
     list.vector[j]=list.vector[j-1];j--;
   }
   list.vector[j]=temp;
}
void Sort::output(Datalist &list){
	cout<<"the element in the list after sorting  is :"<<endl;
	for(int i=0;i<list.currentsize;i++){
		cout<<list.vector[i]<<"     ";
	}
	cout<<endl;
}

void Sort::bubble(Datalist &list,const int i,int &exchange)
{
	exchange=0;
	int temp;
	for(int j=list.currentsize-1;j>=i;j--)
		if(list.vector[j-1]>list.vector[j]){
			temp=list.vector[j];
			list.vector[j]=list.vector[j-1];
			list.vector[j-1]=temp;
			exchange=1;
		}

}
void Sort::bubblesort(Datalist &list)
{
	int pass=1;int exchange=1;
	while(pass<list.currentsize&&exchange){
		bubble(list,pass,exchange);
		pass++;
	}
}

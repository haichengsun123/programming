//#include<iostream.h>

const int MAX = 20; //���ϵ�����Ա����

class UFSet{ //���鼯��

public:
	UFSet(int s = MAX); //���캯��
	UFSet(const UFSet & obj); //�������캯
	~UFSet() //������
	{
		delete []father;
	}

	UFSet & operator = (const UFSet & obj); //��ֵ����

	int FindFather(int pos); //Ѱ�����pos���峤����

	bool Unite(int posI, int posJ);//����ԱposI��posJ�ϲ���ͬһ������

	int FindFatherAndReducePath(int pos); //�����峤��ѹ��·��

	bool UnionBySize (int posI, int posJ); //����С��

	bool SameFamily(int posI, int posJ); //�жϳ�ԱposI��posJ�Ƿ�����ͬһ����

	void PrintUFSet();
	int* FindRoot();
	void Print();
private:
	int *father; //���鼯��Ա���飬��Ÿ�Ԫ�صĸ��׽��
	int size; //���鼯��Ա����
	int *vec;
	int counter;
};
UFSet::UFSet(int s) : size(s) //���캯��
{
	father = new int[size];
	for (int i=0; i<size; i++) //���е�����Ԫ��ֵ����ʼ��Ϊ-1
		father[i] = -1;
}
UFSet::UFSet(const UFSet & obj) //�������캯��
{
	size = obj.size;
	father = new int[size + 1];
	for (int i=0; i<=size; i++)
		father[i] = obj.father[i];
}
UFSet & UFSet::operator = (const UFSet & obj) //��ֵ����
{
	if (this == &obj) //����Ը�ֵ
		return *this;
	delete []father; //�ͷ�ԭ�е��ڴ���Դ
	size = obj.size; //�����µ��ڴ���Դ������������
	father = new int[size + 1];
	for (int i=0; i<=size; i++)
		father[i] = obj.father[i];
	return *this; //���ر����������
}

int UFSet::FindFather(int pos)//Ѱ�����pos���峤���ˡ���pos�������峤���򷵻�����
{
	if (father[pos] < 0)
		return pos;
	return FindFather(father[pos]);
}

bool UFSet::Unite(int posI, int posJ)//����ԱposI��posJ�ϲ���ͬһ������
{
	//���ȸ���ȥѰ���Լ����峤
	
	int fI = FindFather(posI);
	int fJ = FindFather(posJ);
	if (fI == fJ) //�����ͬһ���峤���£����غϲ������ϲ�ʧ��
		return false;
	else
		father[fJ] = fI; //����fI���峤��˭��posIվ��posJ��ǰ����!
	return true;
}
int UFSet::FindFatherAndReducePath(int pos)//�����峤��ѹ��·��
{
	if (father[pos] < 0)
		return pos;
	//���Լ������峤�����ҵ��峤�󣬽���;���Ľ���ָ���峤
	return father[pos] = FindFatherAndReducePath(father[pos]);
}
bool UFSet::UnionBySize(int posI, int posJ)//����С��
{
	//���ȸ���ȥѰ���Լ����峤
	int fI = FindFatherAndReducePath(posI);
	int fJ = FindFatherAndReducePath(posJ);
	if (fI == fJ) //�����ͬһ���峤���£����غϲ������ϲ�ʧ��
		return false;
	else if (father[fI] < father[fJ])
	{//����峤fI��ʵ����fJǿ����|fI|>|fJ|����fI���峤�����޸�father[fI]��father[fJ]
		father[fI] -= father[fJ];
		father[fJ] = fI;
	}
	else //����fJ���峤
	{
		father[fJ] -= father[fI];
		father[fI] = fJ;
	}
	return true;
	
}

bool UFSet::SameFamily(int posI, int posJ)//�жϳ�ԱposI��posJ�Ƿ�����ͬһ����

{
	return FindFatherAndReducePath(posI) == FindFatherAndReducePath(posJ);
	
}
void UFSet::PrintUFSet()//������ϵ�����Ԫ��
{
	for (int i=0; i<size; i++)
		cout<<FindFatherAndReducePath(i)<< ' '<<endl;
	cout << endl;
}
int* UFSet:: FindRoot()//�������еĸ��ڵ�
{
	int flag=0;
	counter=0;
	vec=new int(size);
	vec[counter]=FindFatherAndReducePath(0);
	for(int i=1;i<size;i++){
			for(int j=0;j<=counter;j++){
				if(FindFatherAndReducePath(i)==vec[j])
					break;
				if(j==counter){
					++counter;
					vec[counter]=FindFatherAndReducePath(i);
				}
			}
	}
	return vec;
}
void UFSet::Print()//������ϵ�����Ԫ��
{
    
    FindRoot();

	cout<<"counter:"<<counter<<endl;
	cout<<"root:"<<endl;
	for(int i=0;i<=counter;i++){
		cout<<vec[i]<<endl;
	}
	cout<<"output the equivalence class  :"<<endl;
	for(int m=0;m<=counter;m++)
		for(int n=0;n<size;n++)
		{
			if (FindFather(n)==vec[m])
			{
				cout<<n<<"  ";
			}
			if (n==(size-1))
			{
				cout<<endl;
				}
		}

}
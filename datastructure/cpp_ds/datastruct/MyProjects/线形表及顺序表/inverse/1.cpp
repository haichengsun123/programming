#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#define LIST_INIT_LENGTH 10                  
#define OK 1		                                 
typedef int ElemType;    
typedef  struct  CirLNode  
{
	ElemType			data;
	struct CirLNode		*next;
} CirLNode,  *CirLinkList;
void CreateList_L(CirLinkList &L,int n)		//���� ������ L
{ 
  int i;
  CirLNode *p;
  int array[LIST_INIT_LENGTH];
  L=(CirLinkList)malloc(sizeof(CirLNode));
  L->next=NULL;
    
  printf("���������data��,����Ϊ����,�Իس����߿ո���Ϊ���: <��: 34 20 2 3 10 51 12>\n"); 
  for(i=0;i<n;i++)               //�������dataԪ��
 scanf("%d",&array[i]);
  for(i=n-1;i>=0;--i)
  { p=(CirLinkList)malloc(sizeof(CirLNode));	//�½����
	  p->data=array[i];                 //data ��
	  p->next=L->next;					//next ��
	  L->next=p;
  }     //end of for
  //for(p=L;p->next!=NULL;p=p->next) ;
  //p->next=L;		//���һ�����ָ��ͷ���
} //end of CreateList_L() function 
int Contray_CirL(CirLinkList &L)	// �����������ã������� OK
{CirLinkList t,p,q;
	t=L;
t=t->next;			
p=t->next;	
	t->next=NULL;	
	while (p!= NULL )
	{q=p->next;//�޸�q��� next ��ָ�룬ʹָ֮����ǰ��
	p->next=t;			// ˳������ƶ�ָ�� t
		t=p;			// ˳������ƶ�ָ�� p
		p=q;		// ˳������ƶ�ָ�� q
	} // while ����
L= t;//
	return OK;
} // Contray_CirL
void main()				//main() ����
{CirLinkList L;   CirLNode *p;
	int LNodeNum;		// �洢������Ԫ�صĸ���
cout<<"�����뵥ѭ������Ԫ�صĸ���? <�� 7> : ";
	cin>>LNodeNum;
	CreateList_L(L,LNodeNum);	//���쵥����L 
cout<<endl<<"�½��ĵ�����L����:"<<endl;    p=L;
	while(p->next!=NULL)
	{p=p->next;
		cout<<p->data<<" -> ";	//���������Ԫ��
	}
	
	Contray_CirL(L);

	cout<<"���ú�ĵ�����L����:"<<endl;
	p=L;
	while(p->next!=NULL)
	{
	    p=p->next;
		cout<<p->data<<" -> ";	//������ú�ĵ�ѭ������
	}

	cout<<endl<<"...OK...!"<<endl;
	getch();
}//end of main() function



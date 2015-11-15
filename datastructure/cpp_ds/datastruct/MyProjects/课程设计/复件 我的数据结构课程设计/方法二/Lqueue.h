#include<assert.h>
template <class Type> class Queue;
template <class Type> class QueueNode {
friend class Queue<Type>;
private: 
    Type data;	//���н������
	int flag;   //ֽ�Ʊ����������ı�־ 
    QueueNode<Type> *link;    //�����ָ��
public:
    QueueNode ( Type d=0,int f=0, QueueNode *l=NULL ) : data (d),flag(f),link (l) { }
};
template <class Type> class Queue {	
private: 
    QueueNode<Type> *front, *rear; //����ָ��
public: 
    Queue ( ) : rear ( NULL ), front ( NULL ) { }
    ~Queue ( );	
	int CreateQueue();
    void EnQueue ( const Type & item,const int &F );//����
    void DeQueue ( );//����
    Type GetFront_data( );//�鿴��ͷԪ��
	int  GetFront_flag( );//�鿴flag
	void Game(int n);
    int IsEmpty ( ) const { return front == NULL; }//�п�
};
template <class Type>
Queue<Type>::~Queue ( ) {
//���е���������
    QueueNode<Type> *p;
    while ( front != NULL ) {	     //�������ͷ�
        p = front;  front = front->link;  delete p;
    }
}
template <class Type> int Queue<Type>::CreateQueue() {//��������
		cout<<"�������Ƶ���Ŀ:"<<endl;
		int s,j,Flag ;
		Flag=0;
		cin>>s;
		for(j=1;j<=s;j++){
			EnQueue(j,Flag);
		}
		return s;
}
template <class Type> void Queue<Type>:: EnQueue ( const Type & item,const int &F ){
//����Ԫ��item���뵽���еĶ�β 
    if ( front == NULL )    //��, ������һ�����
	front = rear = new QueueNode<Type> ( item, F,NULL );
    else                               //���в���, ����
         rear = rear->link = new QueueNode<Type> ( item,F, NULL );
}
template <class Type> void Queue<Type>::DeQueue ( ) {
//ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
    if(IsEmpty()==0){	//���в���ʱ����ִ��
    QueueNode<Type> *p = front;
    Type retvalue=p->data;//ȡ����ͷ����ֵ
    front = front->link; 	      //�¶�ͷ
    delete p;//�ͷ�ԭ��ͷ���
	}
	else
		cout<<"����Ϊ��"<<endl;
}
template <class Type> Type Queue<Type>::GetFront_data() {
//���Ӳ��գ��������ض�ͷԪ�ص�ֵ; 
    assert(!IsEmpty()) ;			
    return front->data;				
}
template <class Type> int Queue<Type>::GetFront_flag() {
	assert(!IsEmpty());
	return front->flag;
}
template <class Type> void Queue<Type>::Game(int n) {//ֽ����Ϸ��ֱ��������
	cout<<"���ϵ��Ƶı��Ϊ:"<<endl;
	Type temp1;
	int count,temp2;
	count=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(j==i){
				if(GetFront_flag()%2==0) {			
					cout<<"             "<<GetFront_data()<<endl;count++;
				}
				DeQueue();	
			}
			else{
				temp1=GetFront_data();
				temp2=GetFront_flag();
				if(temp1%(i+1)==0) {DeQueue();EnQueue(temp1,++temp2);}
				else  {DeQueue();EnQueue(j,temp2);}
			}
		}
		cout<<"���ϵ��Ƶ�����Ϊ��  "<<count<<endl;
}

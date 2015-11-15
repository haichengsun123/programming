#include<assert.h>
template <class Type> class Queue;
template <class Type> class QueueNode {
friend class Queue<Type>;
private: 
    Type data;	//���н������
	int flag;

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
    void EnQueue ( const Type & item,const int &F );//��item���������
    Type DeQueue ( );//ɾ�������ض�ͷԪ��
    Type GetFront_data( );//�鿴��ͷԪ��
	int  GetFront_flag( );			
    void MakeEmpty ( ); //�ÿն���,ʵ����~Queue( )ͬ
	void Output();
	void Game(int n);
	void Game();
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
template <class Type> void Queue<Type>:: EnQueue ( const Type & item,const int &F ){
//����Ԫ��item���뵽���еĶ�β 
    if ( front == NULL )    //��, ������һ�����
	front = rear = new QueueNode<Type> ( item, F,NULL );
    else                               //���в���, ����
         rear = rear->link = new QueueNode<Type> ( item,F, NULL );
}
template <class Type> Type Queue<Type>::DeQueue ( ) {
//ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
    assert(!IsEmpty());	//���в���ʱ����ִ��
    QueueNode<Type> *p = front;
    Type retvalue=p->data;//ȡ����ͷ����ֵ
    front = front->link; 	      //�¶�ͷ
    delete p;//�ͷ�ԭ��ͷ���
    return  retvalue;//����ԭ��ͷ����ֵ
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
template <class Type> void Queue<Type>::Output() {
	           QueueNode<Type>  *p;
			   p=front;
			   if(front==NULL)
				   cout<<"Empty!"<<endl;
			   else{
				   cout<<"the member in the queue"<<endl;
			     while(front!=NULL)
				  {
			         cout<<GetFront_data()<<"  "<<GetFront_flag()<<endl;
			         front=front->link;
				   }
			   }
			   front=p;
}
template <class Type> void Queue<Type>::Game() {
	QueueNode<Type> *p=front;
	int count=0;
	while(!IsEmpty()){
		if(GetFront_flag()%2!=0){
			cout<<GetFront_data()<<endl;
			DeQueue();
			count++;
		}
		else {
			DeQueue();	
		}
	}
	cout<<"the total number who is up is :"<<count<<endl;
}

template <class Type> void Queue<Type>::Game(int n) {
	Type temp1;
	int count,temp2;
	count=0;
	cout<<"the cards who face up:"<<endl;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j<=n;j++){
			if(j==i-1){
				if(GetFront_flag()%2!=0) {
					cout<<GetFront_data()<<endl;count++;
				}
				DeQueue();		
			}
			else{
				temp1=GetFront_data();
				temp2=GetFront_flag();
				if(temp1%i==0) {DeQueue();EnQueue(j,++temp2);}
				else  {DeQueue();EnQueue(j,temp2);}
			}
		}
		cout<<"the totoal number who face up is   "<<count<<endl;
}

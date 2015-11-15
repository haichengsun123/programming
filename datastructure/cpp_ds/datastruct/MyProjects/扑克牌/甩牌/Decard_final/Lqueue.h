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
	void CreatQueue();
	void Game(int n);
	void Game();
	void DeCard();
	void   DeCard(Queue<Type> &queue);
	void Result();
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
template <class Type> void Queue<Type>::CreatQueue() {// creat an Queue
	cout<<"create a queue"<<endl;
	cout<<"please enter the number of the card:"<<endl;
	int s,j,Flag ;
	Flag=1;
	cin>>s;
	for(j=1;j<=s;j++){
		EnQueue(j,Flag);
	}
	cout<<"OKey"<<endl;
}
template <class Type> void Queue<Type>::Output() {//output an queue
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
template <class Type> void Queue<Type>::DeCard() {//���ƣ�λ�ã��ƺ�
	cout<<endl<<endl;
	int count=1;
	Type temp1;
	int temp2;
	while(!IsEmpty() ){
		cout<<GetFront_data( )<<"   "<<count<<endl;
		DeQueue();
		if(!IsEmpty()){
			temp1=GetFront_data();
			temp2=GetFront_flag();
			DeQueue();
			EnQueue(temp1,temp2);
		}
		count++;
	}
}
template <class Type> void Queue<Type>::DeCard(Queue<Type> &queue) {//����һ���У��Ա�������
	cout<<endl<<endl;
	int count=1;
	Type temp1;
	int temp2;
	while(!IsEmpty() ){
		cout<<GetFront_data( )<<"   "<<count<<endl;
		queue.EnQueue(GetFront_data(),count);
		DeQueue();
		if(!IsEmpty()){
			temp1=GetFront_data();
			temp2=GetFront_flag();
			DeQueue();
			EnQueue(temp1,temp2);
		}
		count++;
	}
}
template <class Type> void Queue<Type>::Result() {

	cout<<"location    "<<"     card"<<endl;
	Type temp1;
	int count=1,temp2;
	while(!IsEmpty() ){
		if(GetFront_data()==count){
			cout<<GetFront_data()<<"                 "<<GetFront_flag()<<endl;
			DeQueue();count++;
		}
		else{		
			temp1=GetFront_data();
			temp2=GetFront_flag();
			DeQueue();
			EnQueue(temp1,temp2);
		}		
	}
}
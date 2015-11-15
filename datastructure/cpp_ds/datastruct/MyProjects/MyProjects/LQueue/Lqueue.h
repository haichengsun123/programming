#include<assert.h>
template <class Type> class Queue;
template <class Type> class QueueNode {
friend class Queue<Type>;
private: 
    Type data;			     //���н������
    QueueNode<Type> *link;    //�����ָ��
public:
    QueueNode ( Type d=0, QueueNode *l=NULL ) : data (d), link (l) { }
};
template <class Type> class Queue {	
private: 
    QueueNode<Type> *front, *rear; //����ָ��
public: 
    Queue ( ) : rear ( NULL ), front ( NULL ) { }
    ~Queue ( );						
    void EnQueue ( const Type & item );//��item���������
    Type DeQueue ( );//ɾ�������ض�ͷԪ��
    Type GetFront ( );//�鿴��ͷԪ��				
    void MakeEmpty ( ); //�ÿն���,ʵ����~Queue( )ͬ
	void Output();
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
template <class Type> void Queue<Type>:: EnQueue ( const Type & item ) {
//����Ԫ��item���뵽���еĶ�β 
    if ( front == NULL )    //��, ������һ�����
	front = rear = new QueueNode<Type> ( item, NULL );
    else                               //���в���, ����
         rear = rear->link = new QueueNode<Type> ( item, NULL );
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
template <class Type> Type Queue<Type>::GetFront() {
//���Ӳ��գ��������ض�ͷԪ�ص�ֵ; 
    assert(!IsEmpty()) ;			
    return front->data;				
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
				     //cout<<"member"<<endl; 
			         cout<<GetFront()<<endl;
			         front=front->link;
				   }
			   }
			   front=p;
}
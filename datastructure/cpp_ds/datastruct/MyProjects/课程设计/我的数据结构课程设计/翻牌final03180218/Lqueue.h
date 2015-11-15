#include<assert.h>
template <class Type> class Queue;
template <class Type> class QueueNode {
friend class Queue<Type>;
private: 
    Type data;	//���н������
	int flag;   //ֽ�Ʊ������Ĵ���
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
	int CreateQueue();
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
template <class Type> void Queue<Type>::Output() {//�������
	QueueNode<Type>  *p;
	p=front;
	if(front==NULL)
		cout<<"Empty!"<<endl;
	else{
		while(front!=NULL)
		{
			cout<<GetFront_data()<<"             "<<GetFront_flag()<<endl;
			front=front->link;
		}
	   }
	   front=p;
}
template <class Type> void Queue<Type>::Game(int n) {//��Ϸ��ÿ���Ʊ������Ĵ�����¼
	int temp2;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++){
			temp2=GetFront_flag();				
			if(GetFront_data()%i==0) {DeQueue();EnQueue(j,++temp2);}
			else{DeQueue();EnQueue(j,temp2);}
		}
		cout<<"ÿ���ƺ��䱻�����Ĵ���Ϊ:"<<endl;
		cout<<"�����"<<"   "<<"�������Ĵ���"<<endl;
		Output();
		cout<<endl;
}
template <class Type> void Queue<Type>::Game() {//��ʾ��Ϸ�����֮�󣬶���Ϊ��
	cout<<"���Ϊ:"<<endl;
	QueueNode<Type> *p=front;
	int count=0;
	while(!IsEmpty()){
		if(GetFront_flag()%2==0){
			cout<<"           "<<GetFront_data()<<endl;
			DeQueue();
			count++;
		}
		else {
			DeQueue();	
		}
	}
	cout<<"���ϵ��Ƶ���ĿΪ :"<<count<<endl<<endl;
}

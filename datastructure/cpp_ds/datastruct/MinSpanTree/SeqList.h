const int DefaultSize=10;
template <class Type> class SeqList {

public:
    SeqList ( const int MaxSize = DefaultSize );
    ~SeqList() { delete[] data; }
    int Length() const { return last + 1; }
    int Find( Type & x ) const;
    int IsIn ( Type & x);
    int Insert ( const Type & x, int i );
	int Insert ( const Type & x );//���뵽���
    int Remove ( Type & x);
    int Next ( Type & x );
    int Prior ( Type & x );
    int IsEmpty() { return last == -1; }
    int IsFull()  { return last == MaxSize - 1; }
    Type Get( int i ) { return i < 0 || i > last ? NULL:data[i]; }
	void Output();
private:
    Type *data;
    int MaxSize;
    int last;
};
template < class Type > SeqList <Type>::SeqList( int sz ) {
    if ( sz > 0 ) {
       MaxSize = sz;  last = -1;
       data = new Type[MaxSize];
    }
}

template < class Type > int SeqList <Type>::Find( Type & x ) const {
    int i = 0;
    while ( i <= last && data[i] != x ) i++;
    if ( i > last ) return -1;
    else return i;
}

template < class Type > int SeqList <Type>::IsIn( Type & x ) {
    int i = 0, found = 0;
    while ( i <= last && !found)
	if ( data[i] != x ) i++;
	else found = 1;
    return found;
}

template < class Type > int SeqList <Type>::Insert( const Type & x, int i ) {
    if ( i < 0 || i > last+1 || last == MaxSize - 1 ) {
		cout<<"the seqlist is full or the index is not proper:"<<endl;
		exit(0);
		return 0;
	}
    else {
	last++;
	for ( int j = last; j > i; j-- ) data[j] = data[j-1];
	data[i] = x;
	return 1;
    }
}
template < class Type > int SeqList <Type>::Insert( const Type & x) {
	if(last==MaxSize-1 ){
		cout<<"the seqlist is full :"<<endl;
		exit(0);
		return 0;

	}
	else{
		last++;
		data[last] = x;
		return 1;


	}
	
}

template < class Type > int SeqList <Type>::Remove( Type & x ) {
    int i = Find(x);
    if ( i >= 0 ) {
	last--;
	for ( int j = i; j <= last; j++ ) data[j] = data[j+1];
	return 1;
    }
}

template < class Type > int SeqList <Type>::Next( Type & x ) {
    int i = Find(x);
    if ( i >= 0 && i < last ) return i+1;
    else return -1;
}

template < class Type > int SeqList <Type>::Prior( Type & x ) {
    int i = Find(x);
    if ( i > 0 && i < last ) return i-1;
    else return -1;
}

template < class Type > void Union( SeqList <Type> & LA, SeqList <Type> & LB ) {
    int n = LA.Length(); int m = LB.Length();
    for ( int i=1; i <= m; i++ ) {
	Type x = LB.Get(i);
	int k = LA.Find(x);
	if ( k == -1 ) { LA.Insert( n+1, x );  n++;}
    }
}

template < class Type > void Intersection ( SeqList <Type> & LA, SeqList <Type> & LB ) {
    int n = LA.Length();  int m = LB.Length();  int i = 1;
    while ( i < n ) {
	Type x = LA.Get(i);
	int k = LB.Find(x);
	if ( k == -1 ) { LA.Remove(i); n--; }
	else i++;
    }
}
template < class Type > void SeqList <Type>::Output() {
	cout<<"the elements  in the seqlist "<<endl;

	for (int i=0;i<=last;i++) {
		cout<<data[i]<<endl;
	}
}



//////////////////////////////////////////////////////////////////////////////
//////////////////////////���е�������ʵ��///////////////////////////////////
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
    //assert(!IsEmpty());	//���в���ʱ����ִ��
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
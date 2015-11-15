template <class Type> class List;//���ǰ�Ӷ���	

template <class Type> class ListNode {   //��������Ķ���
friend class List<Type>;//List�������ඨ��
    Type data;                        //��������� 
    ListNode<Type> *link;    //�������ָ����
public:
    ListNode ( );               //�����㹹�캯�����������ݣ�
    ListNode ( const Type& item );//�����ݵĹ��캯��
    ListNode<Type> *NextNode ( ) { return link; }
    //������ǰ������һ��㣨��ֱ�Ӻ�̣��ĵ�ַ
ListNode<Type> *GetNode ( const Type& item, ListNode<Type> *next ); //��������Ϊitem��ָ��Ϊnext���½��
     void InsertAfter ( ListNode<Type> *p );
      //�ڵ�ǰ�������p��ָ�Ľ��
     ListNode<Type> *RemoveAfter ( );
     //������ժ�µ�ǰ������һ���
};

template <class Type> class List {
    ListNode<Type> *first, *last;//��ͷ����βָ��		
public:
	List ( ) :first(NULL),last(NULL){}
    List ( const Type & value ) 
   { 
        last =first = new ListNode<Type>( value );
    }    	                                  //���캯��
    ~List ( );		            //��������
    void MakeEmpty ( );        //�����ÿ�
    int Length ( ) const;        //��������
   // ListNode<Type> *Find ( Type value ); //�Һ�����value�Ľ��
    ListNode<Type> *Find ( int i ); //������i��Ԫ�صĵ�ַ
	void Createlist( ) ;
    int Insert ( Type value, int i ); //����Ԫ��value�嵽��i��λ��
	void Output();
    Type *Remove ( int i ); //����i��Ԫ��ɾ��
    Type *Get ( int i ); //ȡ����i��Ԫ��
};
template <class Type>ListNode<Type> :: ListNode ( ) : link (NULL) { }//����ʼ��ָ���Ա

template <class Type>ListNode<Type>::ListNode( const Type& item ) :data (item), link (NULL) { } //��ʼ��������ָ���Ա

template <class Type> void ListNode<Type>::InsertAfter ( ListNode<Type> *p )
{ p->link = link;  link = p; }//��Pָ��ָ������뵽��ǰ����

template <class Type> ListNode<Type>*ListNode<Type>::GetNode ( const Type& item,  ListNode<Type> *next = NULL )  {
//�Ը����Ĳ��������½�㣬�����½��ָ��
     ListNode<Type> *newnode =new ListNode<Type> ( item );
      newnode ->link = next;	
      return newnode;
}

template <class Type> ListNode<Type>*ListNode<Type>::RemoveAfter ( ) {
//ժ�µ�ǰ������һ���
ListNode<Type> *tempptr = link;	
     if ( link == NULL ) return NULL;
     //û����һ����򷵻ؿ�ָ��
     link = tempptr->link;	   //��������		
     return tempptr;            
     //������һ����ַ
}

template <class Type> List<Type> :: ~List ( ){
//�������� (����Ĺ�������)
     MakeEmpty ( );  delete first;
     //�����ÿգ���ɾȥ��ͷ���
}
template <class Type> void List<Type> :: MakeEmpty ( ) {
//ɾȥ�����г���ͷ�����������������
    ListNode<Type> *q;
    while ( first->link != NULL ) {
         q = first->link;  first->link = q->link;
         //����ͷ�����һ����������ժ��
         delete q;        //�ͷ��� 
    }
    last = first;         //�޸ı�βָ��
}
template <class Type> int List<Type>::Length ( ) const {
//������ĳ���
     ListNode<Type> *p = first->link;
     //���ָ��pָʾ��һ�����
     int count = 0; 
     while ( p != NULL ) {      //��������
          p = p->link;  count++;
     }			
     return count;
}
/*template <class Type> ListNode<Type>*List <Type>::Find ( Type value ) {
//�������д�ͷ����������ֵΪvalue�Ľ�� 
     ListNode<Type> *p = first->link;
     //���ָ�� p ָʾ��һ�����
     while ( p != NULL && p->data != value )  
	p = p->link;
     return p;  // p �������ɹ�ʱ�����ҵ��Ľ���ַ
                      // p ���������ɹ�ʱ���ؿ�ֵ
}*/
template <class Type> ListNode<Type> *List<Type> :: Find ( int i ) {
//�������д�ͷ������ i ����㣬����ͷ���
     if ( i < -1 ) return NULL;			
     if ( i == -1 ) return first;	         // i Ӧ ? 0
     ListNode<Type> *p = first->link;  
     int j = 0;		
     while ( p != NULL && j < i )          // j = i ͣ
 	  { p = p->link; j++; }	
     return p;				
}
template <class Type> int List<Type> :: Insert ( Type value, int i ) {
//����value����Ԫ�ز��뵽����� i ��λ��
    ListNode<Type> *p = Find ( i-1 );
    // p ָ������� i-1�����
    if ( p == NULL ) return 0;
    ListNode<Type> *newnode =p->GetNode ( value, p->link );//�������
    if ( p->link == NULL ) last = newnode;
    p->link = newnode;                    //��������
    return 1;
}
template <class Type> Type *List<Type>::Remove ( int i ) {
//��������ɾȥ�� i �����
     ListNode<Type> *p = Find (i-1), *q;
     if ( p == NULL || p->link == NULL )
          return NULL;	
     q = p->link;  p->link = q->link;    //��������
     Type *value = new Type ( q->data );
     if ( q == last ) last = p;
     delete q;
     return value;
}
template <class Type> Type *List<Type>::Get ( int i ) {
//��ȡ�� i ����������
     ListNode<Type> *p = Find ( i );
     // p ָ������� i �����
     if ( p == NULL || p == first )
         return NULL;		
     else return p->data;
}
template <class Type> void List<Type>::Createlist( ) {
	cout<<"How many member you will creat in the list"<<endl;
	int m;
	int i;
	Type  n;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"the "<<i+1<<"th member is:"<<endl;
		cin>>n;
        Insert(n,i) ;
	}
	cout<<"OK"<<endl;
}

template <class Type> void List<Type>::Output( ) {
    ListNode<Type> *p ;
	p=first->link;
	if(p==NULL){cout<<"list empty!"<<endl;cout<<last->data;}
	else{
		cout<<"the memeber in the list"<<endl;
		while(p){
			cout<<p->data<<endl;
			p=p->link;
		}
	}
}

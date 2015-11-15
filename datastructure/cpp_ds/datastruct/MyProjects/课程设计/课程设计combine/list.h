class List;//���ǰ�Ӷ���	
class ListNode {   //��������Ķ���
friend class List;//List�������ඨ��
    int data;                        //��������� 
    ListNode *link;    //�������ָ����
public:
    ListNode ( );               //�����㹹�캯�����������ݣ�
    ListNode ( const int& item );//�����ݵĹ��캯��
    ListNode *NextNode ( ) { return link; }
    //������ǰ������һ��㣨��ֱ�Ӻ�̣��ĵ�ַ
    ListNode *GetNode ( const int& item, ListNode *next ); //��������Ϊitem��ָ��Ϊnext���½��
	void InsertAfter ( ListNode *p );
      //�ڵ�ǰ�������p��ָ�Ľ��
     ListNode *RemoveAfter ( );
     //������ժ�µ�ǰ������һ���
};
class List {
    ListNode *first, *last;//��ͷ����βָ��		
public:
	List ( ) :first(NULL),last(NULL){}
    List ( const int & value ) 
   { 
        last =first = new ListNode( value );
    }    	                                  //���캯��
    ~List ( );		            //��������
    void MakeEmpty ( );        //�����ÿ�
    int Length ( ) const;        //��������
    ListNode *Find ( int i ); //������i��Ԫ�صĵ�ַ
	void Createlist( ) ;
    int Insert ( int value, int i ); //����Ԫ��value�嵽��i��λ��
	void Output();
	void Combine(List &hb);
	void Inverse( );
	ListNode * ReturnFirst(){return first->link;}
	ListNode * Return(){return first;};
	ListNode * Return3(){return first->link->link;};
	int Max();
	ListNode *Min_address();
    //Type *Remove ( int i ); //����i��Ԫ��ɾ��
	void Remove(int value);
    int *Get ( int i ); //ȡ����i��Ԫ��
	void sort(List &list);
	void sort_first();
};
ListNode :: ListNode ( ) : link (NULL) { }//����ʼ��ָ���Ա
ListNode::ListNode( const int& item ) :data (item), link (NULL) { } //��ʼ��������ָ���Ա

void ListNode::InsertAfter ( ListNode *p )
{ p->link = link;  link = p; }//��Pָ��ָ������뵽��ǰ����

ListNode *ListNode::GetNode ( const int & item,  ListNode *next = NULL )  {
//�Ը����Ĳ��������½�㣬�����½��ָ��
     ListNode *newnode =new ListNode ( item );
      newnode ->link = next;	
      return newnode;
}

ListNode *ListNode::RemoveAfter ( ) {
//ժ�µ�ǰ������һ���
ListNode *tempptr = link;	
     if ( link == NULL ) return NULL;
     //û����һ����򷵻ؿ�ָ��
     link = tempptr->link;	   //��������		
     return tempptr;            
     //������һ����ַ
}

List :: ~List ( ){
//�������� (����Ĺ�������)
     MakeEmpty ( );  delete first;
     //�����ÿգ���ɾȥ��ͷ���
}
void List:: MakeEmpty ( ) {
//ɾȥ�����г���ͷ�����������������
    ListNode *q;
    while ( first->link != NULL ) {
         q = first->link;  first->link = q->link;
         //����ͷ�����һ����������ժ��
         delete q;        //�ͷ��� 
    }
    last = first;         //�޸ı�βָ��
}
int List::Length ( ) const {
//������ĳ���
     ListNode *p = first->link;
     //���ָ��pָʾ��һ�����
     int count = 0; 
     while ( p != NULL ) {      //��������
          p = p->link;  count++;
     }			
     return count;
}
ListNode *List:: Find ( int i ) {
//�������д�ͷ������ i ����㣬����ͷ���
     if ( i < -1 ) return NULL;			
     if ( i == -1 ) return first;	         // i Ӧ ? 0
     ListNode *p = first->link;  
     int j = 0;		
     while ( p != NULL && j < i )          // j = i ͣ
 	  { p = p->link; j++; }	
     return p;				
}
int List:: Insert ( int value, int i ) {
//����value����Ԫ�ز��뵽����� i ��λ��
    ListNode  *p = Find ( i-1 );
    // p ָ������� i-1�����
    if ( p == NULL ) return 0;
    ListNode *newnode =p->GetNode ( value, p->link );//�������
    if ( p->link == NULL ) last = newnode;
    p->link = newnode;                    //��������
    return 1;
}
void List::Remove(int value){
	ListNode *p=first->link,*q=first;
	if(p==NULL) return ;
	else{
		while(p->data!=value&&p!=NULL) {q=p;p=p->link;}
		if(p==first->link) {
			if(p->link==NULL){first->link=NULL;}
			else{
				first->link=p->link;
			}
		}
		else{
			if(p->link==NULL){
				q->link=NULL;
			}
			else{
				q->link=p->link;
			}
		}
	}

}
void List::Createlist( ) {
	cout<<"How many member you will creat in the list"<<endl;
	int m;
	int i;
	int  n;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"the "<<i+1<<"th member is:"<<endl;
		cin>>n;
        Insert(n,i) ;
	}
	cout<<"OK"<<endl;
}

void List::Output( ) {
    ListNode *p ;
	p=first;
	if(first->link==NULL){cout<<"list empty!"<<endl;cout<<last->data;}
	else{
		p=first->link;
		cout<<"the memeber in the list"<<endl;
		while(p){
			cout<<p->data<<endl;
			p=p->link;
		}
	}
}
int List::Max( ) {
	ListNode *temp;
	temp=first->link; 
	int  max=temp->data;
	while(temp){
		if(temp->data>max){max=temp->data;}
		temp=temp->link;
	}
	return max;
}

void List::Combine(List &hb){
	ListNode *temp,*pa,*pb,*at,*bt;
	if(this->Length ( )<hb.Length()){
		temp=first;
		first=hb.first;
		hb.first=temp;
	}
		at=pa=first->link;bt=pb=hb.first->link;
		while(bt!=NULL){
			pa=at->link;
			pb=bt->link;
			at->link=bt;
			bt->link=pa;
			at=pa;
			bt=pb;
		}
}
void List::sort(List &temp) {
	int count=0;
	int Temp;
	int n=Length();
	for(int i=0;i<n;i++){
		temp.Insert (Max(),count);
		Temp=Max();
		Remove(Temp);
	}
}

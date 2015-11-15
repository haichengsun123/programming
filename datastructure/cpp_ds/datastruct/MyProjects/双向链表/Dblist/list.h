
template <class Type> class DblList;

template <class Type> class DblNode {
friend class DblList<Type>;
private:
    Type data;                                      //����
    DblNode<Type> *lLink, *rLink;   //������ָ��
public:
	DblNode():data(0),lLink(NULL),rLink(NULL){}
    DblNode (Type value,DblNode<Type> *left, DblNode<Type> *right ):data (value), lLink (left), rLink (right) {data =value;lLink =left; rLink =right; } //���캯��
    DblNode (Type value ) : data (value),lLink (NULL), rLink (NULL){ }	//���캯��
};

template <class Type> class DblList {
public:
    DblList ( Type uniqueVal );//���캯��,����ͷ���
    ~DblList ( );//��������:�ͷ����ÿռ�
    int Length ( ) const;
    int IsEmpty ( ) { return first->rLink == first; }//�п�
    int Find ( const Type & target );//�ҵ��ڸ���ֵ�Ľ��
	void FindElement();
    Type getData ( ) const;//���ص�ǰ����ֵ
    void Firster ( ) { current = first; }//��ǰָ��ָ��ͷ���
    int First ( ); //��ǰָ��ָ��ͷ���
    int Next ( ); //��ǰָ��ָ��ǰ����ֱ�Ӻ��
    int Prior ( ); //��ǰָ��ָ��ǰ����ֱ��ǰ��
    int operator ! ( ) { return current != NULL; }//���ز�����:��current�Ƿ�Ϊ��       	
    void Insert ( const Type & value );	//�����½��
	void Insert ();
	void Remove ();
	void RemoveElement();
    void Createlist( ) ;
	void MakeEmpty();
	void Output();
	Type Max();
	void MaxOfAll();
private:
    DblNode<Type> *first, *current;
};
template <class Type>  DblList<Type>::DblList(Type uniqueVal) {
	first=new DblNode<Type>(uniqueVal);
	first->rLink=first->lLink=first;
	current=NULL;
}
template <class Type>  int  DblList<Type>::Find ( const Type & target ) {
//��˫��ѭ��������������target�Ľ�㣬
//�����ɹ�����1�����򷵻�0��
    DblNode<Type> *p = first->rLink;
    while ( p != first && p->data != target )
	  p = p->rLink;	                   //ѭ��������
    if ( p != first ) { current = p;  return 1; }//�ɹ�������1
    return 0;//ʧ�ܣ�����0
} 
template <class Type> void DblList<Type>::Insert ( const Type & value ) {
     if ( current == NULL )          //�ձ�����
         current = first->rLink =new DblNode<Type>(value,first,first );
     else {                                      //�ǿձ�����
         current->rLink =new DblNode<Type>( value, current, current->rLink );
	     current = current->rLink;//�½���Ϊ��ǰ���
     }
     current->rLink->lLink = current;//�����������
}
template <class Type> void DblList<Type>::Insert () {
	Type m,n;
	cout<<"please enter the element you want to insert:";
	cin>>n;
	cout<<"after which element you want to  insert:";
	cin>>m;
	Find(m);
	Insert(n);
}
template <class Type> void DblList<Type>::Remove ( ) {
    if ( current != NULL ) {
        DblNode<Type> *temp = current;         //��ɾ���
        current = current->rLink;	      //��һ���
        current->lLink = temp->lLink;  //������ժ��
        temp->lLink->rLink = current;
        delete temp; 		               //ɾȥ
        if ( current == first )
           if ( IsEmpty ( ) ) current = NULL;
           else  current = current->rLink;
    }
}
template <class Type> void DblList<Type>::MakeEmpty( ) {
	DblNode<Type> *q;
	while(first->rLink!=first){
		q=first->rLink;
		first->rLink=q->rLink;
		delete q;
	}
}
template <class Type> DblList<Type>::~DblList() {
	MakeEmpty();
	delete first;
}
template <class Type> void DblList<Type>::Createlist( ) {
	cout<<"How many member you will creat in the list"<<endl;
	int m;
	int i;
	Type  n;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"the "<<i+1<<"th member is:"<<endl;
		cin>>n;
        Insert(n) ;
	}
	cout<<"OK"<<endl;
}
template <class Type> void DblList<Type>::Output( ) {
	DblNode<Type> *p ;
	p=first->rLink;
	if(p==first){cout<<"list empty!"<<endl;}
	else{
		cout<<"the memeber in the list"<<endl;
		while(p!=first){
			cout<<p->data<<endl;
			p=p->rLink;
		}
	}
}
template <class Type> void DblList<Type>::RemoveElement() {
	Type n;
	cout<<"please enter the element you want to remove:"<<endl;
	cin>>n;
	while(Find(n)==0){
		cout<<"the element you input doesnot exist"<<endl;
		cout<<"please enter the element you want to remove:"<<endl;
		cin>>n;}
	Remove();
}
template <class Type> void DblList<Type>::FindElement(){
	Type n;
	cout<<"enter the element you want to find:"<<endl;
	cin>>n;
	while(Find(n)==0){
		cout<<"the element you want to find doesnot exist."<<endl;
		cout<<"enter the element you want to find:"<<endl;
		cin>>n;
	}
	cout<<"the adress of the element  "<<n<<" is"<<current<<endl;
}
template <class Type> Type DblList<Type>::Max(){
	DblNode<Type> *temp;
	temp=first->rLink; 
	int max=temp->data;
	while(temp!=first){
		if(temp->data>max){max=temp->data;}
		temp=temp->rLink;
	}
	return max;
}
template <class Type> void DblList<Type>::MaxOfAll(){
	cout<<"the max of all the number is :"<<endl;
	cout<<Max()<<endl;
}








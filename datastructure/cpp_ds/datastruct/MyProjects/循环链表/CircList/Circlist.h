enum Boolean{False,True};
template <class Type> class CircList;

template <class Type> class CircListNode {
friend class CircList<Type>;
public:
	CircListNode ( Type d = 0,CircListNode<Type> *next = NULL ) :
                data ( d ), link ( next ) { }    //���캯��
private: 
     Type data;
     CircListNode<Type> *link;
};
template <class Type> class CircList {
public: 
     CircList ( Type value );	  //���캯��
	 CircList ( Type value,CircListNode<Type> *point ):data(value),link(point){}
     ~CircList ( );			//��������	
     int Length ( ) const;      //����������
     int IsEmpty ( ) { return first->link == first; } //�п�
     Boolean Find ( const Type & value );//����
	 Boolean FindBefore(const Type &value);//��ֵΪvalue��ǰһ�����ָ����Ϊcurrent
     Type getData ( ) const;	//���ص�ǰ���ֵ
	 void Firster ( ) { current = first; }//�õ�ǰָ��Ϊͷָ��
	 Boolean First ( ); //����ǰָ��ָ���һ�����
	 Boolean Next ( );//����ǰָ��ָ��ǰ���ĺ��
	 Boolean Prior ( );	//����ǰָ��ָ��ǰ����ǰ��
	 void Insert ( const Type & value );//�����½��
	 void Insert();
	 void Remove ( );	//ɾ����ǰ������һ���
	 void CreatList();
	 void Output();
	 void MakeEmpty();
	 void RemoveElem();//ɾ��ָ���Ľ��
	 void FindElement();
	 Type Max();
	 void MaxOfAll();
private: 
     CircListNode<Type> *first, *current, *last;
};
template <class Type> CircList<Type>::CircList ( Type value ){
	first=last=new CircListNode<Type>(value);
	first->link=first;current=NULL;
}
template <class Type> CircList<Type>::~CircList (){
		MakeEmpty();
		delete first;
}
template <class Type> void CircList<Type>::Insert( const Type &value ){
	if(current==NULL)
		current=first->link=new CircListNode<Type>(value,first);
	else{
		CircListNode<Type> *newnode=new CircListNode<Type>(value,current->link);		
		if(current->link=first) last=newnode;
		current->link=newnode;
		current=current->link;
	}
}
template <class Type> void CircList<Type>::CreatList(){
	Type n;
	int m;
	cout<<"please enter the number of the element you want to creat:"<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"enter the element you want to insert:"<<endl;
		cin>>n;
		Insert(n);
	}
}
template <class Type> void CircList<Type>::Output(){
	CircListNode<Type> *p ;
	p=first->link;
	if(p==first){cout<<"list empty!"<<endl;}
	else{
		cout<<"the memeber in the list"<<endl;
		while(p!=first){
			cout<<p->data<<endl;
			p=p->link;
		}
	}
}
template <class Type> void CircList<Type>::Insert(){
	Type value,elem;
	cout<<"please enter the element you want to insert:"<<endl;
	cin>>value;
	cout<<"after which element you want to insert:"<<endl;
	cin>>elem;
	while(Find(elem)==False){
		cout<<"the element you want to find doesnot exist."<<endl;
		cout<<"enter the element you want to find:"<<endl;
		cin>>elem;
	}
	Insert(value);
}
template <class Type> Boolean CircList<Type>::Find ( const Type & value ){
	CircListNode<Type> *p=first->link;
	while(p!=first&&p->data!=value) p=p->link;
	if(p!=first){current=p;return True;}
	return False;
}
template <class Type> Boolean CircList<Type>::FindBefore( const Type & value ){
	CircListNode<Type> *p=first;
	while(p->link!=first&&p->link->data!=value) p=p->link;
	if(p->link!=first){current=p;return True;}
	return False;
}
template <class Type> void CircList<Type>::Remove ( ){
	if ( current != NULL ) {
        CircListNode<Type> *temp = current,*temp1= current->link;        //
        current = current->link->link;	      //��һ���
		temp->link=current;
        delete temp1; 		               //ɾȥ
        if ( current == first )
           if ( IsEmpty ( ) ) current = NULL;
           else  current = current->link;
    }
}
template <class Type> void CircList<Type>::RemoveElem ( ){
	Type n;
	cout<<"please enter the element you want to remove:"<<endl;
	cin>>n;
	while(FindBefore(n)==False){
		cout<<"the element you input doesnot exist"<<endl;
		cout<<"please enter the element you want to remove:"<<endl;
		cin>>n;}
	Remove();
}
template <class Type> void CircList<Type>::MakeEmpty(){
	CircListNode<Type> *q;
	while(first->link!=first){
		q=first->link;
		first->link=q->link;
		delete q;
	}
}
template <class Type> void CircList<Type>::FindElement(){
	Type n;
	cout<<"enter the element you want to find:"<<endl;
	cin>>n;
	while(Find(n)==False){
		cout<<"the element you want to find doesnot exist."<<endl;
		cout<<"enter the element you want to find:"<<endl;
		cin>>n;
	}
	cout<<"the adress of the element  "<<n<<" is"<<current<<endl;
}
template <class Type> Type CircList<Type>::Max(){
	CircListNode<Type> *temp;
	temp=first->link; 
	int max=temp->data;
	while(temp!=first){
		if(temp->data>max){max=temp->data;}
		temp=temp->link;
	}
	return max;
}
template <class Type> void CircList<Type>::MaxOfAll(){
	cout<<"the max of all the number is :"<<endl;
	cout<<Max()<<endl;
}


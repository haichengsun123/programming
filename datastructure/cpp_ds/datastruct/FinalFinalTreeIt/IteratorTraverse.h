///////////////////////////////////2009.3.8 11////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////ջ��������ʵ��///////////////////////////////////
template <class Type> class Stack;
template <class Type> class StackNode {
friend class Stack<Type>;
private: 
    Type data;	                         //�������	
    StackNode<Type> *link;	       //�����ָ��
public:
    StackNode ( Type d = 0, StackNode<Type> *l = NULL ) : data ( d ), link ( l ) { }
};
template <class Type> class Stack {
private:
    StackNode<Type> *top;       //ջ��ָ��
public:
    Stack ( ) : top ( NULL ) { }
    ~Stack ( );
    void Push ( const Type & item);
    Type Pop ( );
    Type GetTop ( );
    void MakeEmpty ( );         //ʵ����~Stack( )ͬ
    int IsEmpty ( ) const { return top == NULL; }
	void Output();
};
template <class Type> Stack<Type>::~Stack ( ) {
     StackNode<Type> *p;
     while ( top != NULL )      //�������
 	 { p = top;  top = top->link;  delete p; }
}
template <class Type> void Stack<Type>::MakeEmpty( ) {
     StackNode<Type> *p;
     while ( top != NULL )      //�������
 	 { p = top;  top = top->link;  delete p; }
}
template <class Type> void Stack<Type>::Push ( const Type &item ) {
    top = new StackNode<Type> ( item, top );
    //�½������top֮ǰ, ����Ϊ��ջ��
}
template <class Type> Type Stack<Type>::Pop ( ) {//ɾ��ջ����㣬��������ֵ
    assert(!IsEmpty());			
    StackNode<Type> *p = top;
    Type retvalue = p->data;     //�ݴ�ջ������
    top = top->link;       //�޸�ջ��ָ��
    delete p;   return retvalue;   //�ͷ�,��������
}

template <class Type> Type Stack<Type>::GetTop ( ) {
    assert(!IsEmpty());
    return top->data;
}
template <class Type> void  Stack<Type>::Output( ) {			  
               StackNode<Type> *p;
			   p=top;
			   if(top==0)
				   cout<<"Empty"<<endl;
			   else{
			   cout<<"the members in the stack"<<endl; 
			   while(top)
				  {
				     
			         cout<<GetTop()<<endl;
			         top=top->link;
				   }
			   }
			   top=p;
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
//////////////////////////////////////////////////////////////////////////////
//////////////////////////����������ʵ��///////////////////////////////////
template <class Type> class BinaryTree;
template <class Type> class BinTreeNode {
friend class BinaryTree<Type>;
public:
    BinTreeNode ( ) : leftChild (NULL),rightChild (NULL) { }
    BinTreeNode ( Type item, BinTreeNode<Type> *left = NULL,BinTreeNode<Type> *right = NULL ) :data 

(item),leftChild (left), rightChild(right) { }
    Type GetData ( ) const { return data; } //ȡ�ý�������
    BinTreeNode<Type> *GetLeft ( ) const{ return leftChild; } //ȡ�ý������Ůָ��ֵ    
	BinTreeNode<Type> *GetRight( ) const{ return rightChild; } //ȡ�ý������Ůָ��ֵ
    void SetData ( const Type & item ){ data = item; }//�޸Ľ������ֵ
    void SetLeft ( BinTreeNode <Type> *L ){ leftChild = L; }	//�޸Ľ������Ůָ��ֵ
    void SetRight ( BinTreeNode <Type> *R ){ rightChild = R; } //�޸Ľ������Ůָ��ֵ
private:
    BinTreeNode<Type> *leftChild, *rightChild;   //������Ů   
    Type data;   //������
};

template <class Type> class BinaryTree {
public:
    BinaryTree ( ) : root (NULL) { }//���캯��
    BinaryTree ( Type value ) : RefValue (value), root (NULL) { }
	BinaryTree(const BinaryTree<Type> &s){ root=Copy(s.root);}
    ~BinaryTree ( ) { destroy ( root ); }//��������
    int IsEmpty ( ) { return root == NULL ? 1 : 0; }//�п�
    BinTreeNode <Type> *Copy(BinTreeNode <Type>  *orignode);
    BinTreeNode <Type> *Parent (BinTreeNode <Type> *current ) 
	{ return root == NULL || root == current?NULL : Parent ( root, current ); }//����˫�׽���ַ
    BinTreeNode <Type> *LeftChild (BinTreeNode <Type> *current ) //��������Ů����ַ
        { return root != NULL ? current->leftChild : NULL; }
    BinTreeNode <Type> *RightChild (BinTreeNode <Type> *current ) //��������Ů����ַ
        { return root != NULL ? current->rightChild : NULL; }
    void Insert ( const Type & item){Insert(item,root);}//������Ԫ��
	void input();
    int Find ( const Type &item ) const;//����Ԫ��
    const BinTreeNode <Type> *GetRoot ( ) const{ return root; }//ȡ��
    friend istream &operator >> ( istream&in, BinaryTree<Type> &Tree ) ;
    friend ostream &operator << ( ostream&out, BinaryTree <Type> &Tree );
private:
    BinTreeNode <Type> *root;//�������ĸ�ָ��
    Type RefValue;//��������ֹͣ��־������������
    BinTreeNode <Type> *Parent ( BinTreeNode <Type> *start,BinTreeNode <Type> *current );
    void Insert ( const Type &item,BinTreeNode<Type> * &current); 
    void Traverse ( BinTreeNode<Type> *current,ostream &out ) const;
    int Find ( BinTreeNode<Type> *current, const Type &item ) const ;
    void destroy(BinTreeNode<Type> *current);
};
template<class Type> BinTreeNode <Type> * BinaryTree<Type>::Copy(BinTreeNode <Type>  *orignode){
	if(orignode==NULL) return NULL;
	BinTreeNode<Type> *temp=new BinTreeNode<Type>;
	temp->data=orignode->data;
	temp->leftChild=Copy(orignode->leftChild);
	temp->rightChild=Copy(orignode->rightChild);
	return temp;
}
template<class Type> void BinaryTree<Type>:: destroy ( BinTreeNode<Type> *current ) {
    if ( current != NULL ) {
       destroy ( current->leftChild );
       destroy ( current->rightChild );
       delete current;
    }
}
template <class Type> BinTreeNode <Type> * BinaryTree <Type> :: Parent ( BinTreeNode<Type> * start, BinTreeNode 

<Type> *current ) {
     if ( start == NULL ) return NULL;
     if ( start->leftChild == current ||start->rightChild == current )		//�ҵ�
		 return start;	
     BinTreeNode <Type> *p;	//����
     if ( ( p = Parent ( start->leftChild, current ) )
            != NULL ) return p;	//��������������
     else return Parent ( start->rightChild, current );//��������������
}
template <class Type> void BinaryTree<Type> :: Traverse ( 
BinTreeNode <Type> *current, ostream &out ) 
const {
    if ( current != NULL ) {					       
        out << current->data << ' ';//���current������
        Traverse ( current->leftChild, out );//�����������������
        Traverse ( current->rightChild, out ); //�����������������
    }
}
template <class Type> istream & operator >>( istream & in, BinaryTree <Type> &Tree ) {
     Type item;
     cout << "Construct a binary tree: \n ";			    
     cout << "Input data (end with" << Tree.RefValue 
             << " ): ";
     in >> item;		//����				
     while ( item != Tree.RefValue ) {			
		Tree.Insert ( item );
         	cout << "�������� ( �� " << Tree.RefValue  << "���� ):"; 
            in >> item;
    }
    return in;
}
template <class Type> ostream & operator <<
 ( ostream & out, BinaryTree<Type> &Tree ) {
     out << "��������ǰ�����.\n";
     Tree.Traverse ( Tree.root, out );
     out << endl;
     return out;
}



template <class Type> void BinaryTree<Type>::Insert ( const Type &item,BinTreeNode<Type> * &current)
{	
	if(current==NULL)
	{
		current=new BinTreeNode<Type>(item);
		if(current==NULL)
		{
			cout<<"out of space!"<<endl;
			exit(1);
		}
	}
	else if(item<current->data) Insert(item,current->leftChild);
	else if(item>current->data) Insert(item,current->rightChild);
}


template <class Type> void BinaryTree<Type>::input()
{
	cout<<"establish a tree:"<<endl;
	cout<<"input the flag for quiting��"<<endl;
	cout<<"RefValue=";
	cin>>RefValue;
	Type item;
	cout<<"please input the node��";
	cin>>item;
	while(item!=RefValue)
		{
		   Insert(item,root);
		   cout<<"please input the node��";
		   cin>>item;
		}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////�����α�������///////////////////////////////////

template <class Type> class TreeIterator {
	public:
		TreeIterator(){
			T=NULL,current=NULL;
		}
		TreeIterator(BinaryTree<Type> BT):T(BT){
		//	cout<<BT.GetRoot();		
		}
		void Traverse()  ;
		~TreeIterator(){}
	protected:
		BinaryTree<Type> T;
		const BinTreeNode<Type> *current;
	private:
		TreeIterator(const TreeIterator&){}
		TreeIterator &operator=(const TreeIterator &)const;
};

template <class Type> struct StkNode{
	const BinTreeNode<Type>  *Node;
	int PopTim;
	StkNode( const BinTreeNode<Type> *N=NULL):Node(N),PopTim(0){}
};
//////////////////////////////////////////////////////////////////////////////
//////////////////////////���ĺ������������ʵ��///////////////////////////////////
template <class Type> class PostOrder:public TreeIterator<Type>{
	public:
		PostOrder(const BinaryTree<Type> &BT);
		~PostOrder(){}
		void First();
		void Traverse();
	protected:
		Stack<StkNode<Type> >  st;
};

template <class Type> PostOrder<Type>::PostOrder(const BinaryTree<Type> &BT):
   TreeIterator<Type>(BT)
   {
	   BinTreeNode<Type> const *temp=T.GetRoot();
	   if(temp!=NULL){
	   StkNode<Type> yy(temp);
	   st.Push(yy);
	   }
   }


template <class Type> void PostOrder<Type>::First(){
	st.MakeEmpty();
	if(T.GetRoot!=NULL)
	{
		BinTreeNode<Type> const *temp=T.GetRoot();
		if(temp!=NULL){
		StkNode<Type> yy(temp);
		st.Push(yy);
		}
	}
}
template<class Type>void PostOrder<Type>::Traverse()   
 {   
      if(st.IsEmpty())   
      {   
         // if(current==NULL){
		  cout<<"This is an empty tree"<<endl;
		 // exit(1);
		  //}   
          //current=NULL;   
          //return;   
      }  
	  else{
		  StkNode<Type>  Cnode(NULL);   
		  cout<<"This is  the output of PostOrder:"<<endl;
		  while(!st.IsEmpty ()) 
		  {   
			  Cnode=st.Pop();
			  if(++Cnode.PopTim==3){
				  current=Cnode.Node;   
				  cout<<current->GetData()<<endl;		 
				  continue;
			  }   
			  st.Push(Cnode);   
			  if(Cnode.PopTim==1)   
			  {   
				  if(Cnode.Node->GetLeft()!=NULL)   
					  st.Push(StkNode<Type>(Cnode.Node->GetLeft()));   
			  }   
			  else   
			  {   
				  if(Cnode.Node->GetRight()!=NULL)   
					  st.Push(StkNode<Type>(Cnode.Node->GetRight()));   
			  }   
		  }   
  }  
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////�����������������ʵ��///////////////////////////////////
template <class Type> class InOrder : public PostOrder <Type> { 
public: 
    InOrder ( BinaryTree <Type> & BT ):PostOrder <Type> ( BT ) { } 
	~InOrder(){}
    void First ( ); 
    void Traverse();
}; 
template <class Type> void InOrder <Type>::Traverse() { 
    if ( st.IsEmpty ( ) ) {				
		//if ( current == NULL ) 
		//{ 
			cout << "This is an empty tree" << endl; // exit (1); 
	//	} 
		//current = NULL;  return; 
	} 
	else{
		StkNode <Type> Cnode(NULL); 
		cout<<"This is  the output of InOrder:"<<endl;
		while(!st.IsEmpty ()) {     //ѭ��,�������µ���һ����� 
			Cnode = st.Pop();                   //��ջ 
			if ( ++Cnode.PopTim == 2 ) { 
				//���������˳�����Ϊ��ǰ��� 
				current = Cnode.Node; 
				cout<<current->GetData()<<endl;
				if ( Cnode.Node->GetRight ( ) != NULL ) 
				st.Push ( StkNode <Type> (Cnode.Node->GetRight()));    
				continue;
			} 
			st.Push ( Cnode );                  //�����һ��ջ                     
			if ( Cnode.Node->GetLeft ( ) != NULL ) 
				st.Push ( StkNode <Type> (Cnode.Node->GetLeft ())); //����Ů��ջ 		  
		} 
	}
} 


//////////////////////////////////////////////////////////////////////////////
//////////////////////////����ǰ�����������ʵ��///////////////////////////////////
template <class Type> class PreOrder:public PostOrder <Type> { 
	public:
		PreOrder(BinaryTree<Type> &BT):PostOrder <Type> (BT) {}   
		~PreOrder(){}
		void First();
		void Traverse();
};

template <class Type> void PreOrder <Type>::Traverse() { 
	if (st.IsEmpty()){ 
		//if(current==NULL){
			cout<<"This is an empty tree"<<endl; 
			//exit(1);
	//	}
	//	current=NULL;
	
	}
	else{
		StkNode <Type> Cnode(NULL); 
		cout<<"This is  the output of PreOrder:"<<endl;
		do{ 

			Cnode = st.Pop(); 
			current=Cnode.Node;
			cout<<current->GetData()<<endl;
			if( current->GetRight()!=NULL) st.Push(current->GetRight());
			if( current->GetLeft()!=NULL) st.Push(current->GetLeft());
		} while(!st.IsEmpty ());
	}
	
} 

//////////////////////////////////////////////////////////////////////////////
//////////////////////////���Ĳ�α���������ʵ��///////////////////////////////////
template <class Type> class LevelOrder : public TreeIterator <Type> { 
public: 
    LevelOrder ( const BinaryTree <Type> & BT ); 
    ~LevelOrder() {} 
    void First(); 
    void Traverse(); 
protected: 
    Queue < const BinTreeNode <Type> * > qu; 
};

template <class Type> LevelOrder<Type>::LevelOrder(const BinaryTree<Type> &BT):TreeIterator<Type>(BT)
   {
	   BinTreeNode<Type> const *temp=T.GetRoot();
	   if(temp!=NULL)
	   qu.EnQueue (temp);

	   //StkNode<Type> yy(temp);
	   //st.Push(yy);
   }
template <class Type> void LevelOrder<Type> ::Traverse( ) { 
	 if ( qu.IsEmpty ( ) ) { 
		 cout << "This is an empty tree!" << endl;  ;
	 } 
	 else{
		 cout<<"This is  the output of LevelOrder:"<<endl;
		 while(!qu.IsEmpty ( )){
			 //current=Cnode.Node;
			 current = qu.DeQueue ( );  //�˶�    
			 cout<<current->GetData()<<endl;
			 if ( current->GetLeft ( ) != NULL )          //����Ů 
				 qu.EnQueue ( current->GetLeft ( ) );   //������ 
			 if ( current->GetRight ( ) != NULL )        //����Ů 
				 qu.EnQueue ( current->GetRight ( ) ); //������ 
		 }
	 }
} 

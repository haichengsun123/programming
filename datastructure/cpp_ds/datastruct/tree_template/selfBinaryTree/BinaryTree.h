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
    virtual ~BinaryTree ( ) { destroy ( root ); }//��������
    virtual int IsEmpty ( ) { return root == NULL ? 1 : 0; }//�п�
    virtual BinTreeNode <Type> *Parent (BinTreeNode <Type> *current ) 
	{ return root == NULL || root == current?NULL : Parent ( root, current ); }//����˫�׽���ַ
    virtual BinTreeNode <Type> *LeftChild (BinTreeNode <Type> *current ) //��������Ů����ַ
        { return root != NULL ? current->leftChild : NULL; }
    virtual BinTreeNode <Type> *RightChild (BinTreeNode <Type> *current ) //��������Ů����ַ
        { return root != NULL ? current->rightChild : NULL; }
    virtual int Insert ( const Type & item);//������Ԫ��
    virtual int Find ( const Type &item ) const;//����Ԫ��
    const BinTreeNode <Type> *GetRoot ( ) const{ return root; }//ȡ��
    friend istream &operator >> ( istream&in, BinaryTree<Type> &Tree ) ;
    friend ostream &operator << ( ostream&out, BinaryTree <Type> &Tree );
private:
    BinTreeNode <Type> *root;//�������ĸ�ָ��
    Type RefValue;//��������ֹͣ��־������������
    BinTreeNode <Type> *Parent ( BinTreeNode <Type> *start,BinTreeNode <Type> *current );
    int Insert ( BinTreeNode<Type> * &current, const Type &item ); 
    void Traverse ( BinTreeNode<Type> *current,ostream &out ) const;
    int Find ( BinTreeNode<Type> *current, const Type &item ) const ;
    void destroy(BinTreeNode<Type> *current);
};
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

template <class Type>  int BinaryTree<Type> :: Insert ( const Type & item){
	BinTreeNode<Type> *temp;
	temp=root;
	if(temp==NULL){
		temp=new  BinTreeNode<Type>(item);
		if(temp==NULL){cerr<<"Out of space "<<endl; }
	}
	else if(item<temp->data) Insert(item,temp->leftChild);
	  else if (item>temp->data) Insert(item,temp->rightChild);
}


template <class Type> class DblList;

template <class Type> class DblNode {
friend class DblList<Type>;
private:
    Type data;                                      //����
    DblNode<Type> *lLink, *rLink;   //������ָ��
    DblNode ( Type value,DblNode<Type> *left, DblNode<Type> *right ) :
          data (value), lLink (left), rLink (right) { } //���캯��
    DblNode ( Type value ) : data (value),
          lLink (NULL), rLink (NULL),current(NULL){ }	//���캯��
};

template <class Type> class DblList {
public:
    DblList ( Type uniqueVal );//���캯��,����ͷ���
    ~DblList ( );//��������:�ͷ����ÿռ�
    int Length ( ) const;
    int IsEmpty ( ) { return first->rlink == first; }//�п�
    int Find ( const Type & target );//�ҵ��ڸ���ֵ�Ľ��
    Type getData ( ) const;//���ص�ǰ����ֵ
    void Firster ( ) { current = first; }//��ǰָ��ָ��ͷ���
    int First ( ); //��ǰָ��ָ��ͷ���
    int Next ( ); //��ǰָ��ָ��ǰ����ֱ�Ӻ��
    int Prior ( ); //��ǰָ��ָ��ǰ����ֱ��ǰ��
    int operator ! ( ) //���ز�����:��current�Ƿ�Ϊ��
          { return current != NULL; }	
    void Insert ( const Type & value );	//�����½��
    void Remove ( );//ɾ����ǰ���
private:
    DblNode<Type> *first, *current;
};
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
         current = first->rLink =new DblNode ( value, first, first );
     else {                                      //�ǿձ�����
         current->rLink =new DblNode ( value, current, current->rLink );
	     current = current->rLink;//�½���Ϊ��ǰ���
     }
     current->rLink->lLink = current;//�����������
}
template <class Type> void DblList<Type>::Remove ( ) {
    if ( current != NULL ) {
        DblNode *temp = current;         //��ɾ���
        current = current->rLink;	      //��һ���
        current->lLink = temp->lLink;  //������ժ��
        temp->lLink->rLink = current;
        delete temp; 		               //ɾȥ
        if ( current == first )
           if ( IsEmpty ( ) ) current = NULL;
           else  current = current->rLink;
    }
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
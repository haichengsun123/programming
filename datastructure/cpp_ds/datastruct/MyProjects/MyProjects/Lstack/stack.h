#include<assert.h>
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
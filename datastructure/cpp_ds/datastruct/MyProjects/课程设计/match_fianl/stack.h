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
    Type GetTop ( );
	int CreateStack( );
    void MakeEmpty ( );         //ʵ����~Stack( )ͬ
    int IsEmpty ( ) const { return top == NULL; }
	void Output();
	void Match(int flag);
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
template <class Type> int Stack<Type>::CreateStack( ) {
	cout<<"create a stack"<<endl;
				cout<<"end with q:"<<endl;
				char s;
				cin>>s;
				int k;
				k=0;
		        while(s!='q'){			
					Push(s);
					if(s=='(') k++;
					else if(s==')') k--;
					cin>>s;
				}
				if(k==0)     return 1;
				else return 0;
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
			   cout<<"the element  in the stack"<<endl; 
			   while(top)
				  {
				     if(GetTop()=='(') cout<<')';
					 else if(GetTop()==')')  cout<<'(';
					 else cout<<GetTop();
			         top=top->link;
				   }
			   }
			   cout<<endl;
			   top=p;
}
template <class Type> void  Stack<Type>::Match(int flag) {
	cout<<endl;
	if(flag==1)cout<<"match success!"<<endl;
	else       cout<<"match failing!"<<endl;
}

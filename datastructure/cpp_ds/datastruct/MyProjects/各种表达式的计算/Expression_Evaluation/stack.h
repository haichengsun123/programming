#include <assert.h>
template <class Type> class Stack {
public:
    Stack ( int=10 );                              //���캯��
    ~Stack ( ) { delete [ ] elements; }    //��������
    void Push ( const Type & item );   //��ջ
    Type Pop ( );                                   //��ջ
    Type GetTop ( );                             //ȡջ��
    void MakeEmpty ( ) { top = -1; }    //�ÿ�ջ
    int IsEmpty ( ) const { return top == -1; }
    int IsFull ( ) const { return top == maxSize-1; }
    void Output( ) ;	
private:
    int top;	                       //ջ��ָ��
    Type *elements;	     //ջ����		
    int maxSize;	              //ջ�������		
};
template <class Type> Stack<Type>::Stack ( int s ) : top (-1), maxSize (s) {
     elements = new Type[maxSize];	
     assert ( elements != 0 );//����:��̬����ɹ���
}
//��ջδ������Ԫ�ز��뵽ջ�����������
template <class Type> void Stack<Type>::Push ( const Type & item ) {   
    assert ( !IsFull ( ) );	    //�Ⱦ���������
    elements[++top] = item;    //������Ԫ��
}
//��ջ���գ�����ջ��Ԫ�ص�ֵ��ջ��ָ���1
template <class Type> Type Stack<Type>::Pop ( ) {
    assert(!IsEmpty());              //�Ⱦ���������
    return elements[top--];      //����ջ��Ԫ�ص�ֵ��top--
}
template <class Type> Type Stack<Type>::GetTop ( ) {
    assert ( !IsEmpty ( ) );	   //�Ⱦ���������
    return elements[top];         //ȡ��ջ��Ԫ��
}	
template <class Type> void  Stack<Type>::Output( ) {			  
               int temp;
			   temp=top;
			   while(top>-1)
				  {
				     //cout<<"member"<<endl;
			         cout<<GetTop()<<endl;
			         top--;
				   }
			   top=temp;
}
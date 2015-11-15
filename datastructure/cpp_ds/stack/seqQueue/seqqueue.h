#include <assert.h>
template <class Type> class Queue {	
private:
    int rear, front;
    Type *elements;
    int maxSize;
public: 
     Queue ( int=10 );
     ~Queue ( ) { delete [ ] elements; }
     int EnQueue ( const Type & item);
     Type DeQueue ( );
     Type GetFront ( );
     void MakeEmpty ( ) { front = rear = 0; }//��ͷ����βָ����0
     int IsEmpty ( ) const 
        { return front == rear; }//�п�
     int IsFull ( ) const
        { return (rear+1) % maxSize == front; }//����
     int Length ( ) const
        { return (rear-front+maxSize) % maxSize;}
	 void Output();
	//�����Ԫ�ظ���
};
template <class Type> Queue<Type>::Queue ( int sz ) : front (0), rear (0), maxSize (sz) {
    elements = new Type[maxSize];		
    assert ( elements != 0 );
}//����һ��������maxSize��Ԫ�صĿն���
template <class Type> int Queue<Type>::EnQueue ( const Type & item ) {
     //assert ( !IsFull ( ) );					  
   if( IsFull ( ) )
		return 0;
    else{
		rear = (rear+1) % maxSize;			
        elements[rear] = item;	  //������Ԫ��
	    return 1;
	}
}//�����в�������item���뵽��β�����������
template <class Type>
Type Queue<Type>::DeQueue ( ) {
     assert ( !IsEmpty ( ) );				
     front = ( front+1) % maxSize;			
     return elements[front];
}//�����в��գ����ض�ͷԪ�ص�ֵ��ͬʱɾ����Ԫ��
template <class Type> Type Queue<Type>::GetFront ( ) {
     assert ( !IsEmpty ( ) );				
     return elements[( front+1) % maxSize];
}//�����в��գ����ض�ͷԪ�ص�ֵ
template <class Type> void Queue<Type>::Output ( ) {
			  int temp;
			   temp=front;
			   if(front%maxSize==rear)
				   cout<<"Empty!"<<endl;
			   else{
				   cout<<"the member in the queue"<<endl;
			     while(front%maxSize!=rear)
				  {
				     //cout<<"member"<<endl;
			         cout<<GetFront()<<endl;
			         front++;
				   }
			   front=temp;
}
}
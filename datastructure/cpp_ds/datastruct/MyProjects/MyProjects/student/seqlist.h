template <class type>class seqlist
{
private:
   type *data;              //˳���Ĵ������
   int  maxsize;           //˳����������������
   int  last;                  //��ǰ�Ѵ��������λ��
public:
    seqlist(int maxsize);
    ~seqlist(){delete[] data;}
    int  length()const {return last+1;}   //�����
    void  create(int i);
    int find (type &x) const;                //��λ��������x�ڱ��е�λ��
    int  isin (type &x);                        //�ж�X�ڱ��У���find()������
	int getlast(){return last;};
    type getdata(int i){return i<0||i>last?NULL:data[i];}//ȡ����
    int insert(type x,int i);                       //�ڱ��е�i��λ�ô�����X
    int remove(type &x);               //ɾ��X
    int next(){return current<last?&data[++current]:NULL;} //��x�ĺ��
    int prior(){return current>0?&data[--current]:NULL;}  //�ҳ�x��ǰ��
    int isempty(){return last = = -1;}  // �п�
    int isfull(){return last==maxsize-1;}  // ����
};
template<class type> seqlist<type>::seqlist(int sz)
{
    if (sz>0)
       {  maxsize=sz;last=-1;
           data=new type[maxsize];
           if (data==NULL)
              {cerr<<"�ڴ����"<<endl;exit(1);}
         }
}
template<class type>int seqlist<type>::find(type &x)const 
{ 
	int i=0;
	while(i<=last&&data[i]!=x) i++;
	if(i>last) return -1;
	else return i;
}
template<class type>int  seqlist<type>::insert(type x,int i)
{
	if(i<0||i>last+1||last==maxsize-1) return 0;
	else
	{
		last++;
		for(int j=last;j>i;j--) data[j]=data[j-1];
		data[i]=x;return 1;
	}
}
template<class type>void seqlist<type>::create(int i)
{
	type x;
	for(int j=0;j<i;j++)
	{
		cout<<"���ǵ�"<<j+1<<"��"<<endl;
		cin>>x;
		data[j]=x;
		last++;
	}
}
template<class type >int  seqlist<type>::remove(type &x)
{
    int  i=find(x);
    if(i>=0)
	{
	last--;
      for(int j=i;j<=last;j++)data[j]=data[j+1];
     return 1;
      }
   return   0;
}
template<class type >int seqlist<type>::isin(type &x){
	int i=0,found=0;
	while(i<=last&&!=found)
		if(data[j]!=x) i++;
		else found=1;
	return found;
}
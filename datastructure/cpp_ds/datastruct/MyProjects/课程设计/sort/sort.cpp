	
#include"sort.h"

void main()
{
	char ch;
	do{
	 Sort sort;
	 int n;  int *a;
	 cout<<"������Ҫ�Ƚϵ����ֵĸ�����"<<endl;
	 cin>>n;
	 a=new int[n];
	 for(int i=1;i<=n;i++)
	 {
		 cout<<"������Ҫ�μӱȽϵ����֣�"<<endl;
		 cin>>a[i-1];
	 }
	 Datalist M(n,a); 
	 cout<<"*insertsort enter '1'   "<<endl;
	 cout<<"*bubblesort enter '2'   "<<endl;
	 cout<<"*output     enter '3'   "<<endl;
	 cout<<"*������һ�ֱȽ�,enter  '0'"<<endl;
	int j;
	do{
		cout<<"please choose an item��"<<endl;
		cin>>j;  
	   switch(j)
	   { 
	      case 1:
			  sort.insertsort(M);	  
			break;
		  case 2:
			  sort.bubblesort(M);
			  break;
		   case 3:
			   sort.output(M);
			    break;
		   case 4:
			   break;
	   }
	   i=j;
	   }while(i!=0);
	cout<<"continue enter 'y',or else enter 'n'"<<endl;;
	cin>>ch;
	}while(ch=='y');
}
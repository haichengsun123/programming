#include <iostream>  
#include <string>  
using namespace std;  
  
void main(int argc,char* argv[])    
{  
    int i=0;  
    while(i<argc)  
    {  
        cout<<*argv++<<endl;//�����д��cout<<argv[i]<<endl;Ҳ����ȷ��  
        i++;  
    }  
  cin.get();  
	
} 
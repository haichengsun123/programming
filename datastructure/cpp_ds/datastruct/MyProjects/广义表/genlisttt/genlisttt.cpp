#include<iostream.h>
#include<stdlib.h>
//#include"Genlist.h"
#include<string.h>
int sever ( char *str1, char *hstr1 );
int main()
{
	//GenList List;
	char p[30]="(2,('b',7)),(),('d')";
	char hstr1[21];
     //p="((2,('b',7)),(),('d'))";
	 //cout<<strlen(p)<<endl;
	//	p="()";
    //for (int i=0;i<22;i++){
		//cout<<p[i];
//	}
	//char *hstr1=NULL;
	//cout<<sever( p, hstr1 );
	for(int i=0;i<strlen(p);i++){
		cout<<p[i];}
	return 1;
}
int sever ( char *str1, char *hstr1 ) {
//�Բ�����ֽ�����ַ��������һ��Ԫ��
    char ch = str1[0];   
    int n = strlen ( str1 );
    int i = 0,  k = 0;
    //���str1,ɨ���������', '�����������ͣ
    while ( i < n && ( ch != ',' || k != 0 ) ) {
        if ( ch == '(') k++;//���������ԣ������ż�����1
        else if ( ch ==')' ) k--;//���������ţ�������1
        i++;  ch = str1[i];         // i ����, ȡһ�ַ�
    }    
	if ( i<n ) {
        strncpy ( hstr1, str1, i );
        //str1��ǰ i-1 ���ַ����͵�hstr1
		str1[i]='\0';
        strncpy ( str1, str1+i+1, n-i );
        //��n-i���ַ�����str1, ��ȥ��,��
		str1[n-i]='\0';
        return 1;
    }
    else if ( k != 0 ) return 0;   //���Ų���Գ���
           else {	                     //�������
              strcpy ( hstr1, str1 );  *str1 =NULL;
              //str1ȫ�����͸�hstr1
              return 1;
           }
}
	
	
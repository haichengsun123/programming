#include<iostream.h>
#include<stdlib.h>
//#include"Genlist.h"
#include<string.h>
int main()
{
	char p[30]="'b'";
	char hstr1[21];
	char ch=p[0];
	int n=strlen(p);
    int i=0,k=0;
	if (n==0){*hstr1=NULL;// return 0;
	cout<<"hello"<<strlen(hstr1);
	return 0;}
    //���str1,ɨ���������', '�����������ͣ
    while ( i < n && ( ch != ',' || k != 0 ) ) {
        if ( ch == '(') k++;//���������ԣ������ż�����1
        else if ( ch ==')' ) k--;//���������ţ�������1
        i++;  ch = p[i];         // i ����, ȡһ�ַ�
    }    
	if ( i<n ) {
        strncpy ( hstr1, p, i);
		hstr1[i]='\0';
        //str1��ǰ i-1 ���ַ����͵�hstr1
        strncpy ( p, p+i+1, n-i );
		p[n-i]='\0';
        //��n-i���ַ�����str1, ��ȥ��,��
    }
    else if ( k != 0 )  cout<<"return 0"; //return 0;   //���Ų���Գ���
           else {	                     //�������
              strcpy ( hstr1, p);  //p =0;
			  *p=NULL;
              //str1ȫ�����͸�hstr1
           }
		   cout<<strlen(p)<<endl;
		   cout<<strlen(hstr1)<<endl;
		   for (i=0;i<strlen(hstr1);i++){
			   
			   cout<<hstr1[i];}
		   cout<<endl;
		   cout<<strlen(p);
		   for (i=0;i<strlen(p);i++){
			   cout<<"lijieni"<<p[i];}
		   return 0;
}
	

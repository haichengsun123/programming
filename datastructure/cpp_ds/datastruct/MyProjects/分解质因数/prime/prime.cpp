//���������Ż��㷨!  
 

 
//�������ڣ�2004��6��13��  ������cangzhu  ���ߣ�cangzhu  �Ѿ���2955λ���߶������� 
 


////E-mail:cangzhu@163.com

#include "iostream.h"
#include "stdio.h"

void main()
{
 int count=0;
 for(int i=100;i<1000;i++)
 {
  //ż���������������϶���������
  if(i%2==0)
   continue;
  //�ж�3��5��7��9����i/2�Ƿ���i������
  int j=3;
  while(j<=i/2&&i%j!=0)
   j+=2;
  //��������������i�����ӣ���i������
  if(j>i/2)
  {
   //ÿ����� 8 ������ÿ8�������һ�س���
   if(count%8==0)
    cout<<endl;
   //�������
   cout<<i<<"  ";
   count++;
  }
 }
 cout<<endl;
}
 
 

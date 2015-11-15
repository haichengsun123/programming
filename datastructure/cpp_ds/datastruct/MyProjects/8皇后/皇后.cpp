#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
//���ඨ��һ���ڵ㣬����x�����y�����Լ��ýڵ��ֵvalue
class CNode
{
public:
 int x;
 int y;
 int value;
 void SetValue(){value=1;}
 void ClearValue(){value=0;}
};
CNode array[8][8];//����һ��8*8�Ľڵ����
int cnt=0;//����һ��������
//��ӡ����,��ӡ��ʱ�ľ�������
void PrintArray(ofstream& out)
{
 int i,j;
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
   out<<setw(3)<<array[i][j].value;
  }
  out<<endl;
 }
 return;
}
//�ж�a�ڵ��Ƿ���λ��a�ڵ�֮ǰ�Ѵ���������һ�ڵ�λ��ͬһֱ����
int InSameLine(CNode a)
{
 int i,j;
 for(i=0;i<=a.y;i++)
  for(j=0;j<(i<a.y?8:a.x);j++)
  {
   if(array[i][j].value==1)
   {
    if(a.x==array[i][j].x||a.y==array[i][j].y||
    a.x-a.y==array[i][j].x-array[i][j].y||
    a.x+a.y==array[i][j].x+array[i][j].y)
    return 1;
   }
  }
  return 0;
}
//���β������еĽڵ�
void CreateNextNode(int row,ofstream out)
{
 if(row==8)
 {
     out<<"��"<<cnt+1<<"�ֽⷨ"<<endl;
  PrintArray(out);
  cnt++;
  out<<endl;
  return;
 }
 for(int j=0;j<8;j++)
 {
  if(!InSameLine(array[row][j]))
  {
   array[row][j].SetValue();
   CreateNextNode(++row,out);
   array[--row][j].ClearValue();
  }
 }
}
//������main()
void main()
{
 ofstream outfile("c:\\result.txt");
 if(!outfile)
 {
  cout<<"���ļ�ʧ��!"<<endl;
  return;
 }
 int i,j;
    for(i=0;i<8;i++)
  for(j=0;j<8;j++)
  {
   array[i][j].x=j;
   array[i][j].y=i;
   array[i][j].value=0;
  }
 CreateNextNode(0,outfile);
 outfile<<"�ܹ���"<<cnt<<"�ֽⷨ"<<endl;
 outfile.close();
 cout<<"�����ļ����!"<<endl;
 return;
}
 
 

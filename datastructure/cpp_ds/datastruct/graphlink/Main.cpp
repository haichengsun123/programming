#include<iostream.h>
#include <assert.h>
#include"graphLink.h"
//�����ڴ��ͷŵ�
int main()
{
	const int num=9;
	Graph<char,int> graghic(num);
	cout<<endl<<endl<<endl;
	graghic.OutPutEach();///���ÿ�������ֵ
    graghic.BFS(0);
	return 1;
}

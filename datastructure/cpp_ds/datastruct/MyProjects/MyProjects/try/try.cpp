#include <iostream.h>
double Div(double, double );
void main()
{
	try{
		cout <<"7.3/2.0 = " <<Div(7.3, 2.0) <<endl;
		cout <<"7.3/0.0 = " <<Div(7.3, 0.0) <<endl;
		cout <<"7.3/1.0 = " <<Div(7.3, 1.0) <<endl;
	}
	catch(double)
	{
		cout <<"��������Ϊ����쳣\n";
	}
	cout <<"����ִ�гɹ�\n";
}
double Div(double a, double b)
{
	if(b == 1)
		throw b;
	return a/b;
}

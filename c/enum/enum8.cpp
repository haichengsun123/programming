#include<iostream>
using namespace std;

enum color{
		RED=1,
		GREEN=6,
		BLUE=9
};

int main()
{
		enum color v1=RED,v2;
		cout<<"RED="<<RED<<endl;
		cout<<"GREEN="<<GREEN<<endl;
		cout<<"BLUE="<<BLUE<<endl;
		cout<<"v1="<<v1<<endl;
		v2=GREEN;
		cout<<"(v1<v2)="<<(v1<v2)<<endl;
}

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
double Operand1, Operand2, Addition;

Operand1 = atoi( argv[1] );
Operand2 = atoi( argv[2] );
Addition = Operand1 + Operand2;

cout << "\nFirst Number: " << Operand1;
cout << "\nSecond Number: " << Operand2 << endl;
cout << Operand1 << " + " << Operand2 << " = " << Addition << endl;

return 0;
}
/*�����ļ����ر�VC���̣���������������CL 3.cpp�س�����ʱ�������µ�main.exe������������������main 48.52 1205�س�����ῴ���������н����
D:\MyProgram2\AConsoleApp>3  48.52 1205

First Number: 48
Second Number: 1205
48 + 1205 = 1253

D:\MyProgram2\AConsoleApp>
*/
#include <iostream> 
using namespace std; 

enum Letter { A, B, C, D, E }; 

char name[][20] = { 
		"Automobile", 
		"Bank", 
		"Cat", 
		"Day", 
		"eagle" 
}; 

int main() 
{ 
		Letter how; 

		how = A; 
		cout << name[how] << '\n'; 

		how = C; 
		cout << name[how] << '\n'; 

		how = D; 
		cout << name[how] << '\n'; 

		return 0; 
}

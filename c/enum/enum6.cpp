#include <iostream>

enum ERR_CODE { SUCCESS, ERROR };

ERR_CODE f(int, int&, int&);

int main()
{
		int number = 2, squared, cubed;
		ERR_CODE result;

		result = f(number, squared, cubed);

		if (result == SUCCESS)
		{
				std::cout << "SUCCESS!\n";
		}
		else
				std::cout << "Error encountered!!\n";
		return 0;
}

ERR_CODE f(int n, int &rSquared, int &rCubed)
{
		return ERROR;   // simple error code
}

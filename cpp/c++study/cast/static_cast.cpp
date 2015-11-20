//Converts between types using a combination of implicit and user-defined conversions. 

#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;
struct B {};
struct D : B {};

enum class E { ONE, TWO, THREE };   // warning: scoped enums only available with -std=c++11 or -std=gnu++11

enum EU { ONE, TWO, THREE };

int main()
{
	// 1: initializing conversion
	int n = static_cast<int>(3.14); 
	std::cout << "n = " << n << '\n';
	std::vector<int> v = static_cast<std::vector<int> >(10);
	std::cout << "v.size() = " << v.size() << '\n';

	// 2: static downcast
	D d;
	B& br = d; // upcast via implicit conversion
	D& another_d = static_cast<D&>(br); // downcast

	// 3: lvalue to xvalue
	std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
	std::cout << "after move, v.size() = " << v.size() << '\n';

	// 4: discarded-value expression
	static_cast<void>(v2.size());

	// 5. inverse of implicit conversion
	void* nv = &n;
	int* ni = static_cast<int*>(nv);
	std::cout << "*ni = " << *ni << '\n';

	// 6. array-to-pointer followed by upcast
	D a[10];
	B* dp = static_cast<B*>(a);

	// 7. scoped enum to int or float
	E e = E::ONE;
	int one = static_cast<int>(e);

	// 8. int to enum, enum to another enum
	E e2 = static_cast<E>(one);
	EU eu = static_cast<EU>(e2);

	// 9. pointer to member upcast
	// todo

	// 10. void* to any type
	void* voidp = &e;
	std::vector<int>* p = static_cast<std::vector<int>*>(voidp);
}





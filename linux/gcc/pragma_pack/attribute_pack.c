#include <stdio.h>
#include <stddef.h>

// http://stackoverflow.com/questions/8568432/is-gccs-attribute-packed-pragma-pack-unsafe
// stddef 定义 offsetof, 以及 bool变量
//	#include <uapi/linux/stddef.h>
//	
//	enum {
//		false	= 0,
//		true	= 1
//	};
//	#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
//
int main(void)
{
	struct foo {
		int x;
		char c;
	} __attribute__((packed));
	//};
	struct foo arr[2] = { { 'a', 10 }, {'b', 20 } };
	int *p0 = &arr[0].x;
	int *p1 = &arr[1].x;
	printf("sizeof(struct foo)      = %d\n", (int)sizeof(struct foo));
	printf("offsetof(struct foo, c) = %d\n", (int)offsetof(struct foo, c));
	printf("offsetof(struct foo, x) = %d\n", (int)offsetof(struct foo, x));
	printf("arr[0].x = %d\n", arr[0].x);
	printf("arr[1].x = %d\n", arr[1].x);
	printf("p0 = %p\n", (void*)p0);
	printf("p1 = %p\n", (void*)p1);
	printf("*p0 = %d\n", *p0);
	printf("*p1 = %d\n", *p1);


	//struct __attribute__ ((__packed__)) my_unpacked_struct // 导致my_packed_struct 大小为10
	struct my_unpacked_struct  // 导致my_packed_struct大小为13
	{
		char c;
		int i;
	};
	
	struct __attribute__ ((__packed__)) my_packed_struct
	{
		char c;
		int  i;
		struct my_unpacked_struct s;
	};
	printf("sizeof(struct my_packed_struct)      = %d\n", (int)sizeof(struct my_packed_struct));
	printf("offsetof(struct my_packed_struct, c) = %d\n", (int)offsetof(struct my_packed_struct, c));
	printf("offsetof(struct my_packed_struct, i) = %d\n", (int)offsetof(struct my_packed_struct, i));
	printf("offsetof(struct my_packed_struct, s) = %d\n", (int)offsetof(struct my_packed_struct, s));

	//sizeof(struct my_packed_struct)      = 13
	//offsetof(struct my_packed_struct, c) = 0
	//offsetof(struct my_packed_struct, i) = 1
	//offsetof(struct my_packed_struct, s) = 5
	//
	//sizeof(struct my_packed_struct)      = 10
	//offsetof(struct my_packed_struct, c) = 0
	//offsetof(struct my_packed_struct, i) = 1
	//offsetof(struct my_packed_struct, s) = 5
	//

	return 0;
}


// p_jdzxsun@centos7:~/programming/linux/gcc/pragma_pack$ ./attribute_pack
// sizeof(struct foo)      = 8
// offsetof(struct foo, c) = 0
// offsetof(struct foo, x) = 4
// arr[0].x = 10
// arr[1].x = 20
// p0 = 0x7fffe8dd40e4
// p1 = 0x7fffe8dd40ec
// *p0 = 10
// *p1 = 20



// sizeof(struct foo)      = 5
// offsetof(struct foo, c) = 0
// offsetof(struct foo, x) = 1
// arr[0].x = 10
// arr[1].x = 20
// p0 = 0x7fff6bcd2421
// p1 = 0x7fff6bcd2426
// *p0 = 10
// *p1 = 20


void fun() {}
void bar()  {}

extern "C" {
	void chicken() {}
	void egg(){}
}

/* Prevent g and eg from being optimized away. */
void hello() { fun(); egg(); }


// _Z5hellov:
// .LFB4:
// 	.cfi_startproc
// 	pushl	%ebp
// 	.cfi_def_cfa_offset 8
// 	.cfi_offset 5, -8
// 	movl	%esp, %ebp
// 	.cfi_def_cfa_register 5
// 	call	_Z3funv   #  会mangle
// 	call	egg       # 不会mangle
// 	popl	%ebp
// 
int main()
{
	return 0;
}

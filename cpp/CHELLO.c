/*
Viết chương trình in ra màn hình dòng chữ:

Hello PTIT.

Input
Không có dữ liệu vào

Output
Hello PTIT.
*/

int main(void) {

	const char *msg = "Hello PTIT.\n";
	const int len = 12;

	asm(".intel_syntax noprefix;"

	    "mov   rsi, %[message];"
	    "movsx rdx, %[length];"

	    "mov   rax, 1;"
	    "mov   rdi, 1;"

	    "syscall;"

	    ".att_syntax"
	    :
	    : [message] "r"(msg), [length] "r"(len));

	return 0;
}

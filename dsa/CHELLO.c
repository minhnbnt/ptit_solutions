/*
Viết chương trình in ra màn hình dòng chữ:

Hello PTIT.

Input
Không có dữ liệu vào

Output
Hello PTIT.
*/

const char *msg = "Hello PTIT.";

int main(void) {

	asm(".intel_syntax noprefix");

	asm("mov  rax, QWORD PTR msg[rip]");
	asm("mov  rdi, rax");
	asm("call puts");

	asm(".att_syntax");

	return 0;
}

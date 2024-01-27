/*
Viết chương trình in ra màn hình dòng chữ:

Hello PTIT.

Input
Không có dữ liệu vào

Output
Hello PTIT.
*/

const char *msg = "Hello PTIT.\n";
const volatile int len = 12;

int main(void) {

	asm(".intel_syntax noprefix");

	asm("mov   rax, 1");
	asm("mov   rdi, 1");

	asm("mov   rsi, QWORD PTR msg[rip]");
	asm("movsx rdx, DWORD PTR len[rip]");

	asm("syscall");

	asm(".att_syntax");

	return 0;
}

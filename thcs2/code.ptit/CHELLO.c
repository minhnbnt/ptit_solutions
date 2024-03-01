/*
Viết chương trình in ra màn hình dòng chữ:

Hello PTIT.

Input:
Không có dữ liệu vào

Output:
Hello PTIT.
*/

#include <unistd.h>

int main(void) {
	write(STDOUT_FILENO, "Hello PTIT.\n", 13);
	return 0;
}

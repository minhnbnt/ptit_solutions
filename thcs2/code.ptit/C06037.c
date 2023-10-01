/*
Nam viết bảng chữ cái 2 lần lên trên một vòng tròn, mỗi kí tự xuất hiện đúng 2
lần. Sau đó nối lần lượt các kí tự giống nhau lại. Tổng cộng có 26 đoạn thẳng.

Hình vẽ quá chằng chịt, Nam muốn đố các bạn xem có tất cả bao nhiêu giao điểm?

Một giao điểm được tính khi hai đường thẳng của một cặp kí tự cắt nhau.

Input
Gồm một xâu có đúng 52 kí tự in hoa. Mỗi kí tự xuất hiện đúng 2 lần.

Output
In ra đáp án tìm được.

Ví dụ:

Input:
ABCCABDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ

Output:
1
*/

#include <stdio.h>
#include <string.h>

unsigned result = 0;

void generate(char *str, char target) {
	char *p = strchr(str, target);
	char *q = strrchr(str, target);
	if (p == q) ++result;
	*q = *p = 0;
	while (*p == 0) ++p;
	if (*p == '\n') return;
	generate(p, *p);
}

int main(void) {
	char str[100] = { 0 }, *p;
	fgets(str, 100, stdin);
	generate(str, *str);
	printf("%u\n", result / 2);
	return 0;
}

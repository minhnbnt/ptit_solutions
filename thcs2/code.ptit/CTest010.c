/*
Cho một xâu ký tự độ dài không quá 100 chỉ bao gồm các chữ cái in hoa. Người ta
thực hiện mã hóa bằng cách đếm các ký tự cạnh nhau giống nhau và viết số lượng
phía sau các chữ cái đó.

Ví dụ xâu AAECCCCGGGD thì được mã hóa thành A2E1C4G3D1

Với giả thiết không có ký tự nào xuất hiện nhiều hơn 9 lần liên tiếp. Hãy viết
chương trình mã hóa xâu ký tự theo cách như trên.

Input
Dòng đầu ghi số bộ test. Mỗi bộ test ghi xâu chữ cái in hoa không quá 100 ký tự.
Không có ký tự nào xuất hiện nhiều hơn 9 lần liên tiếp.

Output
Với mỗi test ghi ra kết quả mã hóa.

Ví dụ:
Input:
2
AAAAAAAA
AAECCCCGGGD

Output:
A8
A2E1C4G3D1
*/

#include <stdio.h>

int main() {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char c, temp = 0, i = 0;
		while (1) {
			c = getchar();
			if (c != temp) {
				if (i) printf("%c%d", temp, i);
				if (c == '\n') {
					putchar('\n');
					break;
				} else temp = c, i = 1;
			} else i++;
		}
	}
	return 0;
}

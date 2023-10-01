/*
Một xâu đối xứng là một xâu ký tự khác rỗng mà nếu lật ngược xâu ấy ta thu được
xâu ban đầu. Ví dụ các xâu abcba, dd là xâu đối xứng, trong khi các xâu abc,
ptit thì không phải.

Cho một xâu ký tự S. Hãy tìm cách xoá đi nhiều nhất các kí tự của S để thu được
một xâu đối xứng.

Input:
Một dòng duy nhất gồm một xâu kí tự S có độ dài không quá 100000, có thể có
khoảng trống và ký tự đặc biệt.

Output: Số kí tự lớn nhất có thể xóa đi để S là xâu đối xứng.

Ví dụ

Input:
abccba

Output:
5
*/

#include <stdio.h>

int main() {
	unsigned long result = 0;
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		result++;
	}
	printf("%lu\n", --result);
	return 0;
}

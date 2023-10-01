/*
Viết chương trình tính ước số chung lớn nhất của 2 số nguyên dương (không quá 6
chữ số).

Input
Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng hai số nguyên
dương.

Output
Mỗi bộ test ghi ra kết quả tính được trên một dòng.

Ví dụ
Input:
2
24 14
75 125

Output:
2
25
*/

#include <stdio.h>

int main() {
	unsigned n;
	scanf("%u", &n);
	while (n--) {
		unsigned long a, b;
		scanf("%ld %ld", &a, &b);
		while (a - b)
			if (a > b) a -= b;
			else b -= a;
		printf("%ld\n", a);
	};
	return 0;
}

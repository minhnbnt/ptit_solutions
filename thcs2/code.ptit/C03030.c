/*
Một số gọi là số không giảm nếu các chữ số từ trái qua phải tạo thành dãy không
giảm (tức là không có chữ số nào phía sau nhỏ hơn chữ số ngay trước nó). Viết
chương trình liệt kê các số không giảm có N chữ số (1<N<7).

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi số N

Output
Với mỗi bộ test, ghi ra lần lượt các số không giảm có N chữ số, các số cách nhau
một khoảng trống. Hết một bộ test thì xuống dòng.

Ví dụ:
Input:
1
2

Output:
11 12 13 14 15 16 17 18 19 22 23 24 25 26 27 28 29 33 34 35 36 37 38 39 44 45 46
47 48 49 55 56 57 58 59 66 67 68 69 77 78 79 88 89 99
*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int nums, i, j;
	while (n--) {
		scanf("%d", &nums);
		char a[nums];
		for (i = 0; i < nums; i++) a[i] = 1;
		while (a[0] < 10) {
			for (i = 0; i < nums; i++)
				if (a[i] > 9) {
					for (j = nums - 1; j >= i; j--) {
						a[j] = a[i - 1];
					}
					break;
				}
			for (i = 0; i < nums; i++) {
				printf("%d", a[i]);
			}
			putchar(' '), ++a[nums - 1];
			for (i = nums - 1; i > 0; i--)
				if (a[i] > 9) a[i - 1]++;
		};
		putchar('\n');
	};
	return 0;
}

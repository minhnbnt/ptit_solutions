/*
Một số nguyên dương được gọi là số không giảm nếu các chữ số từ trái qua phải
tạo thành dãy không giảm. Ví dụ số số 123 là số không giảm, số 121 không phải.

Viết chương trình kiểm tra một số có phải số không giảm hay không.

Input
Dòng đầu ghi số bộ test, mỗi bộ test ghi một số nguyên dương không quá 18 chữ số

Output
Với mỗi bộ test, nếu đúng ghi ra YES, nếu sai ghi ra NO.

Ví dụ:
Input:
2
1234567890676543
11223334445555689

Output:
NO
YES
*/

#include <stdio.h>

char no_decrease(unsigned long long n) {
	char before = n % 10, after;
	while (n /= 10) {
		after = n % 10;
		if (before < after) return 0;
		before = after;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	char result[n];
	for (int i = 0; i < n; i++) {
		unsigned long long num;
		scanf("%llu", &num);
		result[i] = no_decrease(num);
	}
	for (int i = 0; i < n; i++) {
		puts(result[i] ? "YES" : "NO");
	}
	return 0;
}

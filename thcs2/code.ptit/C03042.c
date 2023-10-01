/*
Một số gọi là số giảm nếu các chữ số từ trái qua phải tạo thành dãy giảm (tức là
chữ số phía sau nhỏ hơn chữ số ngay trước). Viết chương trình đếm các số giảm có
trong đoạn [a,b].

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi 2 số a,b (1<a<b<10^8)

Output
Với mỗi bộ test, ghi ra số lượng các số giảm đếm được.

Ví dụ:
Input:
1
10 100

Output:
45
*/

#include <stdio.h>

char decrease_number(long n) {
	char a = n % 10, b;
	while (n /= 10) {
		b = n % 10;
		if (a >= b) return 0;
		a = b;
	}
	return 1;
}

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		long a, b, i, count = 0;
		scanf("%ld %ld", &a, &b);
		for (i = a; i <= b; i++) {
			count += decrease_number(i);
		}
		printf("%ld\n", count);
	}
	return 0;
}

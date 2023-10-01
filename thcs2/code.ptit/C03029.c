/*
Một số gọi là số chẵn đặc biệt nếu nó là số chẵn và tất cả các chữ số đều chẵn.
Viết chương trình kiểm tra xem số đã cho có phải là số chẵn đặc biệt hay không.

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi số N không quá 18 chữ số

Output
Với mỗi bộ test, nếu N là số chẵn đặc biệt thì ghi ra YES, ngược lại ghi ra NO
trên một dòng.

Ví dụ:
Input:
2
123456
22446688000000

Output:
NO
YES
*/

#include <stdio.h>

char *special_even(long long n) {
	while (n) {
		if (n % 2) return "NO";
		n /= 10;
	};
	return "YES";
}

int main() {
	unsigned n;
	scanf("%u", &n);
	while (n--) {
		long long x;
		scanf("%lld", &x);
		puts(special_even(x));
	};
	return 0;
}

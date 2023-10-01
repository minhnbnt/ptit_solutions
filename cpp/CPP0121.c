/*
Thấy Tí rất thích thú với những con số, cô giáo đã giao cho Tí một bài tập về
rút gọn các con số. Phép rút gọn được thực hiện như sau: từ một số ban đầu, số
mới được tạo thành bằng cách cộng các chữ số của số ban đầu với nhau. Sau đó Tí
phải thực hiện tiếp tục với con số vừa mới thu được.

Quá trình rút gọn kết thúc khi số thu được chỉ có duy nhất 1 chữ số.

Các bạn hãy cùng Tí đi tìm chữ số cuối cùng của phép rút gọn!

Input:
Dòng đầu tiên gồm số lượng test T (T <= 100).

T dòng tiếp theo, mỗi dòng gồm một số nguyên dương (<= 10^9).

Output:
Hãy in ra chữ số cuối cùng sau khi thực hiện phép rút gọn.

Example
Input:
3
1009
167
102

Output:
1
5
3
*/

#include <stdio.h>

#define u64 unsigned long long

u64 gcd(u64 a, u64 b) {

	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;

	return a + b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 a, b;

		scanf("%llu%llu", &a, &b);

		u64 g = gcd(a, b);

		printf("%llu %llu\n", a * b / g, g);
		fflush(stdout);
	}

	return 0;
}

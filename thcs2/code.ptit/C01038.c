/*
Cho một số nguyên dương n không quá 9 chữ số.

Hãy thực hiện đổi vị trí của chữ số đầu tiên và chữ số cuối cùng.
Lưu ý trong trường hợp chữ số cuối cùng là 0 thì khi đổi chỗ sẽ được loại bỏ (ví
dụ 9800 -> 809)

Input

Chỉ có một số nguyên dương N không quá 9 chữ số.

Output

Ghi ra kết quả trên một dòng

Ví dụ
Input
1234

Output:
4231
*/

#include <stdio.h>

int main() {
	long n, i = 1;
	scanf("%ld", &n);
	long temp = n;
	char first, last = n % 10;
	while (n > i) {
		first = temp % 10;
		temp /= 10;
		i *= 10;
	}
	temp = (last - first) * i / 10 - last + first + n;
	printf("%ld\n", temp);
	return 0;
}

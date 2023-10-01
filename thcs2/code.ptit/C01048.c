/*
Cho số nguyên dương N không quá 9 chữ số.

Hãy đếm xem N có bao nhiêu chữ số lẻ và bao nhiêu chữ số chẵn. Nếu không tồn tại
số lẻ hoặc số chẵn thì in ra kết quả là 0 cho loại số tương ứng

Input
Chỉ có một dòng ghi số N

Output
Ghi số chữ số lẻ rồi đến số chữ số chẵn

Ví dụ:
Input:
12345678

Output:
4 4
*/

#include <stdio.h>

int main() {
	long a;
	scanf("%ld", &a);
	int odd = 0, even = 0;
	while (a) {
		a % 2 ? odd++ : even++;
		a /= 10;
	};
	printf("%d %d\n", odd, even);
	return 0;
}

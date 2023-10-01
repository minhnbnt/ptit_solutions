/*
Nhập một số nguyên dương N không quá 9 chữ số. Hãy đếm xem N có bao nhiêu chữ số
lẻ và bao nhiêu chữ số chẵn.

Input

Dòng đầu của dữ liệu vào ghi số bộ test, mỗi bộ test ghi trên một dòng một số
nguyên cần kiểm tra.

Output

Kết quả in ra trên một dòng lần lượt là số chữ số lẻ và số chữ số chẵn, cách
nhau một khoảng trống.

Ví dụ
Input:
2
1234
4444444

Output:
2 2
0 7
*/

#include <stdio.h>

int main() {
	unsigned n;
	scanf("%d", &n);
	int odd[n], even[n];
	for (int i = 0; i < n; i++) {
		long a;
		odd[i] = even[i] = 0;
		scanf("%ld", &a);
		while (a) {
			a % 2 ? odd[i]++ : even[i]++;
			a /= 10;
		};
	};
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", odd[i], even[i]);
	}
	return 0;
}

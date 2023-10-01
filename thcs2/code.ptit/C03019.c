/*
Một số được coi là đẹp nếu nếu nó có tính chất thuận nghịch và tổng chữ số chia
hết cho 10.  Bài toán đặt ra là cho trước số chữ số. Hãy đếm xem có bao nhiêu số
đẹp với số chữ số như vậy.

Dữ liệu vào: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng số chữ
số tương ứng cần kiểm tra (lớn hơn 1 và nhỏ hơn 10).

Kết quả: Mỗi bộ test viết ra số lượng số đẹp tương ứng.

Ví dụ:

Input:
2
2
5

Output:
1
90
*/

#include <stdio.h>

int main() {
	unsigned n;
	scanf("%u", &n);
	int result[n], x, i;
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x % 2) {
			x /= 2, result[i] = 9;
			while (--x) result[i] *= 10;
		} else {
			char flag = 1;
			result[i] = 1, x /= 2;
			while (--x)
				if (flag) result[i] *= 18, flag = 0;
				else result[i] *= 10;
		};
	};
	for (i = 0; i < n; i++) printf("%d\n", result[i]);
	return 0;
}

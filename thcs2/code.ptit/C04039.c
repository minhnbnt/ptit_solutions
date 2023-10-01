/*
Xét việc di chuyển từ điểm nguyên này tới điểm nguyên khác trên  đường thẳng
theo quy tắc sau:

Bắt đầu từ một điểm có toạ độ nguyên,
Từ điểm hiện tại tới điểm mới với bước đi không âm, độ dài bằng bước đi trước
hoặc khác 1 đơn vị.

Yêu cầu: Cho 2 số nguyên x và y (0 ≤ x ≤ y ≤ 2^31). Hãy xác định số bước tối
thiểu đi từ x tới y với với bước đi ban đầu và bước đi cuối cùng đều có độ
dài 1.

Ví dụ, với x = 45, y = 40, số bước di chuyển tối thiểu là 4:
45 -> 46 -> 48 -> 49 -> 50

Input
Gồm nhiều dòng, mỗi dòng ghi hai số x, y. Cần đọc đến hết luồng dữ liệu vào.

Output
Mỗi dòng ghi kết quả của bộ test tương ứng

Ví dụ:
Input:
0  6
14 19
2  5

4
4
3
*/

#include <stdio.h>

unsigned long long range(unsigned long step) {
	static unsigned long long tmp[100000] = { 0 };
	if (step == 0) return 0;
	else if (tmp[step] == 0) {
		tmp[step] = range(step - 1) + step;
	}
	return tmp[step];
}

int main(void) {
	unsigned long long a, b;
	while (scanf("%llu %llu", &a, &b) != EOF) {
		if (a > b) {
			unsigned long long tmp = a;
			a = b, b = tmp;
		}
		unsigned long step = 0, count = 0;
		while (a + range(++step) <= b) {
			a += step, ++count;
		}
		while (a != b && step > 0) {
			while (a + range(step) <= b) {
				a += step, ++count;
			}
			--step;
		}
		printf("%lu\n", count);
	}
	return 0;
}

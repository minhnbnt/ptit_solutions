/*
Cho một bảng hình chữ nhật kích thước vô hạn. Ban đầu, tất cả các ô đều có giá
trị bằng 0.

Có N phép thực hiện, mỗi bước, bạn được phép tăng giá trị của hình chữ nhật con
từ ô (1, 1) tới ô (a, b) lên 1 đơn vị.

Sau N bước, số lớn nhất trong bảng là X. Nhiệm vụ của bạn là hãy đếm số lần xuất
hiện của X?

Input:
Dòng đầu tiên là số nguyên N (1 ≤ N ≤ 100).
N dòng tiếp theo, mỗi dòng gồm 2 số nguyên a và b mô tả một bước (1 ≤ a, b ≤
10^6).

Output:
In ra số lần xuất hiện của số lớn nhất trong bảng.

Ví dụ:
Input:
3
2 3
3 7
4 1
Output:
2
*/

#include <stdio.h>

int main(void) {
	unsigned cases;
	scanf("%u", &cases);
	unsigned long min_x = __UINT32_MAX__, min_y = __UINT32_MAX__;
	while (cases--) {
		unsigned long x, y;
		scanf("%lu %lu", &x, &y);
		if (x < min_x) min_x = x;
		if (y < min_y) min_y = y;
	}
	printf("%llu\n", (long long)min_x * min_y);
	return 0;
}

/*
Có N (1≤N≤25000) người leo lên và leo xuống trên 1 ngọn núi. Người i mất U(i)
thời gian leo lên và D(i) thời gian để leo xuống. Trong một thời điểm chỉ có tối
đa người 1 người có thể lên và tối đa 1 người có thể xuống (có thể 1 người lên,
1 người xuống). Những người khác có thể đứng chờ ở đỉnh ngọn núi. Thứ tự đi
xuống có thể khác thứ tự đi lên. Bạn hãy xác định xem thời gian tối thiểu để cho
N người lên và xuống ngọn núi là bao nhiêu.

Input: Dòng 1 ghi số N. N dòng tiếp theo chứa 2 số U(i) và D(i) (1 ≤ U(i) , D(i)
≤ 50000)
Output:Ghi ra thời gian tối thiểu có thể.

Ví dụ: (Giải thích: đi lên và xuống theo thứ tự người 3->1->2)

Input:
3
6 4
8 1
2 3

Output:
17
*/

#include <stdio.h>

typedef struct {
	unsigned up;
	unsigned down;
} guy;

int main(void) {
	unsigned n, i, j;
	scanf("%u", &n);
	guy a[n];
	long sum_up = 0, sum_down = 0;
	unsigned min_up = __UINT16_MAX__, min_down = __UINT16_MAX__;
	for (i = 0; i < n; i++) {
		scanf("%u %u", &a[i].up, &a[i].down);
		sum_up += a[i].up, sum_down += a[i].down;
		if (a[i].up < min_up) min_up = a[i].up;
		if (a[i].down < min_down) min_down = a[i].down;
	}
	sum_up += min_down, sum_down += min_up;
	printf("%ld\n", sum_up > sum_down ? sum_up : sum_down);
	return 0;
}

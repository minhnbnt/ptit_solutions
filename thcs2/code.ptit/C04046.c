/*
Thành phố X có N thị trấn trên trục đường chính. Tọa độ của các thị trấn lần
lượt là a[1], a[2], …, a[N], các tọa độ này là phân biệt, không có 2 tọa độ nào
trùng nhau.

Chính quyền thành phố muốn xây dựng một tuyến buýt nhanh BRT để kết nối 2 thị
trấn gần nhau nhất với nhau.

Bạn hãy tính thử xem chiều dài của tuyến buýt này bằng bao nhiêu? Và có bao
nhiêu cặp thị trấn có tiềm năng giống nhau để xây dựng tuyến BRT này.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test bắt đầu bằng số nguyên N (N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (-10^9 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test in ra 2 số nguyên C và D, lần lượt là khoảng cách ngắn nhất giữa 2
thị trấn, và số lượng cặp thị trấn có cùng khoảng cách ngắn nhất này.

Ví dụ:
Input:
2
4
6 -3 0 4
3
-2 0 2

Output:
2 1
2 2
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { //
	return *(long *)a > *(long *)b;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i, j;
		scanf("%u", &ele);
		if (!ele) continue;
		long arr[ele], *min = arr;
		for (i = 0; i < ele; i++) scanf("%ld", &arr[i]);
		qsort(arr, ele, sizeof(long), cmp);
		for (i = 0; i < ele - 1; i++) {
			arr[i] = arr[i + 1] - arr[i];
			if (arr[i] < *min) min = &arr[i];
		}
		unsigned count = 0;
		for (i = 0; i < ele - 1; i++)
			if (arr[i] == *min) count++;
		printf("%ld %u\n", *min, count);
	}
	return 0;
}

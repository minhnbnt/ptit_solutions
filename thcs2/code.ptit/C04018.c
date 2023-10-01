/*
Viết chương trình đếm các cặp số bằng nhau liên tiếp trong dãy số nguyên.

Input: Dòng đầu tiên ghi số bộ test. Mỗi bộ test có hai dòng:

Dòng đầu ghi số phần tử của dãy, không quá 30

Dòng tiếp theo ghi các phần tử của dãy, mỗi phần tử cách nhau một khoảng trống.
Các phần tử không quá 100.

Output: Mỗi bộ test viết ra trên một dòng giá trị
tổng chữ số tương ứng

Ví dụ:
Input:
2
4
1 3 3 4
12
1 2 3 3 3 3 4 4 5 5 5 1

Output:
1
6
*/

#include <stdio.h>

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		int ele, i, j;
		scanf("%d", &ele);
		int arr[ele], result = 0;
		for (i = 0; i < ele; i++) {
			scanf("%u", &arr[i]);
			if (arr[i] == arr[i - 1]) result++;
		};
		printf("%d\n", result);
	};
	return 0;
}

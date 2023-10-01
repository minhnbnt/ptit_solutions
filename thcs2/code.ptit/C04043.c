/*
Theo định lý Pytago, ta đã biết một bộ 3 số (a, b, c) thỏa mãn  a2 + b2 = c2 thì
đó là ba cạnh của một tam giác vuông.

Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là kiểm tra xem có tồn tại bộ
ba số thỏa mãn là ba cạnh của tam giác vuông hay không.

Dữ liệu vào:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N (1≤ N ≤5000).
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).

Kết quả:
Với mỗi test, in ra trên một dòng “YES” nếu tìm được, và “NO” trong trường hợp
ngược lại.

Ví dụ:

Input:
2
5
3 1 4 6 5
3
1 1 1

Output:
YES
NO
*/

#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long

int cmp(const void *a, const void *b) { //
	return *(ull *)a > *(ull *)b;
};

int right_triangle(ull *arr, unsigned ele) {
	qsort(arr, ele, sizeof(ull), cmp);
	unsigned large = ele - 1;
	while (large > 1) {
		unsigned left = 0, right = large - 1;
		while (left != right)
			if (arr[large] > arr[left] + arr[right]) --left;
			else if (arr[large] < arr[left] + arr[right]) --right;
			else return 1;
		--large;
	}
	return 0;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i;
		scanf("%u", &ele);
		ull arr[ele];
		unsigned long edge;
		for (i = 0; i < ele; i++) {
			scanf("%lu", &edge);
			arr[i] = edge * edge;
		}
		puts(right_triangle(arr, ele) ? "YES" : "NO");
	}
	return 0;
}

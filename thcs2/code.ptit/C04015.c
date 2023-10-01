/*
Cho dãy số A có n phần tử chỉ bao gồm các số nguyên dương (không quá 105). Hãy
đếm xem mỗi số xuất hiện bao nhiêu lần.

Input: Dòng đầu tiên ghi số bộ test. Với mỗi bộ test: dòng đầu ghi số n (không
quá 100); dòng tiếp theo ghi n số của dãy.

Output: Với mỗi bộ test ghi ra thứ tự bộ test, sau đó lần lượt là các số nguyên
tố trong dãy theo thứ tự xuất hiện trong dãy và số lần xuất hiện của nó.

Ví dụ:
Input:
1
10
1 7 2 8 3 3 2 1 3 2

Output:
Test 1:
1 xuat hien 2 lan
7 xuat hien 1 lan
2 xuat hien 3 lan
8 xuat hien 1 lan
3 xuat hien 3 lan
*/

#include <stdio.h>

int main() {
	unsigned test, k;
	scanf("%u", &test);
	for (k = 1; k <= test; k++) {
		printf("Test %d:\n", k);
		unsigned ele, i, j;
		scanf("%u", &ele);
		int arr[ele], app[ele];
		for (i = 0; i < ele; i++) {
			app[i] = 1;
			scanf("%d", &arr[i]);
			for (j = 0; j < i; j++)
				if (arr[i] == arr[j]) {
					app[i] = 0, app[j]++;
					break;
				};
		}
		for (i = 0; i < ele; i++)
			if (app[i]) //
				printf("%d xuat hien %d lan\n", arr[i], app[i]);
	}
	return 0;
}

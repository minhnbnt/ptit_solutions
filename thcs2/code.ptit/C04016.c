/*
Cho dãy số A có n phần tử chỉ bao gồm các số nguyên dương (không quá 105). Hãy
xác định các số nguyên tố trong dãy và đếm xem mỗi số xuất hiện bao nhiêu lần.

Input: Dòng đầu tiên ghi số bộ test. Với mỗi bộ test: dòng đầu ghi số n (không
quá 100); dòng tiếp theo ghi n số của dãy.

Output: Với mỗi bộ test ghi ra thứ tự bộ test, sau đó lần lượt là các số nguyên
tố trong dãy theo thứ tự từ nhỏ đến lớn và số lần xuất hiện của nó.

Ví dụ:
Input:

1
10
1 7 2 8 3 3 2 1 3 2

Output:
Test 1:
2 xuat hien 3 lan
3 xuat hien 3 lan
7 xuat hien 1 lan
*/

#include <math.h>
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b, *b = temp;
}

int main() {
	unsigned test, k;
	scanf("%u", &test);
	for (k = 1; k <= test; k++) {
		printf("Test %d:\n", k);
		unsigned ele, i, j;
		scanf("%u", &ele);
		int arr[ele], app[ele], max;
		for (i = 0; i < ele; i++) {
			app[i] = 1;
			scanf("%d", &arr[i]);
			for (j = 0; j < i; j++)
				if (arr[i] == arr[j]) {
					app[i] = 0, app[j]++;
					break;
				};
		};
		for (i = 0; i < ele; i++)
			for (j = i + 1; j < ele; j++)
				if (arr[i] > arr[j]) {
					swap(&arr[i], &arr[j]);
					swap(&app[i], &app[j]);
				}
		char prime[max + 1];
		prime[0] = prime[1] = 0, prime[2] = 1, max = arr[ele - 1];
		for (i = 3; i <= max; i++) prime[i] = 1;
		for (i = 2; i <= sqrt(max); i++)
			if (prime[i])
				for (j = 2 * i; j <= max; j += i) prime[j] = 0;
		for (i = 0; i < ele; i++)
			if (app[i] && prime[arr[i]])
				printf("%d xuat hien %d lan\n", arr[i], app[i]);
	}
	return 0;
}

/*
Viết chương trình tìm số lớn nhất trong một dãy số cho trước.

Input: Dòng đầu ghi số bộ test. Mỗi test gồm 2 dòng, dòng đầu ghi số N là số
phần tử của dãy. Dòng sau ghi N số của dãy. N không quá 100, các số trong dãy
đều nguyên dương và không quá 1000.

Output: Với mỗi bộ test ghi trên hai dòng:

Dòng thứ nhất là giá trị số lớn nhất
Dòng thứ 2 lần lượt là các vị trí trong dãy có giá trị lớn nhất (chỉ số tính từ
0).

Ví dụ:
Input:
1
7
3 5 9 8 4 2 9

Output:
9
2 6
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		int n, x, max = -__INT16_MAX__, *index, size = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if (x > max) {
				max = x, size = 1, free(index);
				index = malloc(sizeof(int));
				index[0] = i;
			} else if (x == max) {
				index = realloc(index, sizeof(int) * ++size);
				index[size - 1] = i;
			}
		};
		printf("%d\n", max);
		for (int i = 0; i < size; i++) printf("%d ", index[i]);
		putchar('\n');
	};
	return 0;
}

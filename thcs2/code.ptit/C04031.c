/*
Một đoạn tăng trong một dãy số nguyên là một đoạn liên tiếp trong dãy sao cho
phần từ phía sau lớn hơn phần từ phía trước. Cho dãy số với n phần tử (n không
quá 100, các phần tử đều không quá 1000). Viết chương trình tìm các đoạn tăng
liên tiếp trong dãy mà số phần tử là nhiều nhất.

Input: Dòng đầu ghi số bộ test. Mỗi test gồm 2 dòng, dòng đầu ghi số N là số
phần tử của dãy. Dòng sau ghi N số của dãy. N không quá 100, các số trong dãy
đều nguyên dương và không quá 1000.

Output: Với mỗi bộ test, ghi ra thứ tự bộ test. Sau đó là 1 dòng ghi độ dài của
đoạn tăng dài nhất. Tiếp theo là một số dòng ghi lần lượt các đoạn tăng dài
nhất, từ trái qua phải trong dãy ban đầu.

Ví dụ:

Input
2
16
2 3 5 7 4 5 8 9 7 11 8 9 6 7 10 12
12
2 3 2 3 2 3 2 2 2 3 4 1

Output
Test 1:
4
2 3 5 7
4 5 8 9
6 7 10 12
Test 2:
3
2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned test, i = 0;
	scanf("%u", &test);
	while (++i <= test) {
		unsigned ele, j, k;
		scanf("%u", &ele);
		int arr[ele], **arrp;
		for (j = 0; j < ele; j++) scanf("%d", &arr[j]);
		unsigned sizep = 0, max = 0, *plength;
		j = 0;
		while (j < ele - 1) {
			arrp = realloc(arrp, sizeof(int *) * ++sizep);
			plength = realloc(plength, sizeof(unsigned) * sizep);
			plength[sizep - 1] = 1, arrp[sizep - 1] = &arr[j];
			while (j < ele - 1 && arr[j] < arr[j + 1])
				plength[sizep - 1]++, j++;
			if (plength[sizep - 1] > max) max = plength[sizep - 1];
			++j;
		};
		printf("Test %d:\n%u\n", i, max);
		for (j = 0; j < sizep; j++)
			if (plength[j] == max) {
				for (k = 0; k < max; k++) {
					printf("%d ", *arrp[j]);
					arrp[j]++;
				};
				putchar('\n');
			};
	};
	return 0;
}

/*
Cho ma trận A chỉ gồm các số nguyên dương cấp N*M . Hãy viết chương trình sắp
xếp ma trận A theo kiểu đổi chỗ trực tiếp. Một ma trận được coi là sắp xếp nếu
góc trên bên trái là nhỏ nhất, góc dưới bên phải là lớn nhất, theo mỗi hàng hay
mỗi cột đều được sắp xếp tăng dần.

Hãy thực hiện sắp xếp ma trận theo ý tưởng đổi chỗ trực tiếp.

Dữ liệu vào:
Dòng đầu tiên ghi số bộ test. Với mỗi bộ test: Dòng đầu tiên ghi hai số n và m
là bậc của ma trân a; n dòng tiếp theo, mỗi dòng ghi m số của một dòng trong ma
trận A.

Kết quả:
Với mỗi bộ test ghi ra thứ tự bộ test, sau đó là ma trận tích tương ứng.

Ví dụ

Input

Output

1
3 3
4 2 6
3 5 3
5 7 8

Test 1:

2 3 4
3 5 6
5 7 8
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { //
	return *(int *)a - *(int *)b;
}

void swap(void *a, void *b, size_t size) {
	char *p = a, *q = b, tmp;
	while (size--) {
		tmp = *p;
		*p++ = *q;
		*q++ = tmp;
	}
}

int main(void) {
	unsigned test, l;
	scanf("%u", &test);
	while (l++ < test) {
		printf("Test %u:\n", l);
		unsigned r, c, i, j, k;
		scanf("%u%u", &r, &c);
		int **arr = (int **)malloc(r * sizeof(int *));
		for (i = 0; i < r; i++) {
			arr[i] = (int *)malloc(c * sizeof(int));
			for (j = 0; j < c; j++) //
				scanf("%d", &arr[i][j]);
		}
		for (i = 0; i < r; i++) //
			qsort(arr[i], c, sizeof(int), cmp);
		for (i = 0; i < c; i++)
			for (j = 0; j < r; j++)
				for (k = j + 1; k < r; k++)
					if (arr[j][i] > arr[k][i])
						swap(&arr[j][i], &arr[k][i], sizeof(int));
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) //
				printf("%d ", arr[i][j]);
			putchar('\n');
		}
	}
	return 0;
}

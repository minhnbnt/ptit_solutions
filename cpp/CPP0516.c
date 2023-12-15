/*
Xây dựng cấp trúc mặt hàng gồm các thông tin: Mã mặt hàng (là một số nguyên, tự động tăng, tính từ
1); Tên mặt hàng, nhóm hàng: là các xâu ký tự; Giá mua, giá bán: là các số thực (không quá 9 chữ số)

Hãy sắp xếp danh sách các mặt hàng theo lợi nhuận giảm dần.

Input:
Dòng đầu chứa số mặt hàng. Mỗi mặt hàng viết trên 4 dòng: Dòng 1: Tên mặt hàng. Dòng 2: Nhóm hàng.
Dòng 3: Giá mua. Dòng 4: Giá bán

Output:
Ghi ra danh sách mặt hàng đã sắp xếp theo lợi nhuận giảm dần (lợi nhuận tính bằng giá bán trừ đi giá
mua). Mỗi mặt hàng viết trên một dòng gồm: mã, tên, nhóm hàng và lợi nhuận. Các thông tin cách nhau
đúng 1 khoảng trống. Lợi nhuận viết với 2 chữ  số sau dấu phẩy.

Ví dụ:
Input
3
May tinh SONY VAIO
Dien tu
16400
17699
Tu lanh Side by Side
Dien lanh
18300
25999
Banh Chocopie
Tieu dung
27.5
37

Output
2 Tu lanh Side by Side Dien lanh 7699.00
1 May tinh SONY VAIO Dien tu 1299.00
3 Banh Chocopie Tieu dung 9.50
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned id;
	double profit;
	char *name, *category;
} Item;

void input(Item *it) {

	static unsigned id = 0;
	it->id = ++id;

	getchar();

	size_t size = 0;
	getline(&it->name, &size, stdin);
	strtok(it->name, "\n");

	size = 0;
	getline(&it->category, &size, stdin);
	strtok(it->category, "\n");

	double buy, sell;
	scanf("%lf%lf", &buy, &sell);

	it->profit = sell - buy;
}

int comparator(const void *a, const void *b) {

	const Item *it1 = (Item *)a, *it2 = (Item *)b;

	return it1->profit < it2->profit;
}

int main(void) {

	size_t ele, i;
	scanf("%zu", &ele);

	Item arr[ele];
	for (i = 0; i < ele; ++i) {
		input(arr + i);
	}

	qsort(arr, ele, sizeof(Item), comparator);

	for (i = 0; i < ele; ++i) {

		printf("%u %s %s %.2lf\n", //
		       arr[i].id, arr[i].name, arr[i].category, arr[i].profit);

		free(arr[i].name), free(arr[i].category);
	}

	fflush(stdout);

	return 0;
}

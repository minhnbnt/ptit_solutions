/*
Hãy sắp xếp danh sách các mặt hàng theo lợi nhuận giảm dần. Mỗi mặt hàng gồm các
thông tin: Mã mặt hàng (là một số nguyên, tự động tăng, tính từ 1); Tên mặt
hàng, nhóm hàng: là các xâu ký tự; Giá mua, giá bán: là các số thực (không quá 9
chữ số)

Input:
Dòng đầu chứa số mặt hàng. Mỗi mặt hàng viết trên 4 dòng: Dòng 1: Tên mặt hàng.
Dòng 2: Nhóm hàng. Dòng 3: Giá mua. Dòng 4: Giá bán

Output: Ghi ra danh sách mặt hàng đã sắp xếp theo lợi nhuận giảm dần (lợi nhuận
tính bằng giá bán trừ đi giá mua). Mỗi mặt hàng viết trên một dòng gồm: mã, tên,
nhóm hàng và lợi nhuận. Các thông tin cách nhau đúng 1 khoảng trống. Lợi nhuận
viết với 2 chữ  số sau dấu phẩy.

Ví dụ:
Input:
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

Output:
2 Tu lanh Side by Side Dien lanh 7699.00
1 May tinh SONY VAIO Dien tu 1299.00
3 Banh Chocopie Tieu dung 9.50
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned index;
	char name[50];
	char category[50];
	double interest;
} product;

int cmp(const void *a, const void *b) {
	product *x = (product *)a;
	product *y = (product *)b;
	return x->interest < y->interest;
}

int main() {
	unsigned products, i, j;
	scanf("%u%*c", &products);
	product list[products];
	for (i = 0; i < products; i++) {
		list[i].index = i + 1;
		double buy, sell;
		scanf("%49[^\n]%*c", list[i].name);
		scanf("%49[^\n]%*c", list[i].category);
		scanf("%lf", &buy);
		scanf("%lf%*c", &sell);
		list[i].interest = sell - buy;
	};
	qsort(list, products, sizeof(product), cmp);
	for (i = 0; i < products; i++)
		printf("%u %s %s %.2lf\n", //
		       list[i].index, list[i].name, list[i].category, list[i].interest);
	return 0;
}

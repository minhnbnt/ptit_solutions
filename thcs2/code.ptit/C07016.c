/*
Hãy sắp xếp danh sách thí sinh theo tổng điểm giảm dần.

Mỗi thí sinh gồm các thông tin:

Mã thí sinh: là một số nguyên, tự động tăng. Tính từ 1.
Tên thí sinh, ngày sinh
Điểm môn 1, điểm môn 2, điểm môn 3
Input:

Dòng đầu chứa số thí sinh. Mỗi thí sinh viết trên 3 dòng:

Dòng 1: Tên thí sinh
Dòng 2: Ngày sinh
Dòng 3,4,5: 3 điểm thi tương ứng. Các điểm thi đều đảm bảo hợp lệ (từ 0 đến 10).
Output:

In ra danh sách thí sinh đã sắp xếp theo tổng điểm giảm dần. Nếu 2 thí sinh bằng
điểm nhau thì thí sinh nào xuất hiện trước sẽ viết trước.  Mỗi thí sinh viết
trên một dòng gồm: mã, tên, ngày sinh và tổng điểm. Các thông tin cách nhau đúng
1 khoảng trống.  Điểm tổng được làm tròn đến 1 số sau dấu phẩy.

Ví dụ
Input:
3
Nguyen Van A
12/12/1994
3.5
7.0
5.5
Nguyen Van B
1/9/1994
7.5
9.5
9.5
Nguyen Van C
6/7/1994
4.5
4.5
5.0

Kết quả:
2 Nguyen Van B 1/9/1994 26.5
1 Nguyen Van A 12/12/1994 16.0
3 Nguyen Van C 6/7/1994 14.0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned index;
	char name[50];
	char birth[15];
	float score;
} contestant;

int cmp(const void *a, const void *b) {
	contestant *x = (contestant *)a;
	contestant *y = (contestant *)b;
	return x->score < y->score;
}

int main() {
	unsigned contestants, i, j;
	scanf("%u", &contestants);
	contestant c[contestants];
	for (i = 0; i < contestants; i++) {
		getchar();
		c[i].index = i + 1;
		scanf("%49[^\n]%*c", c[i].name);
		scanf("%14[^\n]%*c", c[i].birth);
		float score;
		c[i].score = 0;
		for (j = 0; j < 3; j++) {
			scanf("%f", &score);
			c[i].score += score;
		}
	}
	qsort(c, contestants, sizeof(contestant), cmp);
	for (i = 0; i < contestants; i++)
		printf("%u %s %s %.1f\n", //
		       c[i].index, c[i].name, c[i].birth, c[i].score);
	return 0;
}

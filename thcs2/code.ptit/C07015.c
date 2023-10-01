/*
Cho danh sách thí sinh gồm các thông tin: Mã thí sinh: là một số nguyên, tự động
tăng, tính từ 1; Tên thí sinh, ngày sinh, điểm môn 1, điểm môn 2, điểm môn 3.
Hãy tìm thủ khoa trong danh sách đó. Nếu có nhiều thí sinh có điểm bằng nhau và
đều cao nhất thì in ra tất cả thí sinh đó theo mã tăng dần.

Input:
Dòng đầu chứa số thí sinh. Mỗi thí sinh viết trên 3 dòng: Dòng 1: Tên thí sinh,
Dòng 2: Ngày sinh, Dòng 3,4,5: 3 điểm thi tương ứng. Các điểm thi đều đảm bảo
hợp lệ (từ 0 đến 10).

Output: In ra các thủ khoa của kỳ thi, mỗi thí sinh 1 dòng, gồm mã, tên, ngày
sinh và tổng điểm. Chú ý: nếu có nhiều thí sinh bằng điểm nhau và cao nhất thì
in ra tất cả thí sinh đó theo thứ tự mã thí sinh tăng dần.

Ví dụ:
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
8.5
9.5
8.5

Output:
2 Nguyen Van B 1/9/1994 26.5
3 Nguyen Van C 6/7/1994 26.5
*/

#include <stdio.h>

typedef struct {
	unsigned index;
	char name[100];
	char birth[15];
	float score;
} contestant;

int main() {
	unsigned contestants, i, j;
	scanf("%u", &contestants);
	contestant list[contestants];
	float max = 0;
	for (i = 0; i < contestants; i++) {
		getchar();
		float score;
		list[i].index = i + 1;
		scanf("%99[^\n]%*c", list[i].name);
		scanf("%14[^\n]%*c", list[i].birth);
		list[i].score = 0;
		for (j = 0; j < 3; j++) {
			scanf("%f", &score);
			list[i].score += score;
		}
		if (list[i].score > max) {
			max = list[i].score;
		}
	}
	for (i = 0; i < contestants; i++)
		if (list[i].score == max)
			printf("%u %s %s %.1f\n", //
			       list[i].index, list[i].name, list[i].birth, list[i].score);
	return 0;
}

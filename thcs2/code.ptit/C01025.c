/*
Cho 2 hình chữ nhật trên mặt phẳng Oxy. Cần tìm hình vuông có kích thước nhỏ
nhất sao cho phủ kín được 2 hình chữ nhật đã cho.

Dữ liệu vào:
2 dòng, mỗi dòng gồm 4 số nguyên lần lượt mô tả điểm trái dưới và phải trên của
hình chữ nhật. Các tọa độ có giá trị tuyệt đối không vượt quá 100.

Kết quả:
In ra diện tích của hình vuông tìm được.

Ví dụ:
Input:
6 6 8 8
1 8 4 9

Output:
49
*/

#include <stdio.h>

int main() {
	int x[4][2];
	for (int i = 0; i < 4; i++) //
		scanf("%d %d", &x[i][0], &x[i][1]);
	int max[2], min[2];
	for (int i = 0; i < 2; i++) {
		max[i] = min[i] = x[0][i];
		for (int j = 1; j < 4; j++)
			if (x[j][i] > max[i]) {
				max[i] = x[j][i];
			} else if (x[j][i] < min[i]) {
				min[i] = x[j][i];
			}
	};
	int edge = max[0] - min[0];
	if (max[1] - min[1] > edge) //
		edge = max[1] - min[1];
	printf("%d", edge * edge);
	return 0;
}

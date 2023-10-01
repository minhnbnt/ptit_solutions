/*
Cho một bảng cỡ N x N, mỗi ô ghi giá trị số 0 hoặc 1. Chỉ số hàng và cột đánh số
từ 1 đến N. Phép đảo giá trị (swap) trên một phần của bảng được được định nghĩa
là đảo ngược giá trị tất cả các ô trong phần đó, 0 biến đổi thành 1, và 1 biến
đổi thành 0.

Giả sử mỗi bước, bạn được phép swap tất cả các số của một hình chữ nhật con có
điểm trái trên là (1, 1).

Hãy tính xem ít nhất bao nhiêu bước để có thể đưa bảng về trạng thái chứa toàn
số 0.

Input:
Dòng đầu tiên là số nguyên N (1 ≤ N ≤ 10).
N dòng tiếp theo, mỗi dòng gồm N kí tự mô tả một hàng của bảng.

Output:
In ra đáp án tìm được.

Ví dụ:
Input:
3
001
111
111

Output:
2

Giải thích test:

Bước 1: Swap toàn bộ hình.
110
000
000

Bước 2: Swap 2 ô đầu tiên.
*/

#include <stdio.h>

int main() {
	int n, count = 0;
	scanf("%d", &n);
	int i, j, k, l;
	char a[n][n];
	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < n; j++) {
			scanf("%c", &a[i][j]);
			a[i][j] -= '0';
		}
	}
	for (i = n - 1; i >= 0; i--)
		for (j = n - 1; j >= 0; j--)
			if (a[i][j]) {
				for (k = 0; k <= i; k++)
					for (l = 0; l <= j; l++) {
						a[k][l] = (a[k][l] + 1) % 2;
					}
				++count;
			}
	printf("%d\n", count);
	return 0;
}

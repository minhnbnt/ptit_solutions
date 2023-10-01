/*
Trên tờ giấy A4, Nam đã đánh dấu sẵn N điểm từ 1 đến N và liệt kê danh sách N-1
đoạn thẳng nối các điểm với nhau. Nam nhờ Bình kiểm tra giúp xem với danh sách
N-1 đoạn thẳng đó thì có điểm nào là điểm trung tâm hay không.

Một điểm được coi là trung tâm nếu nó có đoạn thẳng nối với tất cả N-1 điểm còn
lại.

Input
Dòng đầu tiên ghi số N (1 ≤ N ≤ 10^5).
N-1 dòng tiếp theo, mỗi dòng ghi ra một đoạn thẳng.
Kết quả

Ghi ra trên một dòng chữ “Yes” nếu tồn tại điểm trung tâm; chữ “No” trong trường
hợp ngược lại.

Ví dụ:
Input:
5
1 2
1 3
1 4
1 5

Output:
Yes
*/

#include <stdio.h>

int main(void) {
	unsigned n, i, j;
	scanf("%u", &n);
	int arr[n - 1][2], *a = NULL;
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	char result = 0, flag[n];
	for (i = 0; i < 2; i++)
		if (arr[0][i] == arr[1][0] || //
		    arr[0][i] == arr[1][1]) {
			a = &arr[0][i];
			break;
		}
	if (a != NULL) {
		char flag[n];
		for (i = 0; i < n - 1; i++) flag[i] = 0;
		flag[*a - 1] = 1, result = 1;
		for (i = 0; i < n - 1; i++) {
			int *p = arr[i];
			if (*p == *a) p++;
			if (*p <= n && *p > 0) flag[*p - 1] = 1;
		}
		for (i = 0; i < n; i++)
			if (!flag[i]) {
				result = 0;
				break;
			}
	}
	puts(result ? "Yes" : "No");
	return 0;
}

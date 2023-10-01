/*
Với một vài số nguyên dương có 1 chữ số, khi cắt đôi số đó theo chiều ngang và
lấy nửa phía trên thì ta vẫn có một số nguyên. Cụ thể:

Số 0 cắt đôi vẫn ra số 0
Số 1 cắt đôi vẫn ra số 1
Số 8 cắt đôi ra số 0
Số 9 cắt đôi ra số 0
Các số khác cắt đôi sẽ không hợp lệ.
Cho một số nguyên dương không quá 18 chữ số. Hãy in ra kết quả “cắt đôi” của số
đó.

Nếu không hợp lệ thì ghi ra INVALID. Chú ý: nếu cắt đôi ra một dãy toàn 0 thì
cũng được coi là không hợp lệ. Kết quả cắt đôi thì không tính chữ số 0 ở đầu.

Input

Dòng đầu ghi số bộ test. Mỗi bộ test ghi một số nguyên dương không quá 18 chữ
số.

Output

Ghi ra kết quả tính toán

Ví dụ

Input:
3
1890
3681
8919

Output:
1000
INVALID
10
*/

#include <stdio.h>

int main() {
	unsigned n, i;
	scanf("%u", &n);
	char flag[n];
	unsigned long long result[n];
	for (i = 0; i < n; i++) {
		flag[i] = 1;
		unsigned long long num;
		scanf("%llu", &num);
		unsigned long long temp = num, j = 1;
		while (temp) {
			char x = temp % 10;
			if (x == 8) num -= 8 * j;
			else if (x == 9) num -= 9 * j;
			else if (x != 1 && x != 0) {
				flag[i] = 0;
				break;
			};
			temp /= 10, j *= 10;
		};
		if (!num) flag[i] = 0;
		result[i] = num;
	};
	for (i = 0; i < n; i++)
		if (flag[i]) printf("%llu\n", result[i]);
		else puts("INVALID");
	return 0;
}

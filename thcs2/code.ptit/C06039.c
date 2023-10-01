/*
Cho N xâu S[1], S[2], …, S[N] có độ dài bằng nhau. Mỗi bước, với xâu T, bạn được
phép xoay vòng 1 kí tự, tức lấy kí tự đầu tiên của T rồi chuyển xuống cuối. Ví
dụ xâu “cool” sẽ chuyển thành “oolc”.

Bạn cần phải xoay N xâu sao cho tất cả chúng đều giống nhau. Hãy xác định số
bước ít nhất để hoàn thành được công việc này?

Input:

Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 50).

N dòng tiếp theo, mỗi dòng gồm xâu S[i] có độ dài không quá 50.

Output:

Với mỗi test, in ra số bước ít nhất tìm được, nếu không thể biến đổi, hãy in ra
-1.

Ví dụ:
Input:
4
xzzwo
zwoxz
zzwox
xzzwo

Output:
5
-------
Input:
2
molzv
lzvmo

Output:
2
-------
Input:
3
kc
kc
kc

Output:
0
-------
Input:
3
aa
aa
ab

Output:
-1
*/

#include <stdio.h>
#include <string.h>

int main(void) {
	unsigned test, i;
	scanf("%u%*c", &test);
	char str[test][100], base[200], flag = 1;
	unsigned step[test], min = __UINT32_MAX__;
	for (i = 0; i < test; i++) {
		fgets(str[i], 100, stdin);
		str[i][strlen(str[i]) - 1] = step[i] = 0;
	}
	unsigned len = strlen(str[0]), sum = 0;
	strcpy(base, str[0]), strcat(base, str[0]);
	for (i = 0; i < test; i++) {
		char *p = strstr(base, str[i]);
		if (p == NULL || len != strlen(str[i])) {
			flag = 0;
			break;
		} else step[i] = len - (p - base);
		if (min > step[i]) min = step[i];
	}
	for (i = 0; i < test; i++) sum += step[i] - min;
	if (flag) printf("%u\n", sum);
	else puts("-1");
	return 0;
}

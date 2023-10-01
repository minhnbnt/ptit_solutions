/*
Viết chương trình tính hiệu của hai số nguyên lớn. Chú ý: luôn luôn lấy số lớn
hơn trừ đi số nhỏ hơn.

Input:
Dòng 1 ghi số bộ test
Mỗi bộ test gồm 2 dòng, mỗi dòng ghi một số không quá 1000 chữ số..

Output: Với mỗi bộ test ghi ra kết quả tính toán tương ứng

Ví dụ:

Input:
3
456
789
100000000000000000000000000001
99
123456789012345678901234567890
1234567890

Output:
333
99999999999999999999999999902
123456789012345678900000000000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char which_is_lager(const char *a, const char *b) {
	unsigned len_a = strlen(a), len_b = strlen(b);
	if (len_a > len_b) return 1;
	else if (len_a < len_b) return -1;
	return strcmp(a, b);
}

char *minus(const char *l, const char *s) {
	unsigned len_l = strlen(l), len_s = strlen(s), carry = 0;
	char *result = malloc(len_l + 1);
	do {
		int tmp = -carry;
		if (len_l > 0) tmp += l[--len_l] - '0';
		if (len_s > 0) tmp -= s[--len_s] - '0';
		if (tmp < 0) tmp += 10, carry = 1;
		else carry = 0;
		result[len_l] = tmp + '0';
	} while (len_l > 0);
	return result;
}

int main(int argc, char *argv[]) {
	unsigned test_cases;
	scanf("%u%*c", &test_cases);
	while (test_cases--) {
		char a[1001] = { 0 }, b[1001] = { 0 }, *tmp;
		scanf("%s%*c%s%*c", a, b);
		char cmp = which_is_lager(a, b);
		if (cmp == 0) puts("0");
		else {
			if (cmp > 0) tmp = minus(a, b);
			else tmp = minus(b, a);
			char *result = tmp;
			while (*result == '0') ++result;
			puts(result), free(tmp);
		}
	}
	return 0;
}

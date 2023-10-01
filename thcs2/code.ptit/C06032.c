/*
Cho M xâu kí tự. Nhiệm vụ của bạn là hãy ghép các xâu này thành một từ, sao cho
từ thu được có thứ tự từ điển nhỏ nhất.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm số nguyên M (M ≤ 9) là số lượng các từ, theo sau là M xâu.
Mỗi xâu có độ dài không vượt quá 10.

Output:
Với mỗi test hãy in ra xâu có thứ tự từ điển nhỏ nhất tìm được.

Ví dụ:
Input:
5
4 acm ptit for students
5 k duz q rc lvraw
3 a bb cc
5 asf asfi asfi afsi okj
5 ukuy hopji lie jaa dcyi

Output:
acmforptitstudents
duzklvrawqrc
abbcc
afsiasfasfiasfiokj
dcyihopjijaalieukuy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b) > 0;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i;
		scanf("%u%*c", &ele);
		char str[ele][10];
		for (i = 0; i < ele; i++) {
			scanf("%s", str[i]);
		}
		qsort(str, ele, 10, cmp);
		for (i = 0; i < ele; i++) {
			printf("%s", str[i]);
		}
		putchar('\n');
	}
	return 0;
}

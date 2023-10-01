/*
Tìm số lần xuất hiện các từ trong xâu S (không phân biệt chữ hoa chữ thường).
Kết quả in ra từ (ở dạng in thường) và số lần xuất hiện của chúng

Input:
Chỉ có một dòng ghi xâu S.

Output:
Ghi ra kết quả đếm từng từ theo thứ tự xuất hiện.

Ví dụ:
Input:
aaa bbb ccc AA bb aa ccc aa

Output:
aaa 1
bbb 1
ccc 2
aa 3
bb 1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char str[50];
	unsigned count;
} word;

int main() {
	char *str = malloc(1), c;
	word *words = malloc(sizeof(word));
	unsigned size = 0, i;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		c = tolower(c);
		str = realloc(str, sizeof(char) * ++size);
		str[size - 1] = c;
	}
	str[size] = 0, size = 0;
	char *p = strtok(str, " ");
	while (p != NULL) {
		char flag = 1;
		for (i = 0; i < size; i++)
			if (!strcmp(words[i].str, p)) {
				words[i].count++, flag = 0;
				break;
			}
		if (flag) {
			words = realloc(words, sizeof(word) * (size + 1));
			strcpy(words[size].str, p);
			words[size++].count = 1;
		}
		p = strtok(NULL, " ");
	}
	for (i = 0; i < size; i++) //
		printf("%s %u\n", words[i].str, words[i].count);
	return 0;
}

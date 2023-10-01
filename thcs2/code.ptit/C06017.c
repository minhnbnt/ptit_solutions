/*
Cho hai chuỗi ký tự S1 và S2 độ dài không quá 100.

Hãy viết chương trình tìm các từ chỉ xuất hiện trong S1 mà không xuất hiện trong
S2. Chú ý: mỗi từ chỉ liệt kê 1 lần và sắp xếp theo thứ tự xuất hiện trong từ
điển

Input:
Có hai dòng, dòng thứ nhất ghi xâu S1, dòng thứ 2 ghi xâu S2.

Output:
Ghi lần lượt các từ thỏa mãn trên một dòng.

Ví dụ:

Input:
abc ab ab ab abcd
ab abc

Output:
abcd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *str;
	char flag;
} word;

int cmp(const void *a, const void *b) {
	return strcmp(*(char **)a, *(char **)b) > 0;
}

int main(void) {
	char str1[1000];
	fgets(str1, 1000, stdin);
	strtok(str1, "\n");
	unsigned size = 0, i;
	word *words = (word *)malloc(sizeof(word));
	char *token = strtok(str1, " ");
	while (token != NULL) {
		words = (word *)realloc(words, sizeof(word) * (size + 1));
		words[size].str = token;
		for (i = 0; i < size; i++)
			if (strcmp(token, words[i].str) == 0) {
				words[size].flag = 0;
				break;
			}
		if (i == size) words[size++].flag = 1;
		token = strtok(NULL, " ");
	}
	char str2[1000];
	fgets(str2, 1000, stdin);
	strtok(str2, "\n");
	token = strtok(str2, " ");
	while (token != NULL) {
		for (i = 0; i < size; i++)
			if (strcmp(token, words[i].str) == 0) words[i].flag = 0;
		token = strtok(NULL, " ");
	}
	qsort(words, size, sizeof(word), cmp);
	for (i = 0; i < size; i++)
		if (words[i].flag) printf("%s ", words[i].str);
	printf("\n");
	return 0;
}

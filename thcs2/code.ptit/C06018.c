/*
Cho hai xâu ký tự S1 và S2. Hãy viết chương trình tìm các từ chỉ xuất hiện trong
S1 mà không xuất hiện trong S2. Chú ý: mỗi từ chỉ liệt kê 1 lần.

Input: Dòng 1 ghi số bộ test. Mỗi bộ test gồm 2 dòng, mỗi dòng ghi một xâu ký tự
độ dài không quá 200, chỉ bao gồm các ký tự viết thường và các khoảng trống.

Output:
Với mỗi bộ test ghi ra các từ có trong S1 mà không có trong S2. Các từ được ghi
theo thứ tự từ điển.

Ví dụ:

Input:
2
abc ab ab ab abcd
ab abc
aaa xyz ab zzz abc dd dd abc
xyz dd ttt sas cdc

Output:
abcd
aaa ab abc zzz
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
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
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
		putchar('\n');
		free(words);
	}
	return 0;
}

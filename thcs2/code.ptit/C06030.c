/*
Cho một văn bản bất kỳ.  Hãy tìm ra từ có độ dài lớn nhất. Nếu có nhiều từ khác
nhau có độ dài bằng nhau và bằng giá trị lớn nhất thì in ra tất cả các từ đó
theo thứ tự xuất hiện trong file dữ liệu vào (nhưng một từ dù xuất hiện nhiều
lần cũng chỉ được liệt kê một lần).

Input:Gồm một đoạn văn bản bất kỳ. Không quá 1000 từ.

Output:Ghi ra từ dài nhất, độ dài của nó và số lần xuất hiện trong file, cách
nhau một khoảng trống. Nếu có nhiều từ như vậy thì liệt kê lần lượt các từ theo
thứ tự xuất hiện trong file ban đầu.

Ví dụ:

Input:
Tiet hoc cuoi cung da ket thuc. Mon hoc Tin hoc co so 2 da ket thuc. Cac ban co
gang on tap tot de thi dat ket qua cao. Chuc cac ban ngay cang gat hai duoc
nhieu thanh cong tren con duong da chon

Output:
thuc. 5  2
nhieu 5  1
thanh 5  1
duong 5  1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char content[100];
	unsigned count;
} word;

int main(void) {
	word *w = (word *)malloc(sizeof(word));
	char str[100];
	unsigned max_len = 0, size = 0, i;
	while (scanf("%s", str) != EOF) {
		unsigned len = strlen(str);
		if (len > max_len) {
			max_len = strlen(str), free(w), size = 1;
			w = (word *)malloc(sizeof(word));
			strcpy(w->content, str), w->count = 1;
		} else if (len == max_len) {
			char flag = 1;
			for (i = 0; i < size; i++)
				if (strcmp(w[i].content, str) == 0) {
					++w[i].count, flag = 0;
					break;
				}
			if (flag) {
				w = (word *)realloc(w, sizeof(word) * (size + 1));
				strcpy(w[size].content, str), w[size++].count = 1;
			}
		}
	}
	for (i = 0; i < size; i++) //
		printf("%s %u %u\n", w[i].content, max_len, w[i].count);
	return 0;
}

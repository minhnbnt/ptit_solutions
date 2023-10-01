/*
Một xâu được gọi là đầy đủ nếu xóa đi 0 hoặc nhiều hơn các ký tự từ xâu đó ta
thu được xâu abcdefghijklmnopqrstuvwxyz

Cho một xâu ký tự chỉ bao gồm các chữ cái viết thường. Hãy tính số ký tự phải
chèn thêm ít nhất (vào bất cứ chỗ nào) để có thể chuyển xâu đó sang dạng đầy đủ.

Input: Chỉ có một dòng ghi ra xâu ký tự đầu vào. Không quá 50 chữ cái.
Output: Ghi ra số kỹ tự ít nhất phải chèn thêm.

Ví dụ:
Input
xyzabcdefghijklmnopqrstuvw

Output:
3

-----
Input:
aiemckgobjfndlhp

Output:
20
*/

#include <stdio.h>
#include <string.h>

int filter(const char *str) {
	int max_len = 0, len = strlen(str), i, j, arr[len];
	for (i = 0; i < len; i++) {
		arr[i] = 0;
		for (j = 0; j < i; j++)
			if (str[j] < str[i] && arr[j] > arr[i]) //
				arr[i] = arr[j];
		if (++arr[i] > max_len) max_len = arr[i];
	}
	return 26 - max_len;
}

int main(int argc, char *argv[]) {
	char str[100];
	fgets(str, 100, stdin);
	printf("%d\n", filter(str));
	return 0;
}

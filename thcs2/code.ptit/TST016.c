/*
Một xâu được gọi là đối xứng nếu nó gồm các cặp dấu (), [], {}, '', "" có đủ bộ
Ví dụ: ()(), ((())()) là các xâu đối xứng

Cho một xâu, hãy cho biết nó là đối xứng (in ra 1), không đối xứng (in ra 0)

Vào:
Chuỗi các ký tự (,),{,},[,],',',"," trên một hàng

Ra:
1 nếu chuỗi vào đối xứng, 0 nếu chuỗi vào không đối xứng

Ví dụ:
Input:         Output:
()()           1
(}()           0
*/

#include <stdio.h>

char check(char *str) {
	int a, b, c;
	char d, e;
	a = b = c = d = e = 0;
	for (char *p = str; *p != '\n'; p++) {
		if (*p == '(') ++a;
		else if (*p == ')') --a;
		else if (*p == '[') ++b;
		else if (*p == ']') --b;
		else if (*p == '{') ++c;
		else if (*p == '}') --c;
		if (a < 0 || b < 0 || c < 0) return 0;
		else if (*p == '\'') d = !d;
		else if (*p == '"') e = !e;
	}
	return !a && !b && !c && !d && !e;
}

int main() {
	char str[1000] = { 0 };
	fgets(str, 100, stdin);
	printf("%d\n", check(str));
	return 0;
}

/*
Bảng chữ số La Mã bao gồm các chữ cái với ý nghĩa I=1; V=5; X=10; L=50;
C=100;D=500; M=1000. Một số quy tắc viết các số La Mã như sau:

Tính từ trái sang phải giá trị của các chữ số và nhóm chữ số giảm dần.
I chỉ có thể đứng trước V hoặc X, X chỉ có thể đứng trước L hoặc C, C chỉ có thể
đứng trước D hoặc M. Các chữ cái I, X, C, M, không được lặp lại quá ba lần liên
tiếp; các chữ cái V, L, D không được lặp lại quá một lần liên tiếp. Bài toán đặt
ra là cho một xâu ký tự mô tả đúng một số La Mã. Hãy tính giá trị thập phân của
số đó

Input: Dòng đầu ghi số bộ test. Mỗi bộ test ghi trên một dòng dãy ký tự số La
Mã.

Output: Với mỗi bộ test ghi ra kết quả tương ứng

Ví dụ:
Input:
3
XIX
DC
CD

Output:
19
600
400
*/

#include <stdio.h>

#define ull unsigned long long

enum roman { // don't need to use enum,
	         // but it's a good practice :D
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000,
};

const unsigned roman_char[] = {
	['I'] = I, ['V'] = V, ['X'] = X, //
	['L'] = L, ['C'] = C, ['D'] = D, ['M'] = M,
};

ull convert_roman_to_arabic(const char *roman) {
	ull result = 0;
	int last = 0, current;
	while (*roman != '\n') {
		current = roman_char[*roman];
		if (current > last) //
			result -= 2 * last;
		result += current;
		last = current;
		++roman;
	}
	return result;
}

int main(void) {
	unsigned test_cases;
	scanf("%u%*c", &test_cases);
	while (test_cases--) {
		char roman[20];
		fgets(roman, 20, stdin);
		printf("%llu\n", //
		       convert_roman_to_arabic(roman));
	}
	return 0;
}

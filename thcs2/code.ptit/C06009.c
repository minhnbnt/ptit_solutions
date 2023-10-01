/*
Biển số xe máy được quy định gồm các thành phần:

Hai chữ số đầu là mã quản lý theo tỉnh – thành phố (ví dụ mã của Hà Nội là 29
đến 31) Tiếp theo là dấu gạch ngang, sau đó là một chữ cái in hoa (từ A đến Z)
và một chữ số. Cặp chữ cái và chữ số này được cấp theo khu vực quận – huyện.
Tiếp theo là một dãy 5 số gồm 2 cụm: 3 chữ số đầu và hai chữ số sau, phân tách
bởi dấu chấm. Thông thường, người ta chỉ quan tâm đến 5 chữ số cuối. Giả sử các
trường hợp sau được coi là đẹp:

Cả 5 chữ số được sắp theo thứ tự tăng chặt từ trái qua phải.
Cả 5 chữ số đều bằng nhau
Ba chữ số đầu bằng nhau và hai chữ số cuối bằng nhau
Cả 5 chữ số đều là 6 và/hoặc 8 (số lộc phát).

Theo quy tắc trên, các biển số sau được coi là đẹp:
29-T1 123.79
29-T1 555.55
29-T1 222.33
29-T1 686.88

Và các biển số sau không đẹp:
29-T1 123.33
29-T1 555.54
29-T1 606.88
Viết chương trình kiểm tra xem các biển số xe có đẹp hay không.

Dữ liệu vào

Dòng đầu ghi số bộ test, không quá 50
Mỗi bộ test là một biển số. Dữ liệu vào đảm bảo biển số được viết đúng quy định.
Kết quả

In ra kết quả kiểm tra với từng bộ test
Ví dụ

Input:
7                  Output:
29-T1 123.45       YES
29-T1 555.55       YES
29-T1 222.33       YES
29-T1 686.88       YES
29-T1 123.33       NO
29-T1 555.54       NO
29-T1 606.88       NO
*/

#include <stdio.h>

char beautyof(double a) {
	char str[6], *p, flag[2];
	flag[0] = flag[1] = 1;
	sprintf(str, "%5.0f", a *= 100);
	str[5] = '\0';
	if (str[0] == str[1] && str[1] == str[2] && str[3] == str[4]) return 1;
	for (p = str; *p != '\0'; p++) {
		if (*p != '8' && *p != '6') flag[1] = 0;
		if (*p >= *(p + 1) && *(p + 1) != '\0') flag[0] = 0;
	}
	return flag[0] || flag[1];
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		double a;
		scanf("%*c%*s %lf", &a);
		puts(beautyof(a) ? "YES" : "NO");
	}
	return 0;
}

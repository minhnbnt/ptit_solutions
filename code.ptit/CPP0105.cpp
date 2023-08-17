/*
Một số được gọi là “lộc phát” nếu chỉ có các chữ số 0,6,8. Nhập vào một số
nguyên dương không quá 9 chữ số, hãy kiểm tra xem đó có phải số lộc phát hay
không.

Input
Dòng đầu là số bộ test, mỗi dòng tiếp theo ghi một số cần kiểm tra.

Ouput
Nếu đúng in ra YES, nếu sai in ra NO.

Ví dụ

Input:
3
181
88888
608868

Output:
NO
YES
YES
*/

#include <cstring>
#include <iostream>
#include <string>

bool all_068(std::string num) {

	const char *num_c = num.c_str();

	while (*num_c != '\0') {
		if (strchr("068", *num_c) == NULL) {
			return false;
		}
		++num_c;
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (all_068(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}

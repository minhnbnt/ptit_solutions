/*
Biển số xe máy được quy định gồm các thành phần:

Hai chữ số đầu là mã quản lý theo tỉnh – thành phố (ví dụ mã của Hà Nội là 29 đến 31)
Tiếp theo là dấu gạch ngang, sau đó là một chữ cái in hoa (từ A đến Z) và một chữ số. Cặp chữ cái và
chữ số này được cấp theo khu vực quận – huyện. Tiếp theo là một dãy 5 số gồm 2 cụm: 3 chữ số đầu và
hai chữ số sau, phân tách bởi dấu chấm. Thông thường, người ta chỉ quan tâm đến 5 chữ số cuối. Giả
sử các trường hợp sau được coi là đẹp:

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

Ví dụ:
Input
7
29T1–123.45
29T1–555.55
29T1–222.33
29T1–686.88
29T1–123.33
29T1–555.54
29T1–606.88

Output
YES
YES
YES
YES
NO
NO
NO
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool is_nice_sign(const std::string &s) {

	const std::string sign_tail = s.substr(5);
	std::vector<char> chars;

	for (char c : sign_tail) {

		if (c == '.') continue;

		chars.push_back(c);
	}

	if (std::is_sorted(chars.cbegin(), chars.cend(), std::less_equal<char>())) {
		return true;
	}

	if (chars[0] == chars[1] && chars[1] == chars[2] && chars[3] == chars[4]) {
		return true;
	}

	std::unordered_set<char> chars_set(chars.cbegin(), chars.cend());

	if (chars.size() == 1) {
		return true;
	}

	for (char c : chars_set) {
		if (strchr("68", c) == NULL) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::string signs;
		std::cin >> std::ws >> signs;

		std::cout << (is_nice_sign(signs) ? "YES" : "NO") << std::endl;
	}

	return 0;
}

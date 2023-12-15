/*
Cho dữ liệu vào dạng văn bản, với không quá 1000 số nguyên dương, các số không quá 50 chữ số. Hãy
liệt kê các số thuận nghịch khác nhau theo thứ tự giảm dần và số lần xuất hiện của nó.

Input
Luồng vào dạng văn bản với không quá 1000 số nguyên dương. Không biết trước số dòng hoặc số lượng
chính xác bao nhiêu số nguyên.

Output
Ghi ra các số thuận nghịch theo thứ tự giá trị giảm dần và số lần xuất hiện của nó, mỗi số trên một
dòng. Không tính các số có 1 chữ số.

Ví dụ
Input
12321 456 12321 34 56 9999999999999999999
12 3 43 34 54 34 54 34 54 657
5 45 554 12321 12321
65 76 45 45 34 53
546 565 65645 6 65 65 35 65
565 565

Output
9999999999999999999 1
12321 4
565 3
*/

#include <iostream>
#include <map>

bool revertable(const std::string &s) {

	const size_t &len = s.length();

	for (size_t i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - i - 1]) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	auto comparator = [](const std::string &s1, const std::string &s2) {
		if (s1.length() != s2.length()) {
			return s1.length() > s2.length();
		}

		return s1 > s2;
	};

	std::map<std::string, size_t, decltype(comparator)> map(comparator);

	while (!std::cin.eof()) {

		std::string num;
		std::cin >> std::ws >> num;

		if (num.length() < 2 || !revertable(num)) {
			continue;
		}

		++map[num];
	}

	for (const auto &[num, count] : map) {
		std::cout << num << ' ' << count << '\n';
	}
	std::cout.flush();

	return 0;
}

/*
Cho một số nguyên dương lớn có nhiều hơn 20 chữ số nhưng không quá 1000 chữ số.
Hãy kiểm tra xem số đó có đầy đủ tất cả các chữ số từ 0 đến 9 hay không.

Dữ liệu vào:
Dòng đầu ghi số bộ test, không quá 10
Mỗi bộ test là một dãy ký tự có độ dài không quá 1000, không có khoảng trống

Kết quả:
Nếu dữ liệu vào không phải là một số nguyên hợp lệ (có ký tự không phải số hoặc
bắt đầu bằng chữ số 0) thì in ra INVALID Nếu dữ liệu vào thỏa mãn đầy đủ thì in
ra YES, nếu không in ra NO

Ví dụ
Input:
3
01234aa32432432432534545b987978
123444444444444566666666667890
324562783924723543243243242354354354333234324

Output:
INVALID
YES
NO
*/

#include <iostream>
#include <string>
#include <unordered_set>

int is_full_number(std::string s) {

	if (s[0] == '0') return -1;
	std::unordered_set<char> set;

	for (const char &c : s) {
		if (!isdigit(c)) return -1;
		set.insert(c);
	}

	return set.size() == 10;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		int result = is_full_number(input);

		if (result == -1) std::cout << "INVALID";
		else std::cout << (result ? "YES" : "NO");

		std::cout << std::endl;
	}

	return 0;
}

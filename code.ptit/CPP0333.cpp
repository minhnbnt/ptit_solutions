/*
Tên người dùng sẽ được chuẩn hóa theo nguyên tắc tên được viết sau cùng, phân
tách với phần tên đệm và tên bởi dấu phẩy. Các chữ cái nằm trong tên đều được
viết hoa; chữ cái đầu tiên của tên đệm và họ được viết hoa, các chữ cái còn lại
viết thường.

Input:
Chỉ có một xâu họ tên độ dài không quá 100

Output:
Ghi ra xâu họ tên đã chuẩn hóa theo mẫu trong ví dụ

Ví dụ:
Input:
ngUyeN   vAN Nam

Output:
Nguyen Van, NAM
*/

#include <iostream>
#include <sstream>
#include <string>

std::string &proper(std::string &s) {

	for (char &c : s) {
		c = tolower(c);
	}

	s[0] = toupper(s[0]);

	return s;
}

std::string &upper(std::string &s) {

	for (char &c : s) {
		c = toupper(c);
	}

	return s;
}

int main(void) {

	std::string full_name, str;
	std::getline(std::cin, full_name);
	std::istringstream iss(full_name);

	bool is_first = true;

	while (true) {

		iss >> str;

		if (iss.eof()) break;

		if (!is_first) {
			std::cout.put(' ');
		}

		is_first = false;

		std::cout << proper(str);
	}

	std::cout << ", " << upper(str) << std::endl;
}

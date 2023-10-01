/*
Địa chỉ email của cán bộ PTIT được cấp theo nguyên tắc ghép tên với chữ cái đầu
tiên của họ và tên đệm. Viết chương trình cho phép tạo các địa chỉ email theo
tên cán bộ

Input
Chỉ có một xâu ký tự họ tên độ dài không quá 100.

Output
Ghi ra địa chỉ email theo mẫu trong ví dụ.

Ví dụ
Input:
Nguyen vAn nAM

Output:
namnv@ptit.edu.vn
*/

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::string full_name;
	std::getline(std::cin, full_name);
	std::istringstream iss(full_name);

	std::string nick_name = "";
	while (true) {

		std::string word;
		iss >> word;

		if (iss.eof()) {

			for (char &c : word) {
				c = tolower(c);
			}

			nick_name = word + nick_name;

			break;
		}

		nick_name += tolower(word[0]);
	}

	std::cout << nick_name << "@ptit.edu.vn" << std::endl;

	return 0;
}

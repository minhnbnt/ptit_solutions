/*
Cho hai file DATA1.in và DATA2.in.

Một từ được định nghĩa là một dãy ký tự liên tiếp không có khoảng trống, dấu tab hay dấu xuống dòng.
Tạm thời chưa xét đến các dấu câu trong bải toán này.

Hãy viết chương trình liệt kê hợp và giao của hai tập từ khác nhau trong hai file.

Các từ được liệt kê theo thứ tự từ điển.

Input
Hai file văn bản DATA1.in và DATA2.in, có không quá 200 dòng.

Output
Hợp và giao của hai tập từ khác nhau trong hai file ban đầu. Mỗi tập trên một dòng, các từ liệt kê
theo thứ tự từ điển và cách nhau đúng một khoảng trống.

Ví dụ
DATA1.in
lap trinh huong doi tuong
ngon ngu lap trinh C++

DATA2.in
lap trinh co ban
lap trinh huong thanh phan

Output
ban c++ co doi huong lap ngon ngu phan thanh trinh tuong
huong lap trinh
*/

#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::set<std::string> data1, data2;

	std::string word;
	std::ifstream ifs("DATA1.in");
	while (ifs >> word) {
		for (char &c : word) {
			c = tolower(c);
		}
		data1.insert(word);
	}

	ifs = std::ifstream("DATA2.in");
	while (ifs >> word) {
		for (char &c : word) {
			c = tolower(c);
		}
		data2.insert(word);
	}

	std::set<std::string> _union(data1);
	for (const std::string &s : data2) {
		_union.insert(s);
	}

	for (const std::string &s : _union) {
		std::cout << s << ' ';
	}

	std::cout.put('\n');

	for (const std::string &s : data1) {
		if (data2.find(s) == data2.end()) {
			continue;
		}
		std::cout << s << ' ';
	}

	std::cout << std::endl;

	return 0;
}

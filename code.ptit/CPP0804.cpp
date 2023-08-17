/*
Cho file văn bản VANBAN.in.

Một từ được định nghĩa là một dãy ký tự liên tiếp không có khoảng trống, dấu tab
hay dấu xuống dòng. Tạm thời chưa xét đến các dấu câu trong bải toán này.

Hãy chuyển tất cả các từ về dạng chữ thường sau đó liệt kê các từ khác nhau xuất
hiện trong file VANBAN.in theo thứ tự từ điển.

Input
File VANBAN.in có không quá 200 dòng.

Output
Ghi ra danh sách các từ khác nhau xuất hiện trong file. Mỗi từ trên một dòng
theo thứ tự từ điển.

Ví dụ:
VANBAN.in
lap trinh Huong doi tuong
lap trinh Huong thanh phan

Output:
doi
huong
lap
phan
thanh
trinh
tuong
*/

#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::string buf;
	std::ifstream ifs("VANBAN.in");
	std::set<std::string> words;

	while (ifs >> buf) {
		for (char &c : buf) {
			c = tolower(c);
		}
		words.insert(buf);
	}

	for (std::string word : words) {
		std::cout << word << '\n';
	}

	return 0;
}

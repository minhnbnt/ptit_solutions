/*
Thông tin về giảng viên Khoa CNTT ban đầu chỉ có họ tên và Bộ môn. Mã giảng viên sẽ tự động điền
tăng dần, tính từ GV01.

Hãy tìm kiếm giảng viên theo tên (yêu cầu tìm gần đúng – tức là trong tên giảng viên xuất hiện từ
hoặc cụm từ khóa, không phân biệt chữ hoa chữ thường).

Input
Dòng đầu ghi số giảng viên.
Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).
Tiếp theo là một dòng ghi số Q là số truy vấn.
Mỗi truy vấn là một từ khóa cần tìm.

Output
Danh sách các giảng viên tìm được theo từ khóa, trong đó mỗi giảng viên ghi trên một dòng. Mã được
tự động điền theo thứ tự nhập, bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở dạng in
hoa.
Thứ tự giảng viên của mỗi bộ môn được liệt kê theo đúng thứ tự ban đầu.

Ví dụ

Input
3
Nguyen Manh Son
Cong nghe phan mem
Vu Hoai Nam
Khoa hoc may tinh
Dang Minh Tuan
An toan thong tin
1
aN

Output
DANH SACH GIANG VIEN THEO TU KHOA aN:
GV01 Nguyen Manh Son CNPM
GV03 Dang Minh Tuan ATTT
*/

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

class Teacher {

	size_t id;
	std::string name, subj;

public:

	const std::string &get_name(void) const {
		return name;
	}

	void input(void) {

		static unsigned id = 0;
		this->id = ++id;

		std::string raw_subjName, buf;
		for (std::string *s : { &name, &raw_subjName }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::istringstream iss(raw_subjName);
		while (iss >> buf) {
			subj.push_back(toupper(buf[0]));
		}
	}

	void print(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 2) id = '0' + id;

		id = "GV" + id;

		std::cout << id << ' ' << name << ' ' << subj << '\n';
	}
};

int main(void) {

	size_t num_T;
	std::cin >> num_T;

	std::vector<Teacher> vecT(num_T);
	for (Teacher &t : vecT) {
		t.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string match;
		std::getline(std::cin >> std::ws, match);

		const std::regex regex(".*(" + match + ").*$", //
		                       std::regex_constants::icase);

		std::cout << "DANH SACH GIANG VIEN THEO TU KHOA " << match << ":\n";

		for (const Teacher &t : vecT)
			if (std::regex_match(t.get_name(), regex)) {
				t.print();
			}

		std::cout.flush();
	}

	return 0;
}

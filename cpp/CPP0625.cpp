/*
Danh sách giảng viên Khoa CNTT cần được sắp xếp lại theo tên. Thông tin về giảng viên ban đầu chỉ có
họ tên và Bộ môn. Mã giảng viên tự động tăng, tính từ GV01.

Cần sắp xếp lại theo tên (tức là từ cuối cùng trong xâu họ tên). Các giảng viên có cùng tên thì được
sắp xếp theo mã giảng viên.

Input
Dòng đầu ghi số giảng viên.
Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).

Output
Danh sách đã sắp xếp trong đó mỗi giảng viên ghi trên một dòng. Mã được tự động điền theo thứ tự
nhập, bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở dạng in hoa.

Ví dụ

Input
3
Nguyen Manh Son
Cong nghe phan mem
Vu Hoai Nam
Khoa hoc may tinh
Dang Minh Tuan
An toan thong tin

Ouput
GV02 Vu Hoai Nam KHMT
GV01 Nguyen Manh Son CNPM
GV03 Dang Minh Tuan ATTT
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Teacher {

	std::string name, last_name, subject;
	size_t id;

public:

	static int comparator(const Teacher &t1, const Teacher &t2) {

		if (t1.last_name != t2.last_name) {
			return t1.last_name < t2.last_name;
		}

		return t1.id < t2.id;
	}

	friend std::istream &operator>>(std::istream &is, Teacher &t) {

		static size_t id = 0;
		t.id = ++id;

		std::getline(is >> std::ws, t.name);

		std::string buf;
		std::vector<std::string> tok;
		std::istringstream iss(t.name);
		while (iss >> std::ws >> buf) {
			tok.push_back(buf);
		}

		t.last_name = tok.back();

		std::string subject_name;
		std::getline(is >> std::ws, subject_name);

		t.subject.clear();
		iss = std::istringstream(subject_name);
		while (iss >> std::ws >> buf) {
			t.subject.push_back(toupper(buf[0]));
		}

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const Teacher &t) {

		std::string id = std::to_string(t.id);
		while (id.length() < 2) id = '0' + id;
		id = "GV" + id;

		os << id << ' ' << t.name << ' ' << t.subject << '\n';

		return os;
	}
};

int main(void) {

	size_t ele;
	std::cin >> ele;

	std::vector<Teacher> vect(ele);
	for (Teacher &t : vect) {
		std::cin >> t;
	}

	std::sort(vect.begin(), vect.end(), Teacher::comparator);

	for (const Teacher &t : vect) {
		std::cout << t;
	}
	std::cout.flush();

	return 0;
}

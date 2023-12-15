/*
Thông tin về mỗi sinh viên gồm:

Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau.
Họ và tên: độ dài không quá 100
Lớp: dãy ký tự không có khoảng trống (không quá 15)
Email: dãy ký tự không có khoảng trống (không quá 15)
Hãy nhập danh sách sinh viên và sắp xếp theo lớp tăng dần (thứ tự từ điển)

Input
Dòng đầu ghi số sinh viên.
Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email.
Có không quá 1000 sinh viên trong danh sách.

Output
Ghi ra danh sách sinh viên đã sắp xếp theo lớp. Mỗi sinh viên trên một dòng, các thông tin cách nhau
một khoảng trống.
Nếu 2 sinh viên có cùng lớp thì sắp xếp theo mã tăng dần (thứ tự từ điển)

Ví dụ

Input:
4
B16DCCN011
Nguyen Trong Duc Anh
D16CNPM1
sv1@stu.ptit.edu.vn
B15DCCN215
To Ngoc Hieu
D15CNPM3
sv2@stu.ptit.edu.vn
B15DCKT150
Nguyen Ngoc Son
D15CQKT02-B
sv3@stu.ptit.edu.vn
B15DCKT199
Nguyen Trong Tung
D15CQKT03-B
sv4@stu.ptit.edu.vn

Output:
B15DCCN215 To Ngoc Hieu D15CNPM3 sv2@stu.ptit.edu.vn
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@stu.ptit.edu.vn
B15DCKT199 Nguyen Trong Tung D15CQKT03-B sv4@stu.ptit.edu.vn
B16DCCN011 Nguyen Trong Duc Anh D16CNPM1 sv1@stu.ptit.edu.vn
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Student {

	std::string id, name, grade, email;

public:

	bool operator<(const Student &other) const {

		if (grade != other.grade) {
			return grade < other.grade;
		}

		return id < other.id;
	}

	void input(std::istream &is) {

		for (std::string *s : { &id, &name, &grade, &email }) {
			std::getline(is >> std::ws, *s);
		}
	}

	void print(void) const {
		std::cout << id << ' ' << name << ' ';
		std::cout << grade << ' ' << email << '\n';
	}
};

int main(void) {

	size_t ele;
	std::cin >> ele;

	std::vector<Student> vecs(ele);

	for (Student &s : vecs) {
		s.input(std::cin);
	}

	std::sort(vecs.begin(), vecs.end());

	for (const Student &s : vecs) {
		s.print();
	}
	std::cout.flush();

	return 0;
}

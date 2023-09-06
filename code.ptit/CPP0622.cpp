/*
Thông tin về mỗi sinh viên gồm:

Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không
trùng nhau.
Họ và tên: độ dài không quá 100
Lớp: dãy ký tự không có khoảng trống (không quá 15)
Email: dãy ký tự không có khoảng trống (không quá 15)
Hãy nhập danh sách sinh viên và liệt kê sinh viên theo lớp

Input
Dòng đầu ghi số sinh viên (không quá 1000)
Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email.
Sau đó sẽ có giá trị số Q là số truy vấn
Tiếp theo là Q dòng, mỗi dòng ghi một lớp

Output
Với mỗi truy vấn, liệt kê danh sách sinh viên của lớp đó theo mẫu như trong ví
dụ. Mỗi sinh viên ghi trên một dòng, các thông tin cách nhau một khoảng trống.
Thứ tự sinh viên vẫn giữ nguyên như thứ tự ban đầu.

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
D15CQKT02-B
sv4@stu.ptit.edu.vn
1
D15CQKT02-B

Output:
DANH SACH SINH VIEN LOP D15CQKT02-B:
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@stu.ptit.edu.vn
B15DCKT199 Nguyen Trong Tung D15CQKT02-B sv4@stu.ptit.edu.vn
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct student {

	std::string id, name, grade, email;

	void input(void);
};

std::unordered_map<std::string, std::vector<student *>> mp_vec;

void student::input(void) {

	for (std::string *s : { &id, &name, &grade, &email }) {
		std::getline(std::cin >> std::ws, *s);
	}

	if (mp_vec.find(grade) == mp_vec.end()) {
		mp_vec[grade] = std::vector<student *>();
	}

	mp_vec[grade].push_back(this);
}

int main(void) {

	size_t num_stu;
	std::cin >> num_stu;

	std::vector<student> vec_stu(num_stu);
	for (student &s : vec_stu) {
		s.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string grade;
		std::cin >> std::ws >> grade;

		std::cout << "DANH SACH SINH VIEN LOP " << grade << ":\n";
		for (const student *s : mp_vec[grade]) {

			std::cout << s->id << ' ' << s->name << ' ';
			std::cout << s->grade << ' ' << s->email << '\n';
		}

		std::cout.flush();
	}

	return 0;
}

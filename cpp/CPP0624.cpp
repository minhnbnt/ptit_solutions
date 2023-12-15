/*
Thông tin về mỗi sinh viên gồm:

Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau.
Họ và tên: độ dài không quá 100
Lớp: dãy ký tự không có khoảng trống (không quá 15)
Email: dãy ký tự không có khoảng trống (không quá 50)
Hãy nhập danh sách sinh viên và liệt kê sinh viên theo ngành học. Chú ý: dữ liệu ngành học thể hiện
qua 4 chữ cái từ thứ 4 đến thứ 7 trong mã sinh viên.

Input
Dòng đầu ghi số sinh viên (không quá 1000)
Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email.
Sau đó sẽ có giá trị số Q là số truy vấn

Tiếp theo là Q dòng, mỗi dòng ghi ngành đào tạo. Chỉ có các ngành đào tạo trong danh sách sau (trong
Input sẽ không có dấu):

Kế toán – mã sinh viên có cụm ký tự DCKT
Công nghệ thông tin – mã sinh viên có cụm DCCN – trừ đi các sinh viên lớp bắt đầu bằng chữ E
An toàn thông tin – mã sinh viên có cụm DCAT – trừ các sinh viên lớp bắt đầu bằng chữ E
Viễn thông – mã sinh viên có cụm DCVT
Điện tử - mã sinh viên có cụm DCDT

Output
Với mỗi truy vấn, liệt kê danh sách sinh viên của khóa đó theo mẫu như trong ví dụ. Mỗi sinh viên
ghi trên một dòng, các thông tin cách nhau một khoảng trống. Thứ tự sinh viên vẫn giữ nguyên như thứ
tự ban đầu.

Ví dụ

Input
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
Ke toan

Output
DANH SACH SINH VIEN NGANH KE TOAN:
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@stu.ptit.edu.vn
B15DCKT199 Nguyen Trong Tung D15CQKT02-B sv4@stu.ptit.edu.vn
*/

#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

class Student {

	std::string id, name, grade, email;

public:

	void print(void) const {
		std::cout << id << ' ' << name << ' ';
		std::cout << grade << ' ' << email << '\n';
	}

	void input(void);
};

std::unordered_map<std::string, std::vector<Student *>> map;

void Student::input(void) {

	for (std::string *s : { &id, &name, &grade, &email }) {
		std::getline(std::cin >> std::ws, *s);
	}

	const std::string group = id.substr(3, 4);

	if (grade[0] == 'E' && (group == "DCCN" || group == "DCAT")) {
		return;
	}

	if (map.find(group) == map.end()) {
		map[group] = std::vector<Student *>();
	}

	map[group].push_back(this);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t num_stu;
	std::cin >> num_stu;

	std::vector<Student> vec(num_stu);
	for (Student &s : vec) {
		s.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string group;
		std::getline(std::cin >> std::ws, group);

		for (char &c : group) {
			c = toupper(c);
		}

		static const std::unordered_map<std::string, std::string> id_map = {
			{ "CONG NGHE THONG TIN", "DCCN" },
			{ "AN TOAN THONG TIN", "DCAT" },
			{ "VIEN THONG", "DCVT" },
			{ "KE TOAN", "DCKT" },
			{ "DIEN TU", "DCDT" }
		};

		std::cout << "DANH SACH SINH VIEN NGANH " << group << ":\n";

		for (const Student *p : map[id_map.at(group)]) {
			p->print();
		}
		std::cout.flush();
	}

	return 0;
}

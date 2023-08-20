/*
Thông tin về mỗi sinh viên gồm:

Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không
trùng nhau.
Họ và tên: độ dài không quá 100
Lớp: dãy ký tự không có khoảng trống (không quá 15)
Email: dãy ký tự không có khoảng trống (không quá 15)
Hãy nhập danh sách sinh viên và sắp xếp theo mã sinh viên tăng dần (thứ tự từ
điển)

Input:
Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email.
Không cho biết số sinh viên nhưng dữ liệu đảm bảo là chẵn lần 4 dòng.
Có không quá 1000 sinh viên trong danh sách.

Output
Ghi ra danh sách sinh viên đã sắp xếp theo mã. Mỗi sinh viên trên một dòng, các
thông tin cách nhau một khoảng trống.

Ví dụ

Input:
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

using namespace std;

struct student {

	string id, grade;
	string name, email;

	student(string id, string name, string grade, string email)
	    : id(id), name(name), grade(grade), email(email) {}
};

int cmp(const student &a, const student &b) {
	return a.id < b.id;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<student> vec;

	while (!cin.eof()) {

		string id, grade;
		string name, email;

		cin >> ws >> id;

		getline(cin >> ws, name);

		cin >> ws >> grade >> ws >> email;

		vec.emplace_back(id, name, grade, email);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (const student &s : vec)
		cout << s.id << ' ' << s.name << ' ' //
		     << s.grade << ' ' << s.email << '\n';
	cout << flush;

	return 0;
}

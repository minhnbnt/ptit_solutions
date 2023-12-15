/*
Thông tin về giảng viên Khoa CNTT ban đầu chỉ có họ tên và Bộ môn. Mã giảng viên sẽ tự động điền
tăng dần, tính từ GV01.

Hãy liệt kê danh sách giảng viên của Bộ môn được yêu cầu.

Input
Dòng đầu ghi số giảng viên.
Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).
Tiếp theo là một dòng ghi số Q là số truy vấn.
Mỗi truy vấn là tên một bộ môn trên một dòng.

Output
Danh sách các giảng viên của bộ môn theo từng truy vấn, trong đó mỗi giảng viên ghi trên một dòng.
Mã được tự động điền theo thứ tự nhập, bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở
dạng in hoa.
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
Cong nghe phan mem

Output
DANH SACH GIANG VIEN BO MON CNPM:
GV01 Nguyen Manh Son CNPM
*/

#include <bits/stdc++.h>

using namespace std;

string abbveration(const string &s) {

	string result, tmp;
	istringstream iss(s);

	while (iss >> tmp) {
		result += toupper(tmp[0]);
	}

	return result;
}

string get_id(const char *head, size_t num, size_t len) {

	ostringstream oss;
	oss << setfill('0') << setw(len) << num;

	return head + oss.str();
}

class Teacher {

	string name, subject;
	size_t id;

public:

	void input(void);

	void print(void) const {

		cout << get_id("GV", id, 2) << ' ' << name;
		cout << ' ' << abbveration(subject) << '\n';
	}
};

unordered_map<string, vector<const Teacher *>> mp;

void Teacher::input(void) {

	static size_t id = 0;
	this->id = ++id;

	getline(cin >> ws, name);
	getline(cin >> ws, subject);

	const string abbr = abbveration(subject);

	auto it = mp.find(abbr);

	if (it != mp.end()) {
		it->second.push_back(this);
		return;
	}

	mp.emplace(abbr, vector<const Teacher *>());
	mp[abbr].push_back(this);
}

int main(void) {

	size_t i, num_teacher;
	cin >> num_teacher;

	auto ptr = make_unique<Teacher[]>(num_teacher);
	for (i = 0; i < num_teacher; ++i) {
		ptr[i].input();
	}

	unsigned cases;
	cin >> cases;

	while (cases-- > 0) {

		string subject;
		getline(cin >> ws, subject);

		const string abbr = abbveration(subject);

		cout << "DANH SACH GIANG VIEN BO MON " << abbr << ":\n";

		for (const Teacher *t : mp.at(abbr)) {
			t->print();
		}
	}

	return 0;
}

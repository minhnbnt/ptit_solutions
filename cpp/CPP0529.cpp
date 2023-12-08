/*
Sinh viên CNTT PTIT đến năm cuối được cử đi thực tập tại các doanh nghiệp.

Thông tin của mỗi sinh viên trong danh sách thực tập bao gồm:

Số thứ tự: là 1 số nguyên tự động tăng
Mã sinh viên: là một xâu ký tự không có khoảng trống, không quá 12 ký tự
Họ tên: là một xâu ký tự họ tên đã chuẩn hóa, không quá 50 ký tự
Lớp: là một xâu ký tự không có khoảng trống, không quá 10 ký tự
Email: là một địa chỉ email, không có khoảng trống, không quá 100 ký tự
Doanh nghiệp: tên viết tắt của doanh nghiệp, không có khoảng trống, không quá 15
ký tự.
Hãy viết chương trình đọc vào danh sách thực tập sau đó in danh sách cho từng
doanh nghiệp theo yêu cầu.

Input
Dòng đầu ghi số N là sinh viên

Mỗi sinh viên ghi trên 5 dòng gồm mã, họ tên, lớp, email và doanh nghiệp.

Không có số thứ tự, cần tự gán theo thứ tự tăng dần từ 1.

Sau khi hết danh sách sinh viên sẽ có một số nguyên Q (không quá 5) cho biết
danh sách truy vấn.

Tiếp theo là Q dòng, mỗi dòng ghi tên một doanh nghiệp (đúng như trong danh
sách, không có trường hợp nào không tồn tại trong danh sách)

Output:
Với mỗi doanh nghiệp, liệt kê danh sách sinh viên thực tập ở doanh nghiệp đó
theo thứ tự sắp xếp mã sinh viên (so sánh theo thứ tự từ điển).

Mỗi sinh viên trên một dòng. Mỗi thông tin trong danh sách cách nhau đúng một
khoảng trống.

Ví dụ:
Input:
6
B17DCCN016
Le Khac Tuan Anh
D17HTTT2
test1@stu.ptit.edu.vn
VIETTEL
B17DCCN107
Dao Thanh Dat
D17CNPM5
test2@stu.ptit.edu.vn
FPT
B17DCAT092
Cao Danh Huy
D17CQAT04-B
test3@stu.ptit.edu.vn
FPT
B17DCCN388
Cao Sy Hai Long
D17CNPM2
test4@stu.ptit.edu.vn
VNPT
B17DCCN461
Dinh Quang Nghia
D17CNPM2
test5@stu.ptit.edu.vn
FPT
B17DCCN554
Bui Xuan Thai
D17CNPM1
test6@stu.ptit.edu.vn
GAMELOFT
1
FPT

Output:
3 B17DCAT092 Cao Danh Huy D17CQAT04-B test3@stu.ptit.edu.vn FPT
2 B17DCCN107 Dao Thanh Dat D17CNPM5 test2@stu.ptit.edu.vn FPT
5 B17DCCN461 Dinh Quang Nghia D17CNPM2 test5@stu.ptit.edu.vn FPT
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

struct Candidate {

	size_t id;

	std::string stu_id, name, grade;
	std::string email, corp;

	void print(void) {

		std::cout << id << ' ' << stu_id << ' ' << name << ' ';

		std::cout << grade << ' ' << email << ' ' << corp << '\n';
	}
};

int comparator(const Candidate *a, const Candidate *b) {
	return a->stu_id < b->stu_id;
}

std::unordered_map<std::string, std::list<Candidate *>> mp;

void input(Candidate &c) {

	static unsigned id = 0;
	c.id = ++id;

	for (std::string *buf : { &c.stu_id, &c.name, &c.grade, &c.email, &c.corp }) {
		std::getline(std::cin >> std::ws, *buf);
	}

	if (mp.find(c.corp) == mp.end()) {
		mp[c.corp] = std::list<Candidate *>();
	}

	mp[c.corp].push_back(&c);
}

int main(void) {

	size_t num_candidate;
	std::cin >> num_candidate;

	std::vector<Candidate> vec(num_candidate);
	for (Candidate &c : vec) {
		input(c);
	}

	size_t num_corp, i;
	std::cin >> num_corp;

	for (i = 0; i < num_corp; ++i) {

		std::string corp;
		std::cin >> std::ws >> corp;

		mp[corp].sort(comparator);
		for (Candidate *c : mp[corp]) {
			c->print();
		}

		std::cout.flush();
	}

	return 0;
}

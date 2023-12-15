/*
Để chuẩn bị cho đợt thực tập tốt nghiệp của sinh viên năm cuối, Khoa CNTT1 trao đổi với các doanh
nghiệp đối tác và chốt số lượng sinh viên có thể nhận thực tập.

Hãy sắp xếp các doanh nghiệp theo số lượng sinh viên có thể nhận giảm dần.

Input
Dòng đầu ghi số doanh nghiệp.

Mỗi doanh nghiệp ghi trên 3 dòng:
Mã doanh nghiệp (xâu ký tự không có dấu cách, độ dài không quá 10)
Tên doanh nghiệp (xâu ký tự độ dài không quá 150)
Số sinh viên có thể nhận: giá trị nguyên không quá 1000

Output
Ghi ra danh sách đã được sắp xếp theo số lượng giảm dần, mỗi thông tin ghi trên một dòng. Trong
trường hợp cùng số lượng thì sắp xếp theo mã doanh nghiệp (thứ tự từ điển tăng dần).

Ví dụ

Input
4
VIETTEL
TAP DOAN VIEN THONG QUAN DOI VIETTEL
40
FSOFT
CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE
300
VNPT
TAP DOAN BUU CHINH VIEN THONG VIET NAM
200
SUN
SUN*
50

Output
FSOFT CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE 300
VNPT TAP DOAN BUU CHINH VIEN THONG VIET NAM 200
SUN SUN* 50
VIETTEL TAP DOAN VIEN THONG QUAN DOI VIETTEL 40
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Corp {

	std::string id, name;
	unsigned candidates;

public:

	void input(void) {

		std::cin >> std::ws >> id;
		std::getline(std::cin >> std::ws, name);

		std::cin >> candidates;
	}

	void print(void) const {
		std::cout << id << ' ' << name << ' ' << candidates << '\n';
	}

	bool operator()(const Corp &c1, const Corp &c2) {

		if (c1.candidates != c2.candidates) {
			return c1.candidates > c2.candidates;
		}

		return c1.id < c2.id;
	}
};

class Solution {
public:
	static void main(void) {

		size_t num_corp;
		std::cin >> num_corp;

		std::vector<Corp> vec_corp(num_corp);
		for (Corp &c : vec_corp) {
			c.input();
		}

		std::sort(vec_corp.begin(), vec_corp.end(), Corp());

		for (const Corp &c : vec_corp) {
			c.print();
		}
		std::cout.flush();
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	Solution::main();

	return 0;
}

/*
Để chuẩn bị cho đợt thực tập tốt nghiệp của sinh viên năm cuối, Khoa CNTT1 trao đổi với các doanh
nghiệp đối tác và chốt số lượng sinh viên có thể nhận thực tập.

Hãy lọc ra các doanh nghiệp nhận số lượng sinh viên trong đoạn [a,b].

Input
Dòng đầu ghi số doanh nghiệp.

Mỗi doanh nghiệp ghi trên 3 dòng:
Mã doanh nghiệp (xâu ký tự không có dấu cách, độ dài không quá 10)
Tên doanh nghiệp (xâu ký tự độ dài không quá 150)
Số sinh viên có thể nhận: giá trị nguyên không quá 1000
Tiếp theo là một dòng ghi số truy vấn Q. Mỗi truy vấn là 2 số nguyên a, b viết trên một dòng trong
đó a<b và dữ liệu đảm bảo luôn có ít nhất 1 doanh nghiệp nhận số lượng sinh viên trong đoạn [a,b].

Output

Ghi ra danh sách đã lọc trong đoạn [a,b] và được sắp xếp theo số lượng giảm dần, mỗi thông tin ghi
trên một dòng. Trong trường hợp cùng số lượng thì sắp xếp theo mã doanh nghiệp (thứ tự từ điển tăng
dần).

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
1
30 50

Output
DANH SACH DOANH NGHIEP NHAN TU 30 DEN 50 SINH VIEN:
SUN SUN* 50
VIETTEL TAP DOAN VIEN THONG QUAN DOI VIETTEL 40
*/

#include <bits/stdc++.h>

using namespace std;

struct Corp {

	string id, name;
	unsigned candidates;

	bool operator<(const Corp &other) const {

		if (candidates != other.candidates) {
			return candidates > other.candidates;
		}

		return id < other.id;
	}

	void input(void) {

		getline(cin >> ws, id);
		getline(cin >> ws, name);

		cin >> candidates;
	}

	void print(void) const {

		cout << id << ' ' << name << ' ';
		cout << candidates << '\n';
	}
};

int main(void) {

	size_t num_corp;
	cin >> num_corp;

	vector<Corp> vec_corp(num_corp);
	for (Corp &c : vec_corp) {
		c.input();
	}

	sort(vec_corp.begin(), vec_corp.end());

	unsigned cases;
	cin >> cases;

	while (cases-- > 0) {

		unsigned left, right;
		cin >> left >> right;

		cout << "DANH SACH DOANH NGHIEP NHAN TU ";
		cout << left << " DEN " << right << " SINH VIEN:\n";

		for (const Corp &c : vec_corp) {

			if (c.candidates < left || c.candidates > right) {
				continue;
			}

			c.print();
		}

		cout.flush();
	}

	return 0;
}

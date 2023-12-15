/*
Viết chương trình khai báo cấu trúc Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp, Ngày sinh và
Điểm GPA (dạng số thực float).

Đọc thông tin N sinh viên từ bàn phím (không có mã sinh viên) và in ra lần lượt màn hình mỗi dòng 1
sinh viên theo đúng thứ tự ban đầu. Trong đó Mã SV được tự tạo ra theo quy tắc thêm mã B20DCCN sau
đó là giá trị nguyên tự động tăng tính từ 001 (tối đa là 099). Ngày sinh được chuẩn hóa về dạng
dd/mm/yyyy

Input
Dòng đầu tiên ghi số sinh viên N (0 < N < 50).
Mỗi sinh viên ghi trên 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:
Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.

Output
Ghi ra danh sách lần lượt các sinh viên có đầy đủ Mã sinh viên, Họ tên, Lớp, Ngày sinh (đã chuẩn hóa
về dạng dd/mm/yyyy), Điểm GPA (với đúng 2 số sau dấu phẩy).
Mỗi sinh viên ghi trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Ví dụ
Input
1
Nguyen Van An
D20CQCN01-B
2/12/2002
3.19

Output
B20DCCN001 Nguyen Van An D20CQCN01-B 02/12/2002 3.19
*/

#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {

	float gpa;
	unsigned id;
	std::string name, grade, birth;

	std::string get_id(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 3) id = '0' + id;

		return "B20DCCN" + id;
	}

	void input(const unsigned id) {

		this->id = id;

		std::string raw_date;
		for (std::string *s : { &name, &grade, &raw_date }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::istringstream iss(raw_date);
		while (true) {

			std::string buf;
			std::getline(iss, buf, '/');

			while (buf.length() < 2) {
				buf = '0' + buf;
			}
			birth += buf;

			if (iss.eof()) break;

			birth += '/';
		}

		std::cin >> gpa;
	}

	void print(void) const {

		std::cout.precision(2);

		std::cout << get_id() << ' ' << name << ' ' << grade << ' ';
		std::cout << birth << ' ' << std::fixed << gpa << '\n';
	}
};

void nhap(struct SinhVien *ds, int N) {
	for (int i = 0; i < N; ++i) {
		ds[i].input(i + 1);
	}
}

void in(const struct SinhVien *ds, int N) {

	for (int i = 0; i < N; ++i) {
		ds[i].print();
	}

	std::cout.flush();
}

using std::cin;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct SinhVien ds[50];
	int N;
	cin >> N;
	nhap(ds, N);
	in(ds, N);
	return 0;
}

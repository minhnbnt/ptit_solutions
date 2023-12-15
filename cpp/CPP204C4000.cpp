/*
Viết chương trình khai báo cấu trúc Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp, Ngày sinh và
Điểm GPA (dạng số thực float).

Đọc thông tin 1 sinh viên từ bàn phím (không có mã sinh viên) và in ra màn hình. Trong đó Mã SV được
gán là N20DCCN001. Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy.

Input
Gồm 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:
Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với nhiều nhất 2 số sau dấu phẩy.

Output
Ghi thông tin sinh viên trên 1 dòng, mỗi thông tin cách nhau 1 Tab.

Ví dụ

Input
Nguyen Van A
D20CQCN01-N
2/2/2000
2.5

Output
N20DCCN001 Nguyen Van A D20CQCN01-N 02/02/2000 2.50
*/

#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
	std::string name, id, birth;
	float GPA;
};

void nhapThongTinSV(SinhVien &a) {

	std::string raw_date, buf;

	for (std::string *s : { &a.name, &a.id, &raw_date }) {
		std::getline(std::cin >> std::ws, *s);
	}
	std::cin >> a.GPA;

	std::istringstream iss(raw_date);
	while (std::getline(iss, buf, '/')) {

		while (buf.length() < 2) buf = '0' + buf;

		a.birth += buf;

		if (iss.eof()) return;

		a.birth.push_back('/');
	}
}

void inThongTinSV(const SinhVien &a) {

	std::cout.precision(2);

	std::cout << "N20DCCN001 " << a.name << ' ' << a.id << ' ';
	std::cout << a.birth << ' ' << std::fixed << a.GPA << '\n';
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct SinhVien a;
	nhapThongTinSV(a);
	inThongTinSV(a);
	return 0;
}

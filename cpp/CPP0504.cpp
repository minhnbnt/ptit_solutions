/*
Viết chương trình khai báo cấu trúc Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp, Ngày sinh và
Điểm GPA (dạng số thực float).

Đọc thông tin 1 sinh viên từ bàn phím (không có mã sinh viên) và in ra màn hình. Trong đó Mã SV được
gán là B20DCCN001. Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy.

Input
Gồm 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:
Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.

Output
Ghi thông tin sinh viên trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Ví dụ
Input
Nguyen Hoa Binh
D20CQCN04-B
2/2/2002
2

Output
B20DCCN001 Nguyen Hoa Binh D20CQCN04-B 02/02/2002 2.00
*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
	std::string name, grade, birth;
	float GPA;
};

void nhap(SinhVien &s) {

	std::getline(std::cin >> std::ws, s.name);
	std::getline(std::cin >> std::ws, s.grade);

	std::string date, tmp;
	std::getline(std::cin >> std::ws, date);

	std::istringstream iss(date);
	while (true) {

		std::getline(iss >> std::ws, tmp, '/');
		s.birth += tmp.size() < 2 ? '0' + tmp : tmp;

		if (iss.eof()) break;
		s.birth += '/';
	}

	std::cin >> s.GPA;
}

void in(const SinhVien &s) {
	std::cout << "B20DCCN001 " << s.name << ' ' << s.grade //
	          << ' ' << s.birth << ' ' << ' ';

	std::cout.precision(2);
	std::cout << std::fixed << s.GPA << std::endl;
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct SinhVien a;
	nhap(a);
	in(a);
	return 0;
}

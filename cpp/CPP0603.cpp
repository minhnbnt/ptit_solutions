/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp, Ngày sinh và Điểm
GPA (dạng số thực float). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc
định (xâu ký tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng
sinh viên với cout.

Đọc thông tin 1 sinh viên từ bàn phím (không có mã sinh viên) và in ra màn hình. Trong đó Mã SV được
gán là B20DCCN001. Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy. Tên được đưa về dạng chuẩn.

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
NguyEn hoa BiNH
D20CQCN04-B
2/2/2002
2

Output
B20DCCN001 Nguyen Hoa Binh D20CQCN04-B 02/02/2002 2.00
*/

#include <iosfwd>
#include <string>

void proper(std::string &s) {

	for (char &c : s) {
		c = tolower(c);
	}

	s[0] = toupper(s[0]);
}

class SinhVien {

	std::string name, grade, birth;
	float GPA;

public:

	friend std::istream &operator>>(std::istream &is, SinhVien &s);
	friend std::ostream &operator<<(std::ostream &os, const SinhVien &s);
};

#include <iostream>
#include <sstream>

std::istream &operator>>(std::istream &is, SinhVien &s) {

	std::string raw_name, raw_date, buf;

	for (std::string *s : { &raw_name, &s.grade, &raw_date }) {
		std::getline(is >> std::ws, *s);
	}
	is >> s.GPA;

	std::istringstream iss(raw_name);

	while (iss >> buf) {

		proper(buf);

		s.name += buf;

		if (iss.eof()) {
			break;
		}

		s.name += ' ';
	}

	iss = std::istringstream(raw_date);

	while (std::getline(iss, buf, '/')) {

		while (buf.length() < 2) buf = '0' + buf;

		s.birth += buf;

		if (iss.eof()) {
			break;
		}

		s.birth.push_back('/');
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const SinhVien &s) {

	os.precision(2);

	os << "B20DCCN001 " << s.name << ' ' << s.grade << ' ';
	os << s.birth << ' ' << std::fixed << s.GPA << '\n';

	return os;
}

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	SinhVien a;
	cin >> a;
	cout << a;
	return 0;
}

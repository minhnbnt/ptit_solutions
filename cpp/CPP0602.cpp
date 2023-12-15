/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp, Ngày sinh và Điểm
GPA (dạng số thực float). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc
định (xâu ký tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng
sinh viên với cout.

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

#include <iostream>
#include <sstream>

void proper_date(std::string &date) {

	std::istringstream iss(date);
	date.clear();

	while (true) {

		std::string tmp;
		std::getline(iss, tmp, '/');

		while (tmp.size() < 2) {
			tmp = '0' + tmp;
		}

		date += tmp;

		if (iss.eof()) {
			break;
		}

		date += '/';
	}
}

class SinhVien {

	std::string name, grade, birth;
	float GPA;

public:

	friend void operator>>(std::istream &is, SinhVien &sv) {

		for (std::string *s : { &sv.name, &sv.grade, &sv.birth }) {
			std::getline(is >> std::ws, *s);
		}

		proper_date(sv.birth);

		is >> sv.GPA;
	}

	friend void operator<<(std::ostream &os, const SinhVien &sv) {

		os.precision(2);

		os << "B20DCCN001 " << sv.name << ' ' << sv.grade << ' ';
		os << sv.birth << ' ' << std::fixed << sv.GPA << '\n';
	}
};

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	SinhVien a;
	cin >> a;
	cout << a;
	return 0;
}

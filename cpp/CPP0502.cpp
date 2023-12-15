/*
Viết chương trình khai báo cấu trúc Thí Sinh gồm các thông tin: Họ tên, Điểm môn 1, Điểm môn 2, Điểm
môn 3 và Tổng điểm.

Đọc thông tin 1 thí sinh từ bàn phím và in ra màn hình 3 thông tin: Họ tên, Ngày sinh, Tổng điểm.

Input
Gồm 5 dòng lần lượt, mỗi dòng ghi 1 thông tin: Họ tên, Ngày sinh, Điểm môn 1, Điểm môn 2, Điểm
môn 3. Họ tên không quá 50 chữ cái, Ngày sinh viết đúng chuẩn dd/mm/yyyy. Các giá trị điểm là số
thực (float).

Output
Ghi ra Họ tên, Ngày sinh và Tổng điểm. Mỗi thông tin cách nhau một khoảng trống. Điểm được ghi ra
với 1 số sau dấu phẩy.

Ví dụ
Input
Nguyen Hoang Ha
11/10/2001
4.5
10.0
5.5

Output
Nguyen Hoang Ha 11/10/2001 20.0
*/

#include <iomanip>
#include <iostream>

struct ThiSinh {

	std::string name, birth;

	float a, b, c;
};

void nhap(struct ThiSinh &A) {

	std::getline(std::cin >> std::ws, A.name);

	std::getline(std::cin >> std::ws, A.birth);

	std::cin >> A.a >> A.b >> A.c;
}

void in(const struct ThiSinh &A) {

	std::cout.precision(1);

	std::cout << A.name << ' ' << A.birth << ' ';
	std::cout << std::fixed << A.a + A.b + A.c << '\n';
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct ThiSinh A;
	nhap(A);
	in(A);
	return 0;
}

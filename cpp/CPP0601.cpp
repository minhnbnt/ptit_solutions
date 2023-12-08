/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp,
Ngày sinh và Điểm GPA (dạng số thực float). Hàm khởi tạo không có tham số, gán
các giá trị thuộc tính ở trạng thái mặc định (xâu ký tự rỗng, giá trị số bằng
0).

Đọc thông tin 1 sinh viên từ bàn phím (không có mã sinh viên) và in ra màn hình.
Trong đó Mã SV được gán là B20DCCN001. Ngày sinh được chuẩn hóa về dạng
dd/mm/yyyy.

Input:
Gồm 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:
Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.

Output
Ghi thông tin sinh viên trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Ví dụ:
Input:
Nguyen Van A
D20CQCN04-B
2/2/2002
2

Output:
B20DCCN001 Nguyen Van A D20CQCN04-B 02/02/2002 2.00
*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SinhVien {

	float GPA;
	string HoTen, Lop, NgSinh;

	public:

	void nhap(void) {

		getline(cin >> ws, this->HoTen);

		getline(cin >> ws, this->Lop);

		getline(cin >> ws, this->NgSinh);

		cin >> GPA;
	}

	void xuat(void) {

		string token;
		vector<string> vec_str;
		istringstream iss(this->NgSinh);

		while (getline(iss, token, '/')) {
			vec_str.push_back(token);
		}
		for (string *p : { &vec_str[0], &vec_str[1] })
			if (p->length() < 2) *p = '0' + *p;

		cout.precision(2);
		cout << "B20DCCN001 " << this->HoTen << ' ' << this->Lop << ' ';
		cout << vec_str[0] << '/' << vec_str[1] << '/' << vec_str[2];
		cout << ' ' << fixed << this->GPA << endl;
	}
};

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	SinhVien a;
	a.nhap();
	a.xuat();
	return 0;
}

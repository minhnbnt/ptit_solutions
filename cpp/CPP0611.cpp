/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp và Điểm GPA (dạng số
thực float). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc định (xâu ký
tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng
sinh viên với cout.

Đọc thông tin N thí sinh từ bàn phím (không có mã sinh viên) và in ra lần lượt màn hình mỗi dòng 1
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

class SinhVien {

	size_t id;
	float GPA;
	std::string name, grade, birth;

	static std::string proper_date(const std::string &date) {

		std::string buf, propered;
		std::istringstream iss(date);

		while (std::getline(iss >> std::ws, buf, '/')) {

			if (buf.length() < 2) buf = '0' + buf;

			propered += buf;

			if (!iss.eof()) propered += '/';
		}

		return propered;
	}

public:

	friend std::istream &operator>>(std::istream &is, SinhVien &s) {

		static size_t id = 0;
		s.id = ++id;

		for (std::string *s : { &s.name, &s.grade, &s.birth }) {
			std::getline(is >> std::ws, *s);
		}

		s.birth = proper_date(s.birth);

		is >> s.GPA;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const SinhVien &s) {

		os.precision(2);

		std::string id = std::to_string(s.id);
		while (id.length() < 3) id = '0' + id;

		id = "B20DCCN" + id;

		os << id << ' ' << s.name << ' ' << s.grade << ' ';
		os << s.birth << ' ' << std::fixed << s.GPA << '\n';

		return os;
	}
};

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	SinhVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ds[i];
	}
	for (i = 0; i < N; i++) {
		cout << ds[i];
	}
	return 0;
}

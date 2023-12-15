/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp và Điểm GPA (dạng số
thực float). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc định (xâu ký
tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng
sinh viên với cout.

Đọc thông tin N thí sinh từ bàn phím (không có mã sinh viên) và in ra lần lượt màn hình mỗi dòng 1
sinh viên theo đúng thứ tự ban đầu. Trong đó Mã SV được tự tạo ra theo quy tắc thêm mã B20DCCN sau
đó là giá trị nguyên tự động tăng tính từ 001 (tối đa là 099). Họ tên được xử lý đưa về dạng chuẩn.
Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy

Input
Dòng đầu tiên ghi số sinh viên N (0 < N < 50).
Mỗi sinh viên ghi trên 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:

Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.

Output
Ghi ra danh sách lần lượt các sinh viên có đầy đủ Mã sinh viên, Họ tên, Lớp, Ngày sinh (đã chuẩn
hóa), điểm GPA (với đúng 2 số sau dấu phẩy).

Mỗi sinh viên ghi trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Ví dụ
Input
1
nGuyEn  vaN    biNH
D20CQCN01-B
2/12/2002
3.1

Output
B20DCCN001 Nguyen Van Binh D20CQCN01-B 02/12/2002 3.10
*/

#include <iostream>
#include <sstream>

class SinhVien {

	std::string name, grade, birth;
	unsigned id;
	float GPA;

public:

	const std::string get_id(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 3) id = '0' + id;

		return "B20DCCN" + id;
	}

	static void proper_date(std::string &date) {

		std::istringstream iss(date);
		date.clear();

		while (true) {

			std::string buf;
			std::getline(iss, buf, '/');

			while (buf.length() < 2) {
				buf = '0' + buf;
			}

			date.append(buf);

			if (iss.eof()) {
				return;
			}

			date.push_back('/');
		}
	}

	static void proper_name(std::string &name) {

		std::istringstream iss(name);
		name.clear();

		while (true) {

			std::string buf;
			iss >> buf;

			for (char &c : buf) {
				c = tolower(c);
			}
			buf[0] = toupper(buf[0]);

			name.append(buf);

			if (iss.eof()) {
				break;
			}

			name.push_back(' ');
		}
	}

	friend std::istream &operator>>(std::istream &is, SinhVien &sv) {

		static unsigned id = 0;
		sv.id = ++id;

		for (std::string *s : { &sv.name, &sv.grade, &sv.birth }) {
			std::getline(is >> std::ws, *s);
		}

		proper_date(sv.birth), proper_name(sv.name);

		is >> sv.GPA;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const SinhVien &sv) {

		os.precision(2);

		os << sv.get_id() << ' ' << sv.name << ' ' << sv.grade << ' ';
		os << sv.birth << ' ' << std::fixed << sv.GPA << '\n';

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

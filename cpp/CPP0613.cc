/*
Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp và Điểm GPA (dạng số
thực float). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc định (xâu ký
tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng
sinh viên với cout.

Đọc thông tin N thí sinh từ bàn phím (không có mã sinh viên) sau đó sắp xếp theo điểm GPA giảm dần
và in ra lần lượt màn hình mỗi dòng 1 sinh viên.

Trong đó Mã SV được tự tạo ra theo quy tắc thêm mã B20DCCN sau đó là giá trị nguyên tự động tăng
tính từ 001 (tối đa là 099). Họ tên được xử lý đưa về dạng chuẩn. Ngày sinh được chuẩn hóa về dạng
dd/mm/yyyy

Input
Dòng đầu tiên ghi số sinh viên N (0 < N < 50).
Mỗi sinh viên ghi trên 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:
Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.
Dữ liệu đảm bảo không có hai sinh viên nào có điểm GPA bằng nhau.

Output
Ghi ra danh sách lần lượt các sinh viên có đầy đủ Mã sinh viên, Họ tên, Lớp, Ngày sinh (đã chuẩn
hóa), điểm GPA (với đúng 2 số sau dấu phẩy) đã được sắp xếp theo điểm GPA giảm dần.

Mỗi sinh viên ghi trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Ví dụ
Input
2
ngUYen Van NaM
D20DCCN01-B
2/12/2002
2.17
Nguyen QuanG hAi
D20DCCN02-B
1/9/2002
3.0

Output
B20DCCN002 Nguyen Quang Hai D20DCCN02-B 01/09/2002 3.00
B20DCCN001 Nguyen Van Nam D20DCCN01-B 02/12/2002 2.17
*/

#include <algorithm>
#include <iostream>
#include <sstream>

class SinhVien {

	std::string name, grade, date;
	unsigned id;
	float GPA;

public:

	const std::string id_str(std::string head) const {

		std::string result = std::to_string(id);
		while (result.length() < 3) result = '0' + result;

		return head + result;
	}

	static bool comparator(const SinhVien &s1, const SinhVien &s2) {
		return s1.GPA > s2.GPA;
	}

	static const std::string proper_name(const std::string raw_name) {

		std::string result, buf;
		std::istringstream iss(raw_name);

		while (true) {

			iss >> buf;

			for (char &c : buf) {
				c = tolower(c);
			}
			buf[0] = toupper(buf[0]);

			result.append(buf);

			if (iss.eof()) break;

			result.push_back(' ');
		}

		return std::move(result);
	}

	static const std::string proper_date(const std::string raw_date) {

		std::string result, buf;
		std::istringstream iss(raw_date);

		while (std::getline(iss, buf, '/')) {

			while (buf.length() < 2) {
				buf = '0' + buf;
			}

			result.append(buf);

			if (iss.eof()) break;

			result.push_back('/');
		}

		return std::move(result);
	}

	friend std::istream &operator>>(std::istream &is, SinhVien &sv) {

		static unsigned id = 0;
		sv.id = ++id;

		std::string raw_name, raw_date;
		for (std::string *s : { &raw_name, &sv.grade, &raw_date }) {
			std::getline(std::cin >> std::ws, *s);
		}
		std::cin >> sv.GPA;

		sv.name = SinhVien::proper_name(raw_name);
		sv.date = SinhVien::proper_date(raw_date);

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, SinhVien &sv) {

		os.precision(2);

		os << sv.id_str("B20DCCN") << ' ' << sv.name << ' ' << sv.grade;
		os << ' ' << sv.date << ' ' << std::fixed << sv.GPA << '\n';

		return os;
	}
};

void sapxep(SinhVien *ds, int N) {
	std::sort(ds, ds + N, SinhVien::comparator);
}

using std::cin, std::cout;

int main() {
	SinhVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ds[i];
	}
	sapxep(ds, N);
	for (i = 0; i < N; i++) {
		cout << ds[i];
	}
	return 0;
}

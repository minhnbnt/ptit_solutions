/*
Viết chương trình khai báo cấu trúc Sinh Viên gồm các thông tin: Mã SV, Họ tên, Ngày sinh, Lớp và
Điểm GPA (dạng số thực float).

Đọc thông tin N sinh viên từ bàn phím (không có mã sinh viên) sau đó sắp xếp theo điểm GPA giảm dần
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
2/12/1994
2.17
Nguyen QuanG hAi
D20DCCN02-B
1/9/1994
3.0

Output
B20DCCN002 Nguyen Quang Hai D20DCCN02-B 01/09/1994 3.00
B20DCCN001 Nguyen Van Nam D20DCCN01-B 02/12/1994 2.17
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

void proper_name(std::string &name) {

	std::istringstream iss(name);
	name.clear();

	std::string token;
	while (iss >> token) {

		for (char &c : token) {
			c = tolower(c);
		}

		token[0] = toupper(token[0]);

		name.append(token);

		if (!iss.eof()) {
			name.push_back(' ');
		}
	}
}

void proper_date(std::string &date) {

	std::istringstream iss(date);
	date.clear();

	std::string token;

	while (std::getline(iss, token, '/')) {

		if (iss.eof()) {
			date.append(token);
			break;
		}

		if (token.length() == 1) {
			token = '0' + token;
		}

		date.append(token);
		date.push_back('/');
	}
}

struct SinhVien {

	std::string id, name, grade, birth;
	float GPA;

	void input(void) {

		for (std::string *s : { &name, &grade, &birth }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::cin >> GPA;

		static size_t id = 0;

		std::string id_str = std::to_string(++id);
		while (id_str.length() < 3) {
			id_str = '0' + id_str;
		}

		this->id = "B20DCCN" + id_str;

		proper_name(name);
		proper_date(birth);
	}

	void print(void) {

		std::cout << id << ' ' << name << ' ' << grade << ' ';
		std::cout << birth << ' ' << std::fixed << GPA << '\n';
	}

	bool operator<(const SinhVien &other) const {
		return GPA > other.GPA;
	}
};

void nhap(SinhVien *ds, int N) {

	for (int i = 0; i < N; ++i) {
		ds[i].input();
	}
}

void sapxep(SinhVien *ds, int N) {
	std::sort(ds, ds + N);
}

void in(SinhVien *ds, int N) {

	std::cout.precision(2);

	for (int i = 0; i < N; ++i) {
		ds[i].print();
	}
}

using std::cin;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct SinhVien ds[50];
	int N;
	cin >> N;
	nhap(ds, N);
	sapxep(ds, N);
	in(ds, N);
	return 0;
}

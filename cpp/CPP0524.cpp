/*
Cho dữ liệu bảng điểm thành phần trong đó thông tin của mỗi sinh viên gồm:

Mã sinh viên (xâu ký tự độ dài không quá 15, không có khoảng trống)
Tên sinh viên (xâu ký tự, độ dài không quá 50)
Lớp (xâu ký tự độ dài không quá 15, không có khoảng trống)
Điểm 1, Điểm 2, Điểm 3: mỗi điểm là một số thực (hệ 10)
Hãy sắp xếp lại bảng điểm thành phần theo mã sinh viên (thứ tự từ điển tăng dần).

Input
Dòng đầu ghi số sinh viên (không quá 100).
Mỗi sinh viên ghi trên 6 dòng lần lượt là: Mã SV, Họ tên, Lớp, Điểm 1, Điểm 2, Điểm 3.

Output
Ghi ra danh sách sinh viên đã sắp xếp theo mã sinh viên.
Mỗi sinh viên ghi trên 1 dòng gồm các thông tin: thứ tự, mã sv, họ tên, lớp, điểm 1, điểm 2, điểm 3.
Các thông tin cách nhau đúng một khoảng trống.
Các giá trị điểm ghi ra với đúng 1 chữ số phần thập phân.

Ví dụ

Input
3
B20DCCN999
Nguyen Van An
D20CQCN04-B
10.0
9.0
8.0
B20DCAT001
Le Van Nam
D20CQAT02-B
6.0
6.0
4.0
B20DCCN111
Tran Hoa Binh
D20CQCN04-B
9.0
5.0
6.0

Output
1 B20DCAT001 Le Van Nam D20CQAT02-B 6.0 6.0 4.0
2 B20DCCN111 Tran Hoa Binh D20CQCN04-B 9.0 5.0 6.0
3 B20DCCN999 Nguyen Van An D20CQCN04-B 10.0 9.0 8.0
*/

#include <algorithm>
#include <iostream>
#include <string>

struct SinhVien {

	float scores[3];
	std::string id, name, grade;

	void print(void) const {

		static size_t id = 0;

		std::cout << ++id << ' ' << this->id << ' ' << name;
		std::cout << ' ' << grade << std::fixed;

		for (const float &score : scores) {
			std::cout << ' ' << score;
		}

		std::cout.put(0xa);
	}
};

void nhap(SinhVien &sv) {

	for (std::string *s : { &sv.id, &sv.name, &sv.grade }) {
		std::getline(std::cin >> std::ws, *s);
	}

	for (float &score : sv.scores) {
		std::cin >> score;
	}
}

void sap_xep(SinhVien *ds, const size_t &size) {

	static auto comparator = [](const SinhVien &s1, const SinhVien &s2) { return s1.id < s2.id; };

	std::sort(ds, ds + size, comparator);
}

void in_ds(const SinhVien *ds, const size_t &size) {

	std::cout.precision(1);

	for (size_t i = 0; i < size; ++i) {
		ds[i].print();
	}

	std::cout.flush();
}

using std::cin;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	int n;
	cin >> n;
	struct SinhVien *ds = new SinhVien[n];
	for (int i = 0; i < n; i++) {
		nhap(ds[i]);
	}
	sap_xep(ds, n);
	in_ds(ds, n);
	return 0;
}

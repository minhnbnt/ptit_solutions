/*
Cho dữ liệu bảng điểm thành phần trong đó thông tin của mỗi sinh viên gồm:

Mã sinh viên (xâu ký tự độ dài không quá 15, không có khoảng trống)
Họ tên sinh viên (xâu ký tự, độ dài không quá 50)
Lớp (xâu ký tự độ dài không quá 15, không có khoảng trống)
Điểm 1, Điểm 2, Điểm 3: mỗi điểm là một số thực (hệ 10)
Hãy sắp xếp lại bảng điểm thành phần theo họ tên (thứ tự từ điển tăng dần - so sánh cả xâu ký tự họ
tên để sắp xếp, không cần tách tên).

Input
Dòng đầu ghi số sinh viên (không quá 100).
Mỗi sinh viên ghi trên 6 dòng lần lượt là: Mã SV, Họ tên, Lớp, Điểm 1, Điểm 2, Điểm 3.

Output
Ghi ra danh sách sinh viên đã sắp xếp theo họ tên.
Mỗi sinh viên ghi trên 1 dòng gồm các thông tin: thứ tự, mã sv, họ tên, lớp, điểm 1, điểm 2, điểm 3.
Các thông tin cách nhau đúng một khoảng trống. Các giá trị điểm ghi ra với đúng 1 chữ số phần thập
phân.

Ví dụ

Input
3
B20DCCN999
Nguyen Van Nam
D20CQCN04-B
10.0
9.0
8.0
B20DCAT001
Le Van An
D20CQAT02-B
6.0
6.0
4.0
B20DCCN111
Nguyen Van Binh
D20CQCN01-B
9.0
5.0
6.0

Output
1 B20DCAT001 Le Van An D20CQAT02-B 6.0 6.0 4.0
2 B20DCCN111 Nguyen Van Binh D20CQCN01-B 9.0 5.0 6.0
3 B20DCCN999 Nguyen Van Nam D20CQCN04-B 10.0 9.0 8.0
*/

#include <forward_list>
#include <iostream>

class Student {

	float scores[3];
	std::string id, name, grade;

public:

	static int comparator(const Student &s1, const Student &s2) {
		return s1.name < s2.name;
	}

	void input(void) {
		for (std::string *s : { &id, &name, &grade }) {
			std::getline(std::cin >> std::ws, *s);
		}

		for (float &score : scores) {
			std::cin >> score;
		}
	}

	void print(void) const {

		static unsigned id = 0;

		std::cout << ++id << ' ' << this->id << ' ' << name;
		std::cout << ' ' << grade << std::fixed;

		for (const float &score : scores) {
			std::cout << ' ' << score;
		}

		std::cout.put(10);
	}
};

int main(void) {

	size_t ele;
	std::cin >> ele;

	std::forward_list<Student> lss(ele);
	for (Student &s : lss) {
		s.input();
	}

	lss.sort(Student::comparator);

	std::cout.precision(1);

	for (const Student &s : lss) {
		s.print();
	}
	std::cout.flush();

	return 0;
}

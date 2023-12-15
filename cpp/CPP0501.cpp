/*
Viết chương trình khai báo cấu trúc điểm trong không gian hai chiều với hai tọa độ x và y (kiểu số
thực double).

struct Point{
     double x, y;
}

Nhập hai điểm A và B. Tính khoảng cách giữa hai điểm A, B với độ chính xác 4 chữ số sau dấu phẩy.

Input
Dòng đầu ghi số bộ test, không quá 20.
Mỗi bộ test có 4 số thực lần lượt là tọa độ của 2 điểm A và B, giá trị tuyệt đối không quá 1000.

Output
Với mỗi bộ test, viết ra khoảng cách giữa 2 điểm với 4 chữ số sau dấu phẩy.

Ví dụ
Input
2
0 0 0 5
0 199 5 6

Output
5.0000
193.0648
*/

#include <complex>
#include <iomanip>
#include <iostream>

using namespace std;

struct Point {
	double x, y;
};

void input(struct Point &p) {
	cin >> p.x >> p.y;
}

double distance(const struct Point &p, const struct Point &q) {
	double x = p.x - q.x, y = p.y - q.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct Point A, B;
	int t;
	cin >> t;
	while (t--) {
		input(A);
		input(B);
		cout << fixed << setprecision(4) << distance(A, B) << endl;
	}
	return 0;
}

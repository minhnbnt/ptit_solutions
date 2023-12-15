/*
Viết chương trình xây dựng class Phân số.

Sau đó thực hiện nhập vào một phân số và in ra phân số đó ở dạng tối giản.

Input
Có hai số nguyên dương lần lượt là tử số và mẫu số. Các giá trị không quá 18 chữ số.

Output
Ghi ra phân số tối giản như trong ví dụ

Ví dụ

Input
123 456

Output
41/152
*/

#include <algorithm>
#include <iostream>

class PhanSo {

	using i64 = long long;

	i64 tu, mau;

public:

	PhanSo(i64 tu, i64 mau) : tu(tu), mau(mau) {}

	void rutgon(void) {
		const long long gcd = std::__gcd(tu, mau);
		tu /= gcd, mau /= gcd;
	}

	friend void operator>>(std::istream &is, PhanSo &p) {
		is >> p.tu >> p.mau;
	}

	friend void operator<<(std::ostream &os, const PhanSo &p) {
		os << p.tu << '/' << p.mau << '\n';
	}
};

using std::cin, std::cout;

int main() {
	PhanSo p(1, 1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}

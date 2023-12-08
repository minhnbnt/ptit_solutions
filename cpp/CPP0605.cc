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

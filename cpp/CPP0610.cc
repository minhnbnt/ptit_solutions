#include <algorithm>
#include <iostream>

class PhanSo {

	using i64 = long long;

	i64 tu, mau;

public:

	PhanSo(i64 tu, i64 mau) : tu(tu), mau(mau) {}

	friend std::istream &operator>>(std::istream &is, PhanSo &ps) {
		is >> ps.tu >> ps.mau;
		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const PhanSo &ps) {
		os << ps.tu << '/' << ps.mau;
		return os;
	}

	PhanSo operator+(const PhanSo &ps) const {

		i64 mau = this->mau * ps.mau;
		i64 tu = this->tu * ps.mau + ps.tu * this->mau;

		const i64 gcd = std::__gcd(tu, mau);

		tu /= gcd, mau /= gcd;

		return PhanSo(tu, mau);
	}
};

using std::cin, std::cout;

int main() {
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}

#include <iostream>

using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

class PhanSo {

	i64 tu, mau;
public:
	PhanSo(i64 tu = 0, i64 mau = 1) : tu(tu), mau(mau) {}

	PhanSo &operator+(PhanSo b) {

		PhanSo *p = new PhanSo(), &c = *p;

		c.mau = this->mau * b.mau;
		c.tu = this->tu * b.mau + b.tu * this->mau;

		c.rutgon();

		return c;
	}

	void rutgon(void) {
		i64 tmp = gcd(this->tu, this->mau);
		this->tu /= tmp, this->mau /= tmp;
	}

	friend istream &operator>>(istream &is, PhanSo &ps) {
		is >> ps.tu >> ps.mau;
		return is;
	}

	friend ostream &operator<<(ostream &os, PhanSo &ps) {
		os << ps.tu << '/' << ps.mau << '\n';
		return os;
	}
};

int main() {
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}

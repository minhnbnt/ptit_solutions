#include <algorithm>
#include <iostream>

using i64 = long long;

struct PhanSo {
	i64 tu, mau;
};

void process(const PhanSo &a, const PhanSo &b) {

	PhanSo c, d;

	c.mau = a.mau * b.mau;
	c.tu = (a.tu * b.mau) + (b.tu * a.mau);

	c.tu *= c.tu, c.mau *= c.mau;

	i64 gcd = std::__gcd(c.tu, c.mau);
	c.tu /= gcd, c.mau /= gcd;

	std::cout << c.tu << '/' << c.mau << ' ';

	d.tu = a.tu * b.tu * c.tu;
	d.mau = a.mau * b.mau * c.mau;

	gcd = std::__gcd(d.tu, d.mau);
	d.tu /= gcd, d.mau /= gcd;

	std::cout << d.tu << '/' << d.mau << std::endl;
}

using std::cin;

int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}

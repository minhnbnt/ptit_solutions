#include <algorithm>
#include <iostream>

using i64 = long long;

struct PhanSo {
	i64 tu, mau;
};

void nhap(PhanSo &p) {
	std::cin >> p.tu >> p.mau;
}

PhanSo tong(const PhanSo &p, const PhanSo &q) {

	PhanSo t;

	t.tu = (p.tu * q.mau) + (p.mau * q.tu);
	t.mau = p.mau * q.mau;

	i64 div = std::__gcd(t.tu, t.mau);

	t.tu /= div, t.mau /= div;

	return t;
}

void in(const PhanSo &p) {
	std::cout << p.tu << '/' << p.mau << std::endl;
}

int main() {
	struct PhanSo p, q;
	nhap(p);
	nhap(q);
	PhanSo t = tong(p, q);
	in(t);
	return 0;
}

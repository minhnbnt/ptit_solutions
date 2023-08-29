#include <algorithm>
#include <iostream>

using i64 = long long;

struct PhanSo {
	i64 tu, mau;
};

void nhap(struct PhanSo &p) {
	std::cin >> p.tu >> p.mau;
}

void rutgon(struct PhanSo &p) {
	i64 div = std::__gcd(p.tu, p.mau);
	p.tu /= div, p.mau /= div;
}

void in(const struct PhanSo &p) {
	std::cout << p.tu << '/' << p.mau << '\n';
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct PhanSo p;
	nhap(p);
	rutgon(p);
	in(p);
	return 0;
}

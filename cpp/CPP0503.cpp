/*
Viết chương trình xây dựng cấu trúc Phân số gồm hai phần tử là tử số và mẫu số. Các giá trị đều
nguyên dương và không quá 18 chữ số.

Sau đó thực hiện nhập vào một phân số và in ra phân số đó ở dạng tối giản.

Input
Có hai số nguyên dương lần lượt là tử số và mẫu số.

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

using i64 = long long;

struct PhanSo {
	i64 tu, mau;
};

void nhap(struct PhanSo &p) {
	std::cin >> p.tu >> p.mau;
}

void rutgon(struct PhanSo &p) {
	const i64 div = std::__gcd(p.tu, p.mau);
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

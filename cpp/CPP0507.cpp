/*
Viết chương trình xây dựng cấu trúc Phân số gồm hai phần tử là tử số và mẫu số. Các giá trị đều
nguyên dương và không quá 9 chữ số.

Sau đó thực hiện nhập vào hai phân số p và q. Tính tổng p + q, rút gọn và in ra kết quả.

Input
Có bốn số nguyên dương lần lượt là tử số và mẫu số của p rồi đến q.

Output
Ghi ra phân số tổng p + q ở dạng tối giản như trong ví dụ

Ví dụ

Input
Output

123 456 12 34
1609/2584
*/

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

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct PhanSo p, q;
	nhap(p);
	nhap(q);
	PhanSo t = tong(p, q);
	in(t);
	return 0;
}

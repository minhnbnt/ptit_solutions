/*
Viết chương trình xây dựng class Phân số.

Sau đó thực hiện nhập vào hai phân số p và q. Tính tổng p + q, rút gọn và in ra
kết quả.

Input
Có bốn số nguyên dương lần lượt là tử số và mẫu số của p rồi đến q. Các giá trị
không quá 9 chữ số.

Output
Ghi ra phân số tổng p + q ở dạng tối giản như trong ví dụ

Ví dụ:
Input:
123 456 12 34

Output:
1609/2584
*/

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

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}

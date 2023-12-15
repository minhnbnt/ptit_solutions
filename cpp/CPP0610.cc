/*
Viết chương trình xây dựng class Phân số.

Sau đó thực hiện nhập vào hai phân số p và q. Tính tổng p + q, rút gọn và in ra kết quả.

Input
Có bốn số nguyên dương lần lượt là tử số và mẫu số của p rồi đến q. Các giá trị không quá 9 chữ số.

Output
Ghi ra phân số tổng p + q ở dạng tối giản như trong ví dụ

Ví dụ

Input
123 456 12 34

Output
1609/2584
*/

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

	PhanSo &rutgon(void) {

		i64 tmp = std::__gcd(this->tu, this->mau);
		this->tu /= tmp, this->mau /= tmp;

		return *this;
	}

	PhanSo operator+(const PhanSo &ps) const {

		i64 mau = this->mau * ps.mau;
		i64 tu = this->tu * ps.mau + ps.tu * this->mau;

		return PhanSo(tu, mau).rutgon();
	}
};

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}

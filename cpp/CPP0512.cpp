/*
Phân số là sự biểu diễn số hữu tỷ dưới dạng tỷ lệ của hai số nguyên, trong đó số ở trên được gọi là
tử số, còn số ở dưới được gọi là mẫu số. Cho hai phân số A và B có tử số và mẫu số được nhập từ bàn
phím.

Viết chương trình thực hiện hai nhiệm vụ sau:

Tính C = (A + B)2 và rút gọn kết quả.
Tính D = A x B x C và rút gọn kết quả.

Input:
Dòng đầu tiên là số bộ test T (T <= 100)

T dòng tiếp theo, mỗi dòng gồm 4 số lần lượt là tử và mẫu số của phân số A và phân số B
với -10^2 <= tử số, mẫu số <= 10^2. Mẫu số là số khác 0.

Output:

Kết quả của hai phép tính theo định dạng phân số.

Ví dụ

Input:
2
1 2 3 4
2 3 4 5

Output:
25/16 75/128
484/225 3872/3375
*/

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

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
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

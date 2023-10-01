/*
Cho ba số a, x, y. Nhiệm vụ của bạn là tìm ước số chung lớn nhất của hai số P và
Q, trong đó P lặp lại x lần số a và Q lặp lại y lần số a. Ví dụ a =2, x = 3, y
=2 thì P=222, Q=22.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp đưa các bộ test. Mỗi bộ test được viết trên một dòng là bộ ba số a,
x, y phân biệt nhau bởi một vài khoảng trống.

Các số T, a, x, y thỏa mãn ràng buộc: 1≤T≤100; 1≤ a, x, y≤10^18;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2 2 3
123 5 2

Output:
2
123
*/

#include <algorithm>
#include <iostream>
#include <string>

int main(void) {

	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x, y, i;
		std::string a;
		std::cin >> std::ws >> a >> x >> y;

		for (i = 0; i < std::__gcd(x, y); ++i) {
			std::cout << a;
		}
		std::cout << std::endl;
	}

	return 0;
}

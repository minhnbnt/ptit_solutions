/*
Cho ba số a, b, c có thể lớn cỡ 10^16. Nhiệm vụ của bạn là tính (a*b)%c.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test trên một dòng đưa vào ba số a, b, c.
T, a, b, c  thỏa mãn ràng buộc : 1≤T≤100; 0≤a, b, c≤10^16.

Output:
Đưa ra số kết quả mỗi test theo từng dòng.

Input:
1
8 4 5

Output:
2
*/

#include <iostream>

int main(void) {

	using u128 = __uint128_t;
	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		u64 a, b, c;
		std::cin >> a >> b >> c;

		const u64 result = static_cast<u128>(a) * b % c;
		std::cout << result << std::endl;
	}

	return 0;
}

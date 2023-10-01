/*
Cho bốn số nguyên dương X, Y, Z và N. Hãy tìm số nguyên dương nhỏ nhất có N chữ
số chia hết đồng thời cho X, Y, Z.  Ví dụ với X = 2, Y = 3, Z = 5, N = 4 ta tìm
được số nguyên dương nhỏ nhất có 4 chữ số là 1020 chia hết cho cả 2, 3, 5.

Input:
Dòng đầu tiên đưa vào số lượng test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là bộ bốn số X, Y, Z, N.

Các số X, Y, Z, N thỏa mãn ràng buộc dưới đây:
1≤ X, Y, Z ≤10^5; N≤18.

Output:
Đưa ra theo từng dòng kết quả mỗi test là số nguyên nhỏ nhất có N chữ số chia
hết đồng thời cho X, Y, Z. Trong trường hợp không có số nguyên N chữ số thỏa mãn
yêu cầu bài toán đưa ra giá trị -1.

Input:
3
2 3 5 4
4 5 6 3
3 5 7 2

Output:
1020
120
-1
*/

#include <algorithm>
#include <cmath>
#include <iostream>

int main(void) {

	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 arr[3];
		for (u64 &x : arr) {
			std::cin >> x;
		}

		int digits;
		std::cin >> digits;

		const u64 min = pow(10, digits - 1), max = min * 10 - 1;

		u64 base = 1;
		for (u64 &x : arr)
			if (base % x != 0) {
				base *= x / std::__gcd(base, x);
			}

		const u64 result = (((min - 1) / base) + 1) * base;

		if (result > max) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << result << std::endl;
	}

	return 0;
}

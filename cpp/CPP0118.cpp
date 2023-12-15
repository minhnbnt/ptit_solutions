/*
Số nguyên dương N được gọi là số Sphenic nếu N được phân tích duy nhất dưới dạng tích của ba số khác
nhau. Ví dụ N=30 là số Sphenic vì 30 = 2×3×5;  N = 60 không phải số Sphenic vì 60 = 2×2×3×5. Cho số
tự nhiên N, nhiệm vụ của bạn là kiểm tra xem N có phải số Spheic hay không?

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương N.
T, N thỏa mãn ràng buộc : 1≤T≤100; 1≤N≤10000.

Output:
Đưa ra 1 hoặc 0 tương ứng với N là số Sphenic hoặc không của mỗi test theo từng dòng.

Input:
2
30
60

Output:
1
0
*/

#include <complex>
#include <iostream>

using u64 = unsigned long long;

bool is_sphenic(u64 x) {
	int remaining = 3;

	for (u64 i = 2; i <= sqrt(x); ++i) {
		unsigned count = 0;
		while (x % i == 0) {

			x /= i;

			--remaining, ++count;

			if (count > 1) return false;

			if (remaining == 0) {
				break;
			}
		}
	}

	if (x > 1) --remaining;

	return remaining == 0;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x;
		std::cin >> x;

		std::cout << is_sphenic(x) << std::endl;
	}

	return 0;
}

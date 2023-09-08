/*
Juggernaut được cô giáo Disruptor dạy toán, cô giáo định nghĩa một hàm f(x) như
sau:

Với  t là số lượng các số tự nhiên k (1 <= k <= x) thỏa mãn nguyên tố cùng nhau
với x, nếu t là nguyên tố thì f(x) = 1, ngược lại f(x) = 0.

Disruptor cho Juggernaut một số nguyên dương x, yêu cầu anh cho biết giá trị của
hàm f(x), nếu trả lời sai thì Jug sẽ bị  cô trả về nhà, Jug không muốn về nhà,
các bạn hãy giúp Jug giải bài toán này.

Input
Dòng đầu tiên chứa số bộ test T (T <= 10).
Mỗi test gồm một dòng chứa số x (1 <= x <= 10^5).

Output
In ra kết quả mỗi test trên một dòng là giá trị của hàm f(x).

Example:
Input:
2
2
3

Output:
0
1
*/

#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool is_prime(unsigned x) {
	for (unsigned i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) return false;
	}
	return x > 1;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x, i, j;
		std::cin >> x;

		std::vector<bool> vec(x, true);
		vec[0] = vec[1] = false;
		for (i = 2; i <= sqrt(x); ++i) {

			unsigned count = 0;
			while (x % i == 0) {
				x /= i;
				++count;
			}

			if (count == 0) continue;
			for (j = i; j < vec.size(); j += i) {
				vec[j] = false;
			}
		}
		if (x > 1) {
			for (j = x; j < vec.size(); j += x) {
				vec[j] = false;
			}
		}

		unsigned count = 1;
		for (i = 1; i < vec.size(); ++i) {
			if (vec[i]) ++count;
		}
		std::cout << is_prime(count) << std::endl;
	}

	return 0;
}

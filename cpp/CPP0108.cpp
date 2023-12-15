/*
Một số được gọi là số tăng giảm nếu số đó có các chữ số thỏa mãn hoặc tăng dần, hoặc giảm dần từ
trái qua phải. Hãy đếm các số nguyên tố là số tăng giảm với số chữ số cho trước.

Dữ liệu vào: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng số chữ số tương ứng cần
kiểm tra (lớn hơn 1 và nhỏ hơn 10)

Kết quả: Ghi ra số lượng các số thỏa mãn điều kiện.

Input
2
2
4

Output
20
50
*/

#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

std::vector<bool> prime(2, false);

void sieve(const u64 &n) {

	const size_t &size = prime.size();

	if (size > n) return;

	prime.resize(n + 1, true);

	u64 i, j;
	for (i = 2; i <= sqrt(n); ++i) {

		if (!prime[i]) continue;

		const u64 start = std::max<u64>(i, size / i) * i;

		for (j = start; j <= n; j += i) {
			prime[j] = false;
		}
	}
}

bool is_decrease(u64 x) {

	unsigned short prev = x % 10;

	while (x > 9) {

		x /= 10;

		unsigned short next = x % 10;
		if (next >= prev) {
			return false;
		}

		prev = next;
	}

	return true;
}

bool is_increase(u64 x) {

	unsigned short prev = x % 10;

	while (x > 9) {

		x /= 10;

		unsigned short next = x % 10;
		if (next <= prev) {
			return false;
		}

		prev = next;
	}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned short digits;
		std::cin >> digits;

		u64 i, count = 0;
		const u64 min = pow(10, digits - 1), max = min * 10 - 1;

		sieve(max);

		for (i = min; i <= max; ++i) {

			if (!prime[i]) continue;

			if (is_increase(i) || is_decrease(i)) {
				++count;
			}
		}

		std::cout << count << std::endl;
	}

	return 0;
}

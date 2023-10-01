/*
Dãy số Fibonacci được định nghĩa theo công thức như sau:
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 với n>2

Viết chương trình tính số Fibonacci thứ n (với n không quá 92)

Dữ liệu vào: Dòng đầu ghi số bộ test. Mỗi bộ test là một số nguyên n.

Kết quả: Với mỗi bộ test, ghi ra số Fibonacci thứ n trên một dòng.

Ví dụ:
Input:
3
2
5
20

Output:
1
5
6765
*/

#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 get_fibonacci(unsigned n) {

	static std::vector<u64> fibs = { 0, 1, 1 };

	if (n >= fibs.size()) {
		fibs.resize(n + 1, 0);
	}

	if (fibs[n] == 0 && n > 0) {
		fibs[n] = get_fibonacci(n - 1) + get_fibonacci(n - 2);
	}

	return fibs[n];
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned n;
		std::cin >> n;

		std::cout << get_fibonacci(n) << std::endl;
	}

	return 0;
}

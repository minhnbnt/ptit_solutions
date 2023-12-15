/*
Cho mảng A[] gồm n số nguyên không âm. Hãy tìm dãy con lớn nhất chỉ toàn các số
Fibonacci. Số 0 được coi là số Fibonacci đầu tiên.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào n là số phần tử của mảng A[]; dòng tiếp theo đưa vào n số các phần tử
của mảng A[]; các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc :1 ≤ T ≤ 100; 1≤n≤100; 1≤A[i]≤1000.

Output:
Đưa ra dãy con lớn nhất bao gồm các số Fibonacci của mỗi test theo từng dòng.

Input:
2
7
1 4 3 9 10 13 7
9
0 2 8 5 2 1 4 13 23

Output:
1 3 13
0 2 8 5 2 1 13
*/

#include <algorithm>
#include <iostream>
#include <vector>

auto in_fibs(unsigned x) -> bool {

	static auto vec = std::vector<unsigned>{ 0, 1 };

	if (x < vec.back()) {
		return std::binary_search(vec.begin(), vec.end(), x);
	}

	while (x > vec.back()) {

		const auto last1 = vec.back();
		const auto last2 = *std::next(vec.rbegin());

		vec.push_back(last1 + last2);

		if (x < vec.back()) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	auto cases = 0u;
	std::cin >> cases;

	while (cases--) {

		auto ele = 0u;
		std::cin >> ele;

		auto vec = std::vector<unsigned>(ele);

		for (auto &x : vec) {
			std::cin >> x;
		}

		for (const auto x : vec) {
			if (!in_fibs(x)) continue;
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

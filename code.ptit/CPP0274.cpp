/*
Cho mảng A[] gồm N phần tử. Hãy đếm số phần tử bị lặp lại ít nhất 1 lần. Ví dụ
với mảng A[] = {5, 6, 1, 2, 1, 4} thì ta có đáp án là 2 vì có 2 phần tử 1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào số phần tử của mảng N; dòng tiếp theo là N số A[i] là các phần tử của
mảng A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^6, 1≤ A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
4 5 1 2 1
6
10 20 30 30 20 5

Output:
2
4
*/

#include <iostream>
#include <unordered_map>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::unordered_map<i64, size_t> map;
		while (ele--) {

			i64 input;
			std::cin >> input;

			if (map.find(input) != map.end()) {
				++map[input];
			} else map.emplace(input, 1);
		}

		size_t result = 0;
		for (auto &pair : map) {
			size_t &count = pair.second;
			if (count > 1) {
				result += count;
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}

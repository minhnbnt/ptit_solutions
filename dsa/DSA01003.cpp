/*
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N.

Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[].

Ví dụ N=5, X[] = {1, 2, 3, 4, 5}
thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

Input:
Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.

T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input
2
5
1 2 3 4 5
5
5 4 3 2 1

Output
1 2 3 5 4
1 2 3 4 5
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		std::cin >> size;

		std::vector<unsigned> vec(size);
		for (auto &x : vec) {
			std::cin >> x;
		}

		std::next_permutation(vec.begin(), vec.end());

		for (unsigned x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

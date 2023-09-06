/*
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra
hoán vị trước đó của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị trước đó
của X[] là {5, 4, 3, 2, 1}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.

T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤10^3.

Input đảm bảo không có trường hợp hoán vị đã cho là đầu tiên (tức là luôn có
hoán vị trước nó)

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
2
5
1 2 3 5 4
5
5 4 3 2 1

Output:
1 2 3 4 5
5 4 3 1 2
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<unsigned> vec(ele);
		for (unsigned &x : vec) {
			std::cin >> x;
		}

		std::prev_permutation(vec.begin(), vec.end());

		for (const unsigned &x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

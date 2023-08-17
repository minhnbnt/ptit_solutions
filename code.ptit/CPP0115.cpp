/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy đưa ra tất cả các ước số nguyên tố
của N cùng lũy thừa của nó. Ví dụ N=100 = 22 × 52. N = 35 =51 × 71.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên N.
T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N≤10000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
100
35

Output:
2 2 5 2
5 1 7 1
*/

#include <complex>
#include <iostream>
#include <map>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::map<int, unsigned> mp;

		unsigned long long n;
		std::cin >> n;

		for (unsigned long i = 2; i <= sqrt(n); ++i) {

			unsigned count = 0;

			while (n % i == 0) {
				n /= i;
				++count;
			}

			if (count > 0) mp.insert({ i, count });
		}

		if (n > 1) mp.insert({ n, 1 });

		for (const std::pair<int, unsigned> &pr : mp)
			std::cout << pr.first << " " << pr.second << " ";

		std::cout << std::endl;
	}

	return 0;
}

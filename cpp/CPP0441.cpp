/*
Cho mảng A[] gồm n phần tử. Hãy tìm vị trí của phần tử đầu tiên có giá trị X
trong mảng A[]. Nếu không tìm thấy X hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào n là số các phần tử của mảng A[] và số X cần tìm; dòng tiếp theo đưa vào
n số A[i] (1≤i≤n) các số được viết cách nhau một vài khoảng trống. T, n, A, X
thỏa mãn ràng buộc: 1≤T≤100; 1≤N, X, A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 16
9 7 2 16 4
7 98
1 22 57 47 34 18 66

Output:
4
-1
*/

#include <iostream>
#include <unordered_map>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i, target;
		std::cin >> ele >> target;

		std::unordered_map<i64, unsigned> map;
		for (i = 1; i <= ele; ++i) {

			i64 x;
			std::cin >> x;

			if (map.find(x) == map.end()) {
				map.emplace(x, i);
			}
		}

		if (map.find(target) != map.end()) {
			std::cout << map[target];
		} else std::cout << -1;
		std::cout << std::endl;
	}

	return 0;
}

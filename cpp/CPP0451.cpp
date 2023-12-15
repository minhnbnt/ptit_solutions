/*
Cho mảng A[] gồm N phần tử đã được sắp xếp. Hãy tìm K phần tử gần nhất của X khác X. Ví dụ với mảng
A[] = {1, 3, 5, 7, 9, 11}, X = 7, K=2 thì ta có 2 phần tử gần nhất của 7 là 5 và 9. K là số chẵn và
cần lấy một nửa lớn, một nửa nhỏ hơn X.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm ba dòng: dòng thứ nhất đưa vào số phần tử
của mảng N; dòng tiếp theo là N số A[i] là các phần tử của mảng A[]; dòng tiếp theo đưa vào hai số K
và X.

T, N, K, X, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, K, X ≤10%6, 1≤ A[i] ≤10^6;

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		/* for some reasons, this only works with int,
		 * but not size_t or unsigned long long (which i loved) */

		int ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		int target, nearest;
		std::cin >> nearest >> target;

		const int index = std::lower_bound(vec.begin(), vec.end(), target) - vec.begin();
		int left = index - nearest / 2, right = index;

		if (vec[index] == target) ++right;

		for (int i = 0; i < nearest / 2; ++i) {
			std::cout << vec[left + i] << ' ';
		}
		for (int i = 0; i < nearest / 2; ++i) {
			std::cout << vec[right + i] << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}

/*
Cho mảng A[] gồm n phần tử và Q câu hỏi. Mỗi câu hỏi Q là bộ đôi hai số L và R.
Nhiệm vụ của bạn là tìm tổng các phần tử của mảng A[] của mỗi câu hỏi Q. Ví dụ
với mảng A[] = {1, 1, 2, 1, 3, 4, 5, 2, 8}, các câu hỏi Q: [1, 5], [2, 4], [3,
5] ta sẽ có các câu trả lời : 8 , 4, 6.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba phần: phần thứ nhất đưa
vào n, Q là số phần tử của mảng A[] và số lượng câu hỏi Q; phần tiếp theo đưa
vào n số A[i] của mảng; phần cuối cùng đưa vào Q câu hỏi, mỗi câu hỏi là một bộ
đôi L, R; các số được viết cách nhau một vài khoảng trống.

T, n, Q, L, R, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ L≤ R ≤n, Q, ≤10^4; 1≤ A[i]
≤10^3;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
9 3
1 1 2 1 3 4 5 2 8
1 5
2 4
3 5

Output:
8
4
6
*/

#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, ques;
		std::cin >> ele >> ques;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		while (ques--) {

			unsigned i, j, k;
			std::cin >> i >> j;

			long long result = 0;
			for (k = i - 1; k < j; ++k) {
				result += vec[k];
			}

			std::cout << result << std::endl;
		}
	}

	return 0;
}

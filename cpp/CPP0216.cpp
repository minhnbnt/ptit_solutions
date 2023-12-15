/*
Cho mảng A[] gồm n phần tử và một câu hỏi Q. Mỗi câu hỏi Q là bộ đôi hai số L và R. Nhiệm vụ của bạn
là xác định xem dãy con của A[] trong khoảng [L, R] có tạo nên một dãy Mountain hay không ? Dãy
Mountain là dãy được chia thành hai phần : phần thứ nhất tăng phần thứ hai giảm. Ví dụ với mảng A[]
= {2, 3, 2, 4, 4, 6, 3, 2}, các câu hỏi Q: [0, 2], [2, 7], [2, 3], [1, 3] ta sẽ có các câu trả lời :
Yes, Yes, Yes, No tương ứng với các dãy Mountain [2, 3, 2], [2, 4, 4, 6, 3, 2], [2, 4], [3, 2, 4].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào n, L, R là số
phần tử của mảng A[] và câu hỏi Q; phần tiếp theo đưa vào n số A[i] của mảng; các số được viết cách
nhau một vài khoảng trống.
T, n, L, R,  A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ L≤ R ≤n, ≤10^4; 1≤ A[i] ≤10^3;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
8
2 3 2 4 4 6 3 2
0 2
8
2 3 2 4 4 6 3 2
1 3

Output:
Yes
No
*/

#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
bool is_mountain(Iter begin, Iter end) {

	const Iter it = std::is_sorted_until(begin, end);

	return std::is_sorted_until(it, end, std::greater<int>()) == end;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		size_t left, right;
		std::cin >> left >> right;

		bool result = is_mountain(vec.begin() + left, vec.begin() + right + 1);

		std::cout << (result ? "Yes" : "No") << std::endl;
	}

	return 0;
}

/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là đưa ra mảng đã được sắp xếp bao
gồm các chữ số của mỗi phần tử trong A[].

Ví dụ A[] = { 110, 111, 112, 113, 114 }ta có kết quả là {0, 1, 2, 3, 4}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A[i] ; các số được
viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^7; 0≤ A[i] ≤10^16.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
3
131 11 48
4
111 222 333 446

Output:
1 3 4 8
1 2 3 4 6
*/

#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<char> se;

		while (ele--) {

			std::string s;
			std::cin >> std::ws >> s;

			for (char c : s) {
				se.insert(c);
			}
		}

		for (char c : se) {
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

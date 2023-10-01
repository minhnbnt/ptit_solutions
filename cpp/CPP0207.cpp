/*
Cho mảng A[] gồm n phần tử. Hãy tìm phần tử lớn nhất của mảng. Ví dụ với mảng
A[] = {7, 10, 4, 3, 20, 15 } ta nhận được kết quả là 20.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^5; 1≤ A[i] ≤10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6
7 10 4 3 20 15
6
9 7 12 8 6 5

Output:
20
12
*/

#include <deque>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, n;
		std::cin >> ele >> n;

		std::deque<int> deck(ele);
		for (int &x : deck) {
			std::cin >> x;
		}

		while (n--) {
			int tmp = deck.front();
			deck.pop_front();
			deck.push_back(tmp);
		}

		for (int x : deck) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

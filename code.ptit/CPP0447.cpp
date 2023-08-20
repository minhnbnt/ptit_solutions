/*
Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng. Các phần tử
được đưa ra theo thứ tự giảm dần.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào N và K; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một
vài khoảng trống. T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤K < N ≤10^3,
1≤A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi bộ test trên một dòng.

Input:
2
5 3
10 7 9 12 6
6 2
9 7 12 8 6 5

Output:
12 10 9
12 9
*/

#include <iostream>
#include <queue>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, n;
		std::cin >> ele >> n;

		std::priority_queue<i64> pq;
		while (ele--) {

			i64 x;
			std::cin >> x;

			pq.push(x);
		}

		while (n--) {
			std::cout << pq.top() << ' ';
			pq.pop();
		}
		std::cout << std::endl;
	}

	return 0;
}

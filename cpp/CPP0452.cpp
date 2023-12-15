/*
Cho mảng A[], B[], C[] gồm N1, N2, N3 phần tử đã được sắp xếp. Hãy đưa ra các phần tử có mặt trong
cả ba mảng theo thứ tự tăng dần. Nếu không có đáp án, in ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm bốn dòng: dòng thứ nhất đưa vào N1, N2, N3
là số phần tử của mảng A[], B[], C[]; các dòng tiếp theo đưa vào N1 số A[i], N2 số B[j], N3 số C[k].
T, N1, N2, N3, A[i], B[j], C[k] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N1, N2, N3 ≤10^6, 0≤ A[i], B[j],
C[k] ≤10^18.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120

Output:
20 80
*/

#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t sizes[3];
		for (size_t &size : sizes) {
			std::cin >> size;
		}

		std::vector<long long> vec[3];
		for (int i = 0; i < 3; ++i) {
			vec[i].resize(sizes[i]);
			for (long long &x : vec[i]) {
				std::cin >> x;
			}
		}

		bool is_empty = true;
		size_t index[3] = { 0 };
		while (index[0] < sizes[0] && index[1] < sizes[1] && index[2] < sizes[2]) {

			if (vec[0][index[0]] == vec[1][index[1]] && vec[1][index[1]] == vec[2][index[2]]) {

				is_empty = false;
				std::cout << vec[0][index[0]] << ' ';
				++index[0], ++index[1], ++index[2];

			} else if (vec[0][index[0]] < vec[1][index[1]]) {

				++index[0];

			} else if (vec[1][index[1]] < vec[2][index[2]]) {

				++index[1];

			} else {

				++index[2];
			}
		}

		std::cout << (is_empty ? "-1" : "") << std::endl;
	}

	return 0;
}

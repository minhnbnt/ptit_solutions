/*
Cho số tự nhiên N. Hãy đưa ta các xâu nhị phân có độ dài N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc :1 ≤ T, N ≤ 20.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input
2
2
3

Output
00  01  10 11
000 001 010 011 100 101 110 111
*/

#include <iostream>
#include <string>

void print_all_bits(size_t len) {

	static std::string bits;

	if (bits.length() == len) {
		std::cout << bits << ' ';
		return;
	}

	for (char c : { '0', '1' }) {

		bits.push_back(c);

		print_all_bits(len);

		bits.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t length;
		std::cin >> length;

		print_all_bits(length);
		std::cout << std::endl;
	}

	return 0;
}

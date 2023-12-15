/*
Cho xâu ký tự S bao gồm các ký tự ‘A’,..,’Z’ và các chữ số ‘0’,...,’9’. Nhiệm vụ của bạn in các ký
tự từ ’A’,.., ‘Z’ trong S theo thứ tự anphabet và nối với tổng các chữ số trong S ở cuối cùng. Ví dụ
S =”ACCBA10D2EW30” ta nhận được kết quả: “AABCCDEW6”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
AC2BEW3
ACCBA10D2EW30

Output:
ABCEW5
AABCCDEW6
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using u64 = unsigned long long;

bool gen_res(const std::vector<u64> &vec) {

	size_t odd = 0, even = 0;

	for (const u64 &x : vec) {
		if (x % 2 == 1) {
			++odd;
		} else ++even;
	}

	if (vec.size() % 2 == 1) {
		return odd > even;
	}

	return odd < even;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		std::vector<u64> vec;

		while (!iss.eof()) {

			u64 x;
			iss >> x;

			vec.push_back(x);
		}

		std::cout << (gen_res(vec) ? "YES" : "NO") << std::endl;
	}

	return 0;
}

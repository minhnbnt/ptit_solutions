/*
Cho xâu ký tự S chỉ bao gồm các ký tự số. Nhiệm vụ của bạn là đếm các xâu con của S chia hết cho N.
Ví dụ S =”1234”, N = 4 ta nhận được kết quả là 4 tương ứng với 4 xâu con chia hết cho 4: 4, 12, 24,
124. Xâu con có thể chứa các kí tự không liên tiếp nhau.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N, trong
đó M là độ dài xâu S; phần tiếp theo là xâu S gồm M số.
T, M, N, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N <= 100.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4 4
1234
3 6
676

Output:
4
3
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;

u64 gen_result(const std::vector<short> &vec, unsigned mod) {

	std::unordered_map<unsigned, u64> map;

	for (const short &num : vec) {

		const std::unordered_map<unsigned, u64> prev_map(map);

		for (const auto &[x, count] : prev_map) {
			unsigned target = x * 10 + num;
			map[target % mod] += count;
		}

		++map[num % mod];
	}

	return map.at(0);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t len;
		unsigned mod;
		std::cin >> len >> mod >> std::ws;

		std::vector<short> vec(len);
		for (short &x : vec) {
			x = std::cin.get() - '0';
		}

		std::cout << gen_result(vec, mod) << std::endl;
	}

	return 0;
}

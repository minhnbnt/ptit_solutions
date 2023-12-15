/*
Cho số tự nhiên N. Bạn chỉ được phép sử dụng nhiều nhất một phép đổi chỗ giữa 2 chữ số để nhận được
số lớn nhất nhỏ hơn N. Ví dụ với số N=12435, sử dụng một phép đổi chỗ ta nhận được số lớn nhất nhỏ
hơn N là 12345. Mặc dù 12354 > 12345 nhưng ta không thể tạo ra số 12345 với chỉ một phép hoán vị.
Với số N=12345 ta không có phép đổi chỗ.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp đưa các bộ test. Mỗi bộ test được viết trên một dòng là một xâu ký tự số không có ký tự
‘0’ đầu tiên.

Các số T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤length(N) ≤10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng, trong đó -1 được xem là test không có phép đổi chỗ.

Input:
2
12435
12345
12345

Output:
-1
*/

#include <algorithm>
#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		auto it1 = std::is_sorted_until(input.rbegin(), input.rend(), std::greater<char>());

		if (it1 == input.rend()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::string::reverse_iterator it2 = input.rbegin();

		while (*it2 >= *it1 || *it2 == *std::next(it2)) {
			++it2;
		}

		std::swap(*it1, *it2);

		std::cout << input << std::endl;
	}

	return 0;
}

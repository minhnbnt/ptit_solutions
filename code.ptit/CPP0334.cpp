/*
Cho xâu ký tự S bao gồm các ký tự ‘a’,..,’z’ và các chữ số. Nhiệm vụ của bạn là
hãy tính tổng các số có mặt trong xâu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ Length(S) ≤10^5.
Input đảm bảo đáp asn không vượt quá 10^9.

Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123
*/

#include <cctype>
#include <iostream>
#include <string>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf, num;
		std::getline(std::cin >> std::ws, buf);

		u64 result = 0;

		for (size_t i = 0; i < buf.length(); ++i) {

			if (isdigit(buf[i])) {
				num += buf[i];
			}

			else if (num.length() > 0) {
				result += std::stoll(num);
				num.clear();
			}
		}

		if (num.length() > 0) {
			result += std::stoll(num);
		}

		std::cout << result << std::endl;
	}

	return 0;
}

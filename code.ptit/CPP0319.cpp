/*
Cho số tự nhiên m và số nguyên s không âm. Nhiệm vụ của bạn là tìm số bé nhất và
lớn nhất có m chữ số và tổng chữ số bằng s.

Input:
Dòng đầu gồm 2 số m và s (1 ≤ m ≤ 100, 0 ≤ s ≤ 900).

Output:
In ra kết quả của bài toán.
Số đầu tiên là số bé nhất, số thứ hai là số lớn nhất. Nếu không có đáp án in ra
“-1 -1”.

Example
Input:
2 15

Output:
69 96
*/

#include <iostream>
#include <string>

const std::string gen_max(unsigned digits, unsigned sum) {

	if (sum == 0 && digits > 1) {
		return "-1";
	}

	std::string result;

	while (sum > 9 && digits > 1) {
		result.push_back('9');
		sum -= 9, --digits;
	}

	if (sum > 9) return "-1";

	result.push_back(sum + '0');
	result += std::string(digits - 1, '0');

	return result;
}

const std::string gen_min(const std::string &max) {

	if (max == "0") return "0";
	if (max == "-1") return "-1";

	std::string min(max.rbegin(), max.rend());

	if (min[0] == '0') {

		for (size_t i = 1; i < min.length(); ++i)
			if (min[i] != '0') {
				--min[i];
				break;
			}

		min[0] = '1';
	}

	return min;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned digits, sum;
	std::cin >> digits >> sum;

	const std::string max = gen_max(digits, sum);

	std::cout << gen_min(max) << ' ' << max << std::endl;

	return 0;
}

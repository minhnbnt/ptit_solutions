/*
Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn
hơn số n cho trước.
Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử
bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?

Các tập hợp là hoán vị của nhau chỉ được tính là một.
Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

Input:
Gồm nhiều bộ test (không quá 100 test).
Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155.
Input kết thúc bởi 3 số 0.

Output:
Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

Ví dụ:
Input
9 3 23
9 3 22
10 3 28
16 10 107
20 8 102
20 10 105
20 10 155
3 4 3
4 2 11
0 0 0

Output:
1
2
0
20
1542
5448
1
0
0
*/

#include <iostream>
#include <vector>

template <typename Iter>
unsigned generate_and_count(Iter begin, Iter end, size_t size, int target_sum) {

	if (size == 0) {
		return target_sum == 0 ? 1 : 0;
	}

	unsigned result = 0;
	for (Iter it = begin; it != end; it++) {
		result += generate_and_count(it + 1, end, size - 1, target_sum - *it);
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::vector<unsigned> numbers;

	while (true) {

		unsigned vec_size, result_size, target_sum;
		std::cin >> vec_size >> result_size >> target_sum;

		numbers.resize(vec_size);

		if (numbers.empty()) {
			break;
		}

		for (unsigned i = 0; i < vec_size; i++) {
			numbers[i] = i + 1;
		}

		unsigned result = generate_and_count(numbers.begin(), numbers.end(),
		                                     result_size, target_sum);

		std::cout << result << std::endl;
	}

	return 0;
}

/*
Cho một dãy các xâu ký tự chỉ bao gồm các chữ cái in hoa từ A đến Z,
trong đó các ký tự trong mỗi xâu đều đã được sắp xếp theo thứ tự từ điển và mỗi
chữ cái chỉ xuất hiện nhiều nhất một lần (tức là độ dài xâu tối đa là 26).

Nếu một ký tự xuất hiện trong hai xâu liên tiếp thì được coi là một lần lặp.
Hãy tìm cách sắp xếp lại thứ tự các xâu sao cho số lần lặp là nhỏ nhất có thể.

Ví dụ dưới đây là cùng một dãy xâu nhưng với cách sắp xếp lại thì số lần lặp chỉ
còn 2.

ABC
ABEF
DEF
ABCDE
FGH
=> Số lần lặp là 6

ABEF
DEF
ABC
FGH
ABCDE
=> Số lần lặp là 2.

Input
Dòng đầu tiên ghi số N (2 ≤ N ≤ 10) là số xâu ký tự. N dòng tiếp theo, mỗi dòng
ghi một xâu.

Output
In ra trên một dòng số lần lặp nhỏ nhất có thể.

Ví dụ

Input
5
ABC
ABEF
DEF
ABCDE
FGH

Output
2

-----
Input
6
BDE
FGH
DEF
ABC
BDE
ABEF

Output
3

-----
Input
4
XYZ
XYZ
ABYZ
Z

Output
4
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

size_t count_duplicates(const std::string &s1, const std::string &s2) {

	size_t counter = 0;

	for (char c1 : s1) {
		for (char c2 : s2) {
			if (c1 == c2) {
				counter++;
			}
		}
	}

	return counter;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int size, i, j;
	std::cin >> size;

	std::vector<std::string> vec(size);
	for (std::string &s : vec) {
		std::cin >> s;
	}

	std::vector<std::vector<size_t>> dups(size);
	for (i = 0; i < size; i++) {

		dups[i].resize(size);

		for (j = 0; j < size; j++) {
			dups[i][j] = count_duplicates(vec[i], vec[j]);
		}
	}

	std::vector<int> indexes(size);
	for (int i = 0; i < size; i++) {
		indexes[i] = i;
	}

	int result = std::numeric_limits<int>::max();

	do {

		int total_dups = 0;

		for (i = 1; i < size; i++) {

			int s1_index = indexes[i];
			int s2_index = indexes[i - 1];

			total_dups += dups[s1_index][s2_index];
		}

		result = std::min(result, total_dups);

	} while (std::next_permutation(indexes.begin(), indexes.end()));

	std::cout << result << std::endl;

	return 0;
}

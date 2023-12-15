/*
Cho mảng A[] gồm n số nguyên không âm. Hãy sắp đặt lại các phần tử trong mảng sao cho khi nối các số
lại với nhau ta được một số lớn nhất. Ví dụ với mảng A[] = {54, 546, 548, 60 } thực hiện theo nguyên
tắc trên ta được số lớn nhất là  6054854654.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤105;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4
54 546 548 60
8
1 34 3 98 9 76 45 4

Output:
6054854654
998764543431
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int comparator(const std::string &s1, const std::string &s2) {
	return s1 + s2 > s2 + s1;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<std::string> vec(ele);
		for (std::string &s : vec) {
			std::cin >> std::ws >> s;
		}

		std::sort(vec.begin(), vec.end(), comparator);

		for (const std::string &s : vec) {
			std::cout << s;
		}
		std::cout << std::endl;
	}

	return 0;
}

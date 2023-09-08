/*
Cho dãy số A[] chỉ bao gồm các số nguyên dương không quá 1000. Hãy liệt kê các
số khác nhau trong dãy theo thứ tự tăng dần.

Input
Dòng đầu ghi số n là số phần từ của dãy (không quá 100).
Dòng thứ 2 ghi n số của mảng.

Output
Ghi ra các số khác nhau trong dãy A[] theo thứ tự tăng dần, mỗi số cách nhau một
khoảng trống.

Ví dụ
Input:
10

Output:
3 7 9 3 6 13 7 7 9 3
3 6 7 9 13
*/

#include <iostream>
#include <set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::set<int> set;

	unsigned ele;
	std::cin >> ele;

	while (ele--) {
		int x;
		std::cin >> x;
		set.insert(x);
	}

	for (const int &x : set) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}

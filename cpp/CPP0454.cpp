/*
Theo định lý Pytago, ta đã biết một bộ 3 số (a, b, c) thỏa mãn  a2 + b2 = c2 thì đó là ba cạnh của
một tam giác vuông.

Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là kiểm tra xem có tồn tại bộ ba số thỏa mãn là ba
cạnh của tam giác vuông hay không.

Dữ liệu vào:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N (1≤ N ≤5000).
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10^9).

Kết quả:
Với mỗi test, in ra trên một dòng “YES” nếu tìm được, và “NO” trong trường hợp ngược lại.

Ví dụ:
Input
2
5
3 1 4 6 5
3
1 1 1

Output
YES
NO
*/

#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool has_righttriangle(std::vector<u64> vec) {

	for (u64 &x : vec) x *= x;
	std::sort(vec.begin(), vec.end());

	for (int i = vec.size(); i > 0; --i) {

		u64 &hypo = vec[i - 1];
		int left = 0, right = i - 2;

		while (left != right) {
			if (vec[left] + vec[right] > hypo) --right;
			else if (vec[left] + vec[right] < hypo) ++left;
			else return true;
		}
	}

	return false;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<u64> vec(ele);
		for (u64 &item : vec) {
			std::cin >> item;
		}

		std::cout << (has_righttriangle(vec) ? "YES" : "NO") << std::endl;
	}

	return 0;
}

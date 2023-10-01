/*
Cho mảng A[] gồm n số nguyên dương. Nhiệm vụ của bạn là hãy sắp đặt lại các phần
tử của mảng sao theo nguyên tắc số lớn nhất ở đầu, số nhỏ nhất thứ 2, số lớn thứ
nhì ở vị trí tiếp theo, số nhỏ thứ nhì ở vị trí kế tiếp …. Ví dụ với mảng A[] =
{1, 7, 3, 5, 9} ta được mảng được sắp A[] = {9, 1, 7, 3, 5}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 1≤ A[i] ≤10^3;

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
4
1 5 2 7
6
1 3 2 7 9 8

Output:
7 1 5 2
9 1 8 2 7 3
*/

#include <iostream>
#include <list>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, pos = 0;
		std::cin >> ele;

		std::list<int> llist(ele);
		for (int &x : llist) {
			std::cin >> x;
		}
		llist.sort();

		while (!llist.empty()) {

			if (pos % 2 == 0) {
				std::cout << llist.back() << ' ';
				llist.pop_back();
			} else {
				std::cout << llist.front() << ' ';
				llist.pop_front();
			}
			++pos;
		}

		std::cout << std::endl;
	}

	return 0;
}

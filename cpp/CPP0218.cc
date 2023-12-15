/*
Cho mảng các số nguyên dương A[] gồm n số. Hãy tìm tất cả các số nguyên dương K sao cho tất cả các
phần tử của mảng A[] lấy phần dư với K đều bằng nhau. Ví dụ với mảng A[] = {6, 38, 34} ta tìm được
các số K = {1, 2, 4} vì:

6%1 = 38%1 = 34%1 =0; 6%2 = 38%2 = 34%2 =0; 6%4 = 38%4 = 34%4 =2;

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa vào số n; dòng tiếp
theo đưa vào n số của mảng A[]. Các số được viết cách nhau một vài khoảng trống.
T, A[i], n thỏa mãn ràng buộc : 1≤T≤100; 0≤n ≤10^5; 1≤ A[i] ≤10^5.

Output:
Đưa ra số các số Kkết quả mỗi test theo từng dòng.

Input:
2
3
6 38 34
2
3 2

Output:
3
1
*/

#include <algorithm>
#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t ele;
		std::cin >> ele;

		std::unordered_set<i64> set;
		while (ele-- > 0) {

			i64 x;
			std::cin >> x;

			set.insert(x);
		}

		if (set.size() == 1) {
			// should be inf :0
			std::cout << 0 << std::endl;
			continue;
		}

		unsigned long long count = 0;
		const i64 max = *std::max_element(set.cbegin(), set.cend());
		for (i64 i = 1; i < max; ++i) {

			const i64 mod = max % i;

			auto it = std::find_if(set.cbegin(), set.cend(),
			                       [&mod, &i](const i64 &x) { return x % i != mod; });

			if (it == set.cend()) ++count;
		}

		std::cout << count << std::endl;
	}

	return 0;
}

/*
Cho mảng A1[] và A2[] gồm n, m phần tử theo thứ tự. Hãy sắp xếp lại các phần tử
trong A1[] theo quan hệ thứ tự trong A[2]. Phần tử xuất hiện trước trong A2[] và
có mặt trước trong A1[] đứng trước; các phần tử xuất hiện trong A1[] nhưng không
xuất hiện trong A2[] đứng sau theo thứ tự tăng dần. Ví dụ với mảng A1[] = {2, 1,
2, 5, 7, 1, 9, 3, 6, 8, 8 }, A2[] = {2, 1, 8, 3} sau khi sắp xếp ta được A1[] =
{2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng thứ nhất đưa
là hai số n, m; dòng  thứ hai đưa vào n số của mảng A1[i]; dòng  thứ ba đưa vào
m số của mảng A2[i];các số được viết cách nhau một vài khoảng trống.

T, n, m, A1[i], A2[j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤10^6;
1≤ A1[i], A2[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9
*/

#include <iostream>
#include <map>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele1, ele2, i;
		std::cin >> ele1 >> ele2;

		std::map<i64, size_t> mp;
		for (i = 0; i < ele1; ++i) {

			i64 x;
			std::cin >> x;

			++mp[x];
		}

		std::vector<i64> vec(ele2);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		for (const i64 &x : vec) {

			std::map<i64, size_t>::iterator it = mp.find(x);

			if (it == mp.end()) {
				continue;
			}

			size_t second = it->second;
			while (second--) {
				std::cout << it->first << ' ';
			}

			mp.erase(it);
		}

		for (const std::pair<i64, size_t> &pr : mp) {

			size_t second = pr.second;
			while (second--) {
				std::cout << pr.first << ' ';
			}
		}

		std::cout << std::endl;
	}

	return 0;
}

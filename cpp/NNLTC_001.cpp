/*
Cho 1 danh sách tuyến tính ds theo khai báo sau chứa n số nguyên:

const int MAXLIST = 10000;

typedef struct {
    int n;
    int nodes[MAXLIST];
} list;

list ds;

Viết chương trình con Thống kê số lần xuất hiện của từng số trong danh sách ds,
và in ra màn hình mỗi số trên 1 dòng  theo ví dụ sau:

Dãy số ds: 5 5 3 4 3 2 5

Kết quả in trên màn hình:
5 3
3 2
4 1
2 1
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main(void) {

	int x;
	std::vector<int> vec;
	std::unordered_map<int, unsigned> mp;

	while (std::cin >> x)

		if (mp.find(x) == mp.end()) {
			vec.push_back(x);
			mp.emplace(x, 1);

		} else ++mp[x];

	for (const int &x : vec) {
		std::cout << x << ' ' << mp[x] << '\n';
	}
	std::cout << std::flush;

	return 0;
}

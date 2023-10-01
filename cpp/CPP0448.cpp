/*
Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy tìm số lần xuất hiện số X trong
mảng. Nếu số lần xuất hiện số x trong mảng là 0 hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào N và X; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một
vài khoảng trống.
T, N, X, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^3, 1≤A[i], X ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3

Output:
4
-1
*/

#include <iostream>
#include <unordered_map>

int main(void) {

	using namespace std;
	using i64 = long long;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unsigned cases;
	cin >> cases;

	while (cases--) {

		size_t ele;
		i64 target;
		cin >> ele >> target;

		unordered_map<i64, size_t> map;
		while (ele--) {

			i64 x;
			cin >> x;

			if (map.find(x) != map.end()) {
				++map[x];
			} else map.emplace(x, 1);
		}

		if (map.find(target) != map.end()) {
			cout << map[target] << endl;
		} else cout << -1 << endl;
	}

	return 0;
}

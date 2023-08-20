/*
Cho mảng A[]gồm N phần tử. Hãy đưa ra các phần tử nhỏ nhất thứ k của mảng.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào N,k là số phần tử của mảng A[] và số k; các dòng tiếp theo đưa vào N số
A[i].
T, N, A[i], k thỏa mãn ràng buộc: 1≤T≤100; 1≤ k< N ≤10^6, 0≤ A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
6 3
10 5 15 50 40 80

Output:
15
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using namespace std;
	using i64 = long long;

	unsigned cases;
	cin >> cases;

	while (cases--) {

		size_t ele, target;
		cin >> ele >> target;

		vector<i64> vec(ele);
		for (i64 &x : vec) {
			cin >> x;
		}

		sort(vec.begin(), vec.end());

		cout << vec[target - 1] << endl;
	}

	return 0;
}

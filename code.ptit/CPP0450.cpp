/*
Cho mảng A[] gồm N phần tử. Hãy tìm phần tử lặp lại đầu tiên của mảng. Ví dụ với
mảng A[] = {5, 6, 1, 2, 1, 4} thì ta có 1 là phần tử đầu tiên lặp lại trong
mảng. Nếu không tồn tại đáp án, in ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào số phần tử của mảng N; dòng tiếp theo là N số A[i] là các phần tử của
mảng A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^6, 1≤ A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
4 5 1 2 1
6
10 20 30 30 20 5 7

Output:
1
30
*/

#include <iostream>
#include <unordered_set>
#include <vector>

int main(void) {

	using namespace std;
	using i64 = long long;

	unsigned cases;
	cin >> cases;

	while (cases--) {

		size_t ele;
		cin >> ele;

		vector<i64> nums(ele);
		for (i64 &x : nums) {
			cin >> x;
		}

		i64 result = -1;
		unordered_set<i64> set;

		for (const i64 &x : nums) {
			if (set.find(x) != set.end()) {
				result = x;
				break;
			}
			set.insert(x);
		}

		cout << result << endl;
	}

	return 0;
}

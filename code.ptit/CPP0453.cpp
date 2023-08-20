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

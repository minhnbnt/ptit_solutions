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

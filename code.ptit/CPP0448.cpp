#include <iostream>
#include <unordered_map>

int main(void) {

	using namespace std;
	using i64 = long long;

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

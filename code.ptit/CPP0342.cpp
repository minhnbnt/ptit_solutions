#include <cctype>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	using namespace std;

	unsigned cases;
	cin >> cases;

	while (cases--) {

		string str;
		cin >> str;

		unsigned long long sum = 0;

		multiset<char> mset;
		for (const char &c : str) {
			if (isalpha(c)) {
				mset.insert(c);
				continue;
			}
			if (isdigit(c)) {
				sum += c - '0';
			}
		}

		for (const char &c : mset) cout.put(c);
		cout << sum << endl;
	}

	return 0;
}

#include <iostream>
#include <sstream>
#include <string>

auto main(void) -> int {

	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unsigned cases;
	cin >> cases;

	while (cases--) {

		string buf, word;
		getline(cin >> ws, buf);

		istringstream iss(buf);
		unsigned word_count = 0;

		while (iss >> word) {
			++word_count;
		}

		cout << word_count << endl;
	}

	return 0;
}

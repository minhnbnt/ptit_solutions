#include <deque>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, n;
		std::cin >> ele >> n;

		std::deque<int> deck(ele);
		for (int &x : deck) {
			std::cin >> x;
		}

		while (n--) {
			int tmp = deck.front();
			deck.pop_front();
			deck.push_back(tmp);
		}

		for (int x : deck) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}

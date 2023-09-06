#include <algorithm>
#include <iostream>
#include <vector>

class Item {

	size_t id;
	std::string name, category;
	long double buy, sell;
public:
	void input(void) {

		static size_t id = 0;
		this->id = ++id;

		std::getline(std::cin >> std::ws, name);
		std::getline(std::cin >> std::ws, category);

		std::cin >> buy >> sell;
	}

	void print(void) const {

		std::cout << id << ' ' << name << ' ' << category;
		std::cout << ' ' << std::fixed << profit() << '\n';
	}

	long double profit(void) const {
		return sell - buy;
	}
};

int main(void) {

	std::cout.precision(2);

	auto compatator = [](const Item &a, const Item &b) {
		return a.profit() > b.profit();
	};

	size_t ele;
	std::cin >> ele;

	std::vector<Item> vec(ele);
	for (Item &i : vec) {
		i.input();
	}

	std::sort(vec.begin(), vec.end(), compatator);

	for (const Item &i : vec) {
		i.print();
	}
}

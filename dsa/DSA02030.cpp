#include <iostream>

void gen_string(char begin, char end, size_t size) {

	static std::string current;

	if (current.length() == size) {
		std::cout << current << '\n';
		return;
	}

	for (char c = begin; c <= end; c++) {

		current.push_back(c);

		gen_string(c, end, size);

		current.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	char end;
	size_t size;
	std::cin >> end >> size;

	gen_string('A', end, size);
	std::cout.flush();

	return 0;
}

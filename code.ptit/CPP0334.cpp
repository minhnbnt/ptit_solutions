#include <cctype>
#include <iostream>
#include <string>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf, num;
		std::getline(std::cin >> std::ws, buf);

		u64 result = 0;

		for (size_t i = 0; i < buf.length(); ++i) {
			if (isdigit(buf[i])) {
				num += buf[i];
			}

			else if (num.length() > 0) {
				result += std::stoll(num);
				num.clear();
			}
		}

		if (num.length() > 0) {
			result += std::stoll(num);
		}

		std::cout << result << std::endl;
	}

	return 0;
}

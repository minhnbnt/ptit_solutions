#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	const char end_chars[] = { '.', '!', '?' };

	std::string buf;
	bool need_proper = true;

	while (std::cin >> buf) {

		for (char &c : buf) {
			c = tolower(c);
		}

		if (need_proper) {
			buf[0] = toupper(buf[0]);
			need_proper = false;
		}

		for (char c : end_chars) {
			size_t pos = buf.find(c);

			if (pos != std::string::npos) {
				buf.erase(pos);

				need_proper = true;
				break;
			}
		}

		std::cout << buf << (need_proper ? '\n' : ' ');
	}

	return 0;
}

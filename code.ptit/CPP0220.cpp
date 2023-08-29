#include <iostream>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, i, j;
		std::cin >> rank;

		int arr[rank][rank];
		for (i = 0; i < rank; ++i)
			for (int &x : arr[i]) {
				std::cin >> x;
			}

		for (i = 0; i < rank; ++i) {
			for (j = 0; j < rank; ++j) {
				if (i != 0 && j != 0 && i != rank - 1 && j != rank - 1) {
					std::cout << "  ";
					continue;
				}
				std::cout << arr[i][j] << ' ';
			}
			std::cout.put(0xa);
		}
		std::cout.flush();
	}

	return 0;
}

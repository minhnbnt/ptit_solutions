#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using std::vector;

bool is_prime(size_t n) {

	static vector<bool> vec{ false, false };
	const size_t prev_size = vec.size();

	if (n >= prev_size) {

		const size_t new_size = n + 1;
		vec.resize(new_size, true);

		for (size_t i = 2; i <= sqrt(n); i++) {

			if (!vec[i]) continue;

			const size_t start = std::max(i, prev_size / i) * i;

			for (size_t j = start; j <= n; j += i) {
				vec[j] = false;
			}
		}
	}

	return vec[n];
}

template <typename Iter>
void generate(Iter begin, Iter end, vector<vector<int>> &output) {

	static vector<int> current;
	static long long sum = 0;

	if (is_prime(sum)) {
		output.push_back(current);
	}

	while (begin != end) {

		const int current_element = *begin;

		current.push_back(current_element);
		sum += current_element, begin++;

		generate(begin, end, output);

		current.pop_back();
		sum -= current_element;
	}
}

bool comparator(const vector<int> &a, const vector<int> &b) {

	const size_t size_a = a.size(), size_b = b.size();
	const size_t min_size = std::min(size_a, size_b);

	for (size_t i = 0; i < min_size; i++) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}

	return size_a < size_b;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		vector<vector<int>> results;
		generate(vec.begin(), vec.end(), results);

		for (vector<int> &res : results) {
			std::sort(std::begin(res), std::end(res), std::greater<int>());
		}

		std::sort(std::begin(results), std::end(results), comparator);

		for (const vector<int> &res : results) {
			for (int element : res) {
				std::cout << element << ' ';
			}
			std::cout.put('\n');
		}

		std::cout.flush();
	}

	return 0;
}

#include <iomanip>
#include <iostream>
#include <unordered_map>

static std::unordered_map<int, const char *> rignt_ans = { //
	{ 101, "ABBADCCABDCCABD" },
	{ 102, "ACCABCDDBBCDDBB" }
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int id, pos;
		std::cin >> id;

		float score = 10;
		static const float score_per_ques = score / 15;

		for (int i = 0; i < 15; i++) {

			char ans;
			std::cin >> std::ws >> ans;

			if (ans != rignt_ans[id][i]) {
				score -= score_per_ques;
			}
		}

		std::cout << std::fixed << std::setprecision(2) << score << std::endl;
	}

	return 0;
}

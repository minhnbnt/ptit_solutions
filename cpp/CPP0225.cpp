#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

    unsigned cases;
    std::cin >> cases;

    while (cases--) {

        size_t rank, i, j;
        std::cin >> rank;

        int sum = 0;
        std::vector<int> row(rank, 0), col(rank, 0);
        for (i = 0; i < rank; ++i) {
            for (j = 0; j < rank; ++j) {

                int x;
                std::cin >> x;

                sum += x;
                row[i] += x;
                col[j] += x;
            }
        }

        const int max_row = *std::max_element(row.cbegin(), row.cend());
        const int max_col = *std::max_element(col.cbegin(), col.cend());

        std::cout << std::max(max_row, max_col) * rank - sum << std::endl;
    }

    return 0;
}

from typing import List


def compute_original_array(matrix: List[List[int]]) -> List[int]:
    rank = len(matrix)

    array_sum = (
        sum(element for row in matrix for element in row)  #
        // ((rank - 1) * 2)
    )

    if rank == 2:
        element = array_sum // 2
        return [element, element]

    element_diff = [0] * rank

    for i in range(1, rank):
        if i == 1:
            element_diff[i] = matrix[2][1] - matrix[2][0]
        else:
            element_diff[i] = matrix[1][i] - matrix[1][0]

    first_element = (array_sum - sum(element_diff)) // rank

    return [first_element + diff for diff in element_diff]


rank = int(input())

matrix = [[int(token) for token in input().split()] for _ in range(rank)]

for element in compute_original_array(matrix):
    print(element, end=" ")

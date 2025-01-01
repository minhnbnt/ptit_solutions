from typing import List


def input_matrix(height: int) -> List[List[int]]:
    return [
        [int(token) for token in input().split()]  #
        for _ in range(height)
    ]


def convolution(a: List[List[int]], b: [List[List[int]]]) -> List[List[int]]:
    a_width, a_height = len(a[0]), len(a)
    b_width, b_height = len(b[0]), len(b)

    result_width = a_width - b_width + 1
    result_height = a_height - b_height + 1

    result = [[0] * result_width for _ in range(result_height)]

    for i in range(result_height):
        for j in range(result_width):
            result[i][j] = sum(
                a[i + k][j + l] * b[k][l]
                for k in range(b_height)
                for l in range(b_width)
            )

    return result


cases = int(input())

for _ in range(cases):
    height, _ = (int(token) for token in input().split())
    a, b = input_matrix(height), input_matrix(3)

    result = sum(element for row in convolution(a, b) for element in row)

    print(result)

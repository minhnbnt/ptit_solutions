#!/usr/bin/env python3

"""
Cho số nguyên dương N.
Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự
ngược.

Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được
viết trên một dòng.

T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2
3

Output:
21 12
321 312 231 213 132 123
"""

from itertools import permutations

cases = int(input())
for _ in range(cases):
    length = int(input())

    array = range(length, 0, -1)

    for result in permutations(array):
        print(*result, sep="", end=" ")

    print()

#!/usr/bin/python3

"""
Cho hai số nguyên dương N và K.
Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của 1, 2, .., N.

Ví dụ với N=5, K=3 ta có 10 tập con của 1, 2, 3, 4, 5 như sau:
{1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 3, 4}, {1, 3, 5},
{1, 4, 5}, {2, 3, 4}, {2, 3, 5}, {2, 4, 5}, {3, 4, 5}.

Input:
Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số tự nhiên N, K
được viết trên một dòng.

T, n thỏa mãn ràng buộc: 1≤T≤100; 1≤ k ≤ n ≤15.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input
2
4 3
5 3

Output
123 124 134 234
123 124 125 134 135 145 234 235 245 345
"""

from itertools import combinations

cases = int(input())
for _ in range(cases):
    n, k = map(int, input().split())

    for combination in combinations(range(1, n + 1), k):
        print(*combination, sep="", end=" ")

    print()

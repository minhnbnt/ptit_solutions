#!/usr/bin/env python3

"""
Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).
Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ hợp theo
thứ tự tăng dần (tính từ 1).

Input
Dòng đầu ghi số T là số bộ test (T < 10)
Mỗi bộ test gồm 2 dòng

Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.

Output
Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1, theo thứ
tự liệt kê tăng dần).

Ví dụ
Input
2
6 4
1 3 5 6
6 4
2 3 4 6


Output
9
12
"""

from itertools import combinations

cases = int(input())

for _ in range(cases):
    n, k = map(int, input().split())
    array = [x + 1 for x in range(n)]

    target = tuple(map(int, input().split()))

    for i, permutation in enumerate(combinations(array, k)):
        if permutation == target:
            print(i + 1)
            break

#!/usr/bin/env python3

"""
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một
số K < N.

Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được
sắp xếp theo thứ tự tăng dần.
Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

Input
Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi hai số N và K (2 < K < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác
nhau từng đôi một.

Output
Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng.

Ví dụ

Input
1
4 3
3 2 5 4

Output
2 3 4
2 3 5
2 4 5
3 4 5
"""

from itertools import combinations

cases = int(input())

for _ in range(cases):
    size, subArraySize = map(int, input().split())
    array = sorted(int(token) for token in input().split())

    for combination in combinations(array, subArraySize):
        print(*combination)

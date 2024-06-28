#!/usr/bin/env python3

"""
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.

Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán
vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ
trái qua phải.

Input:

Dòng đầu ghi số N (1 < N < 9)
Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

Output:
Ghi mỗi hoán vị của dãy số trên một dòng

Ví dụ
Input
3
88 77 99

Output
77 88 99
77 99 88
88 77 99
88 99 77
99 77 88
99 88 77
"""

from itertools import permutations

size__ = int(input())
array = sorted(int(token) for token in input().split())

for permutation in permutations(array):
    print(*permutation)

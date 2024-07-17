#!/usr/bin/env python3

"""
Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử.
Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất.
Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test.
Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N;
dòng tiếp theo đưa vào N số của mảng A[];
dòng tiếp theo đưa vào N-1 số của mảng B[];
các số được viết cách nhau một vài khoảng trống.

T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤10^18.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input:
2
7
2 4 6 8 9 10 12
2 4 6 8 10 12
6
3 5 7 9 11 13
3 5 7 11 13

Output:
5
4
"""

from typing import List


def findDiff(a1: List[int], a2: List[int]) -> int:
    for i, (x1, x2) in enumerate(zip(a1, a2)):
        if x1 != x2:
            return i + 1

    return max(len(a1), len(a2))


cases = int(input())

for _ in range(cases):
    size = int(input())

    array1 = list(map(int, input().split()))
    array2 = list(map(int, input().split()))

    print(findDiff(array1, array2))

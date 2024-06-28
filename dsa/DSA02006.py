#!/usr/bin/env python3

"""
Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K.
Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy
con đó đúng bằng K.
Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần
tử giống nhau.
Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50
ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm hai phần:
phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[] và số K;
dòng tiếp theo đưa vào N phần tử của dãy số A[].

T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.

Output:
Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự
từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ].

Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.

Input
2
5 50
5 10 15 20 25
8 53
15 22 14 26 32 9 16 8

Output
[5 10 15 20] [5 20 25] [10 15 25]
[8 9 14 22] [8 14 15 16] [15 16 22]
"""

from typing import Iterator, List


def allSubArray(array: List[int]) -> Iterator[List[int]]:
    current = []

    def helper(index=0) -> Iterator[List[int]]:
        yield current

        for i in range(index, len(array)):
            current.append(array[i])
            yield from helper(i + 1)

            current.pop()

    return helper()


cases = int(input())
for _ in range(cases):
    size, targetSum = map(int, input().split())

    array = sorted(int(token) for token in input().split())

    has = False
    results = (
        subArray
        for subArray in allSubArray(array)
        if sum(subArray) == targetSum
    )

    for subArray in results:
        elements = " ".join(map(str, subArray))
        print(f"[{elements}]", end=" ")

        has = True

    print("-1" if not has else "")

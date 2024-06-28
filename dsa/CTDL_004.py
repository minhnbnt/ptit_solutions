#!/usr/bin/env python3

"""
Cho dãy gồm N số phân biệt A = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100).

Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử
trong dãy đó thỏa mãn tính chất tăng dần.

Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số
A.

Ví dụ:

Input:
5 3
2 5 15 10 20

Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc
của dãy con.

Dòng kế tiếp: N số của dãy số A, các số trong dãy không lớn hơn 100.

thì Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)
"""

from typing import Iterator, List


def generate(array: List[int], rank: int) -> Iterator[List[int]]:
    subArray = []

    def helper(index=0) -> Iterator[List[int]]:
        if len(subArray) == rank:
            yield subArray

        while index < len(array):
            current = array[index]
            index += 1

            if len(subArray) > 0 and current < subArray[-1]:
                continue

            subArray.append(current)

            yield from helper(index)

            subArray.pop()

    yield from helper()


size, rank = map(int, input().split())
array = [int(token) for token in input().split()]

result = 0
for _ in generate(array, rank):
    result += 1

print(result)

#!/usr/bin/python3

"""
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K.

Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho tổng các
phần tử trong dãy con đó đúng bằng K.

Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:

5 50
5 10 15 20 25

Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết
cách nhau bởi một khoảng trống.

Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
10 15 25
5 20 25
5 10 15 20
3
"""

from typing import Iterator, List


def allSubarray(array: List[int]) -> Iterator[List[int]]:
    current = []

    def solve(index=0):
        yield current

        for i in range(index, len(array)):
            current.append(array[i])
            yield from solve(i + 1)

            current.pop()

    yield from solve()


size__, targetSum = (int(token) for token in input().split())
array = [int(token) for token in input().split()]

results = [
    list(subArray)
    for subArray in allSubarray(array)
    if sum(subArray) == targetSum
]

for subArray in reversed(results):
    print(*subArray)

print(len(results))

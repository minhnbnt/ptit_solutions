#!/usr/bin/env python3

"""
Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng
dần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N,
K (1 ≤ K ≤ N ≤ 16).

Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

Ví dụ:
Input
2
4 2
3 2

Output
0011
0101
0110
1001
1010
1100
011
101
110
"""

from typing import Iterator


def allBitsStr(length: int) -> Iterator[str]:
    current = []

    def generate() -> Iterator[str]:
        if len(current) == length:
            yield "".join(current)
            return

        for char in ["0", "1"]:
            current.append(char)
            yield from generate()

            current.pop()

    yield from generate()


cases = int(input())
for _ in range(cases):
    length, numberOfTrues = map(int, input().split())

    validBitStrings = (
        string  #
        for string in allBitsStr(length)
        if string.count("1") == numberOfTrues
    )

    for string in validBitStrings:
        print(string)

#!/usr/bin/env python3

"""
Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 10^9+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).

Output:
Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:
Input
2
5 2
10 3

Output
10
120
"""

from functools import lru_cache
from sys import setrecursionlimit

MOD = int(1e9 + 7)


@lru_cache(maxsize=None)
def combination(n: int, k: int) -> int:
    if n < k:
        return 0

    if k > n / 2:
        k = n - k

    if k == 0:
        return 1

    result = combination(n - 1, k - 1)
    result += combination(n - 1, k)
    result %= MOD

    return result


setrecursionlimit(1_000_000)

cases = int(input())
for _ in range(cases):
    n, k = map(int, input().split())
    print(combination(n, k))

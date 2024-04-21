from functools import lru_cache
from sys import setrecursionlimit

MOD = int(1e9 + 7)


@lru_cache(maxsize=None)
def combination(n: int, k: int) -> int:
    if n < k:
        return 0

    if k == 0 or k == n:
        return 1

    if k > n / 2:
        k = n - k

    result = combination(n - 1, k - 1)
    result += combination(n - 1, k)
    result %= MOD

    return result


setrecursionlimit(1_000_000)

cases = int(input())
for _ in range(cases):
    n, k = map(int, input().split())
    print(combination(n, k))

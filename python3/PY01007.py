from math import log, ceil

cases = int(input())

for _ in range(cases):
    initial, rate, target = map(float, input().split())
    result = log(target / initial, 1 + rate / 100)

    print(ceil(result))

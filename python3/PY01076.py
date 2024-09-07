from math import gcd

cases = int(input())

for _ in range(cases):
    a = int(input())
    b = int(input())

    print(gcd(a, b))

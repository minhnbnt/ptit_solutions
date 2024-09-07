cases = int(input())

for _ in range(cases):
    size = int(input())

    a1 = sorted(map(int, input().split()))
    a2 = sorted(map(int, input().split()))

    result = all(x1 <= x2 for x1, x2 in zip(a1, a2))
    print("YES" if result else "NO")

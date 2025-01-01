def is_valid(n: str) -> bool:
    left, right = 0, 0

    for i in range(1, len(n)):
        if n[i - 1] < n[i]:
            left = i
        else:
            break

    for i in range(len(n) - 1, 0, -1):
        if n[i] < n[i - 1]:
            right = i
        else:
            break

    return left + 1 == right


cases = int(input())

for _ in range(cases):
    number = input()
    print("YES" if is_valid(number) else "NO")

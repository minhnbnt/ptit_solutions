cases = int(input())

for _ in range(cases):
    number = input()

    first, last = number[:2], number[-2:]
    print("YES" if first == last else "NO")

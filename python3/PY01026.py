cases = int(input())

for i in range(cases):
    a, b = sorted(input()), sorted(input())
    print(f"Test {i + 1}:", "YES" if a == b else "NO")

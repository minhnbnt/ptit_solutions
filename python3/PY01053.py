def mod(x: str, y: int) -> int:
    mod = 0

    for digit in x:
        mod = mod * 10 + int(digit)
        mod %= y

    return mod


cases = int(input())

for _ in range(cases):
    number = input()
    print("YES" if mod(number, 3) == 0 else "NO")

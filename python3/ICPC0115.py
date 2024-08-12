def primorial(n: int) -> int:
    if n < 2:
        return 1

    return n * primorial(n - 1)


def is_krish_number(n: int) -> bool:
    temp = n

    while n > 0:
        temp -= primorial(n % 10)
        n //= 10

    return temp == 0


cases = int(input())

for _ in range(cases):
    number = int(input())
    print("Yes" if is_krish_number(number) else "No")

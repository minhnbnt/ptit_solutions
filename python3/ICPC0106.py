from string import hexdigits


def get_number(n: int, base: int) -> str:
    if n == 0:
        return "0"

    lastDigit = hexdigits[n % base]
    others = get_number(n // base, base)

    return others.lstrip("0") + lastDigit


cases = int(input())

for _ in range(cases):
    outputBase = int(input())
    number = int(input(), base=2)

    print(get_number(number, outputBase).upper())

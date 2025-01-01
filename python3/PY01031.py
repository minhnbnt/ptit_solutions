import string

ALPHABET = string.digits + string.ascii_uppercase


def format_number(n: int, base: int) -> str:
    digits = []

    while n > 0:
        digits.append(ALPHABET[n % base])
        n //= base

    return "".join(reversed(digits))


cases = int(input())

for _ in range(cases):
    number, base = (int(token) for token in input().split())
    print(format_number(number, base))

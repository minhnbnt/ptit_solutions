from string import hexdigits


def convert_to_base(number: int, n: int) -> str:
    digits = []
    while number > 0:
        digits.append(hexdigits[number % n])
        number //= n

    if not digits:
        digits.append("0")

    return "".join(reversed(digits)).upper()


with open("DATA.in") as fp:
    cases = int(fp.readline())

    for _ in range(cases):
        base, number = int(fp.readline()), int(fp.readline(), base=2)
        print(convert_to_base(number, base))

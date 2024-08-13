from functools import reduce

cases = int(input())

for _ in range(cases):
    number = input()
    elements = (int(digit) for digit in number if digit != "0")

    print(reduce(lambda a, b: a * b, elements))

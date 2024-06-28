MONEY_VALUES = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000]

cases = int(input())
for _ in range(cases):
    money = int(input())

    result = 0
    for bankNote in sorted(MONEY_VALUES, reverse=True):
        result += money // bankNote
        money %= bankNote

    print(result)

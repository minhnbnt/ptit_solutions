MONEY_VALUES = [1000, 500, 200, 100, 50, 20, 10, 5, 2, 1]

cases = int(input())
for _ in range(cases):
    money = int(input())

    result = 0
    for bankNote in MONEY_VALUES:
        result += money // bankNote
        money %= bankNote

    print(result)

def sum_of_digits(n: int) -> int:
    result = 0
    while n > 0:
        result += n % 10
        n //= 10

    return result


cases = int(input())

for _ in range(cases):
    _size = int(input())
    array = list(map(int, input().split()))

    result = sorted(array, key=lambda x: (sum_of_digits(x), x))
    print(*result)

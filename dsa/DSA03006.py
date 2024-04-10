cases = int(input())

for _ in range(cases):
    size, leftSize = map(int, input().split())
    array = sorted(map(int, input().split()))

    if leftSize > size // 2:
        leftSize = size - leftSize

    sumLeft = sum(array[:leftSize])
    sumRight = sum(array[leftSize:])

    print(sumRight - sumLeft)

cases = int(input())

for _ in range(cases):
    _, n = map(int, input().split())
    array = list(map(int, input().split()))

    maxElement = max(array)
    maxElementIndex = array.index(maxElement)
    array.insert(maxElementIndex, n)

    negative = [elem for elem in array if elem < 0]
    positive = [elem for elem in array if elem >= 0]

    print(*negative, *positive)

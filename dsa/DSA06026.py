from itertools import count

size = int(input())
array = list(map(int, input().split()))

for step in count(1):
    isSorted = True

    for i in range(1, size):
        if array[i - 1] <= array[i]:
            continue

        isSorted = False
        array[i - 1], array[i] = array[i], array[i - 1]

    if isSorted:
        break

    print(f"Buoc {step}:", *array)

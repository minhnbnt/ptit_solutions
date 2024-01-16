size = int(input())

array = list(map(int, input().split()))

step = 0
while True:
    isSorted = True

    for i in range(1, size):
        if array[i - 1] <= array[i]:
            continue

        isSorted = False
        array[i - 1], array[i] = array[i], array[i - 1]

    if isSorted:
        break

    step += 1
    print(f"Buoc {step}:", *array)

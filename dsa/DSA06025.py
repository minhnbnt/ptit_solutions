size = int(input())

array = [int(token) for token in input().split()]

for i, element in enumerate(array):
    j = i - 1

    while j >= 0 and array[j] > element:
        array[j + 1] = array[j]
        j -= 1

    array[j + 1] = element

    print(f"Buoc {i}:", *array[: i + 1 :])

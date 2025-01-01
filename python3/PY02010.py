while True:
    array_length = int(input())

    if array_length == 0:
        break

    array = [int(input()) for _ in range(array_length)]

    min_elem, max_elem = min(array), max(array)
    if min_elem == max_elem:
        print("BANG NHAU")
    else:
        print(min_elem, max_elem)

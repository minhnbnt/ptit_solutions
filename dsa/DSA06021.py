cases = int(input())
for _ in range(cases):
    size__, target = map(int, input().split())

    array = list(map(int, input().split()))
    print(array.index(target) + 1)

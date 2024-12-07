def tower_of_hanoi(n: int, a: str, b: str, c: str) -> None:
    if n == 0:
        return

    tower_of_hanoi(n - 1, a, c, b)
    print(a, "->", c)
    tower_of_hanoi(n - 1, b, a, c)


n = int(input())
tower_of_hanoi(n, "A", "B", "C")

from itertools import count


def main():
    a, K, N = (int(token) for token in input().split())

    bMin = K - (a % K)
    if a + bMin > N:
        print(-1)
        return

    for b in count(start=bMin, step=K):
        if a + b > N:
            break

        print(b, end=" ")


if __name__ == "__main__":
    main()

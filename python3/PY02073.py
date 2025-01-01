import heapq


def compute_cost(
    target_length: int,
    insert_cost: int,
    delete_cost: int,
    copy_cost: int,
) -> int:
    queue = [(0, 0)]
    visited_length = set()

    while True:
        cost, length = heapq.heappop(queue)
        if length == target_length:
            return cost

        elif length in visited_length:
            continue

        visited_length.add(length)

        heapq.heappush(queue, (cost + insert_cost, length + 1))
        heapq.heappush(queue, (cost + copy_cost, length * 2))

        if length > 1:
            heapq.heappush(queue, (cost + delete_cost, length - 1))


cases = int(input())

for _ in range(cases):
    length = int(input())

    insert_cost, delete_cost, copy_cost = (
        int(token) for token in input().split()
    )

    print(compute_cost(length, insert_cost, delete_cost, copy_cost))

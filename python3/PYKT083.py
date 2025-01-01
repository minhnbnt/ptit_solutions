from collections import defaultdict
from typing import Dict

PRICE_MAP = {
    ("Xe_con", 5): 10000,
    ("Xe_con", 7): 15000,
    ("Xe_tai", 2): 20000,
    ("Xe_khach", 29): 50000,
    ("Xe_khach", 45): 70000,
}

cases = int(input())

results: Dict[str, int] = defaultdict(lambda: 0)
for _ in range(cases):
    _, vehicle_type, seats, direction, date = input().split()  # type: ignore

    if direction != "OUT":
        results[date] += PRICE_MAP[(vehicle_type, int(seats))]

for day, revenue in results.items():
    print(f"{day}: {revenue}")

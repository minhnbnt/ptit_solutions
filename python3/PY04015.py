from dataclasses import dataclass


@dataclass
class Customer:
    id: str
    name: str
    money: int

    def __str__(self) -> str:
        return f"{self.id} {self.name} {self.money}"


def compute_money(diff: int) -> int:
    money = diff * 100 * 1.02
    if diff > 100:
        money = (12500 + (diff - 100) * 200) * 1.05

    elif diff > 50:
        money = (5000 + (diff - 50) * 150) * 1.03

    return round(money)


size = int(input())

customers = []
for i in range(size):
    name = input()

    before = int(input())
    after = int(input())

    customers.append(
        Customer(
            id=f"KH{i + 1:02}",
            name=name,
            money=compute_money(after - before),
        )
    )

for customer in sorted(customers, key=lambda c: c.money, reverse=True):
    print(customer)

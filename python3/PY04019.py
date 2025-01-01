from dataclasses import dataclass


@dataclass
class Staff:
    id: str
    name: str
    score: float

    def get_type(self) -> str:
        score = self.score

        if score < 5:
            return "TRUOT"

        if score < 8:
            return "CAN NHAC"

        if score <= 9.5:
            return "DAT"

        return "XUAT SAC"

    def __str__(self) -> str:
        return f"{self.id} {self.name} {self.score:.2f} {self.get_type()}"


def get_score() -> float:
    score = float(input())
    if score > 10:
        score /= 10

    return score


size = int(input())
staff_list = list()

for i in range(size):
    name = input()

    theory_score = get_score()
    practice_score = get_score()

    staff_list.append(
        Staff(
            id=f"TS0{i + 1}",
            name=name,
            score=(theory_score + practice_score) / 2,
        )
    )

for staff in sorted(staff_list, key=lambda s: s.score, reverse=True):
    print(staff)

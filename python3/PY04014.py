from dataclasses import dataclass
from typing import List


@dataclass
class Student:
    id: str
    name: str
    scores: List[float]

    def avg_score(self) -> float:
        score_total = sum(self.scores) + sum(self.scores[:2])
        return score_total / 10 / 1.2

    def tier(self) -> str:
        avg_score = self.avg_score()

        if avg_score < 5:
            return "YEU"

        if avg_score < 7:
            return "TB"

        if avg_score < 8:
            return "KHA"

        if avg_score < 9:
            return "GIOI"

        return "XUAT SAC"

    def __str__(self):
        return f"{self.id} {self.name} {self.avg_score():.1f} {self.tier()}"


students = []

size = int(input())
for i in range(size):
    students.append(
        Student(
            id=f"HS{i + 1:02d}",
            name=input(),
            scores=[float(token) for token in input().split()],
        )
    )

for student in sorted(students, key=lambda s: s.avg_score(), reverse=True):
    print(student)

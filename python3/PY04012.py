from dataclasses import dataclass
from typing import Optional


@dataclass
class Student(object):
    id: str
    name: str
    grade: str
    statuses: Optional[str]

    def get_daily_score(self) -> int:
        if self.statuses is None:
            return 10

        score = 10
        score -= self.statuses.count("m")
        score -= self.statuses.count("v") * 2

        if score < 0:
            score = 0

        return score

    def able_to_take_exam(self) -> bool:
        return self.get_daily_score() > 0

    def __str__(self) -> str:
        result = f"{self.id} {self.name} {self.grade} {self.get_daily_score()} "

        if not self.able_to_take_exam():
            result += "KDDK"

        return result


size = int(input())

students = dict()

for _ in range(size):
    id = input()

    students[id] = Student(
        id,
        name=input(),
        grade=input(),
        statuses=None,
    )

for _ in range(size):
    id, statuses = input().split()
    students[id].statuses = statuses

for student in students.values():
    print(student)

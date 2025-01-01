from dataclasses import dataclass

MINIMUM_SCORE = 20.5


@dataclass
class Student:
    id: str
    name: str
    score: float
    race: str
    region: int

    def get_additional_score(self) -> float:
        result: float = 0
        if self.region == 1:
            result += 1.5

        elif self.region == 2:
            result += 1

        if self.race != "Kinh":
            result += 1.5

        return result

    def get_total_score(self) -> float:
        return self.score + self.get_additional_score()

    def is_failed(self) -> bool:
        return self.get_total_score() < MINIMUM_SCORE

    def __str__(self) -> str:
        status = "Truot" if self.is_failed() else "Do"
        return f"{self.id} {self.name} {self.get_total_score():.1f} {status}"


def title_string(s: str) -> str:
    return " ".join(token.title() for token in s.split())


size = int(input())
students = [
    Student(
        id=f"TS{i + 1:02}",
        name=title_string(input()),
        score=float(input()),
        race=input(),
        region=int(input()),
    )
    for i in range(size)
]

students.sort(key=lambda s: s.get_total_score(), reverse=True)

for student in students:
    print(student)

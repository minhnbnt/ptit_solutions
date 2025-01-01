from __future__ import annotations
from dataclasses import dataclass


class Time:
    def __init__(self, string: str) -> None:
        self.hour, self.minute = (  #
            int(token) for token in string.split(":")
        )

    def __sub__(self, other: Time) -> Time:
        hour = self.hour - other.hour
        minute = self.minute - other.minute

        if minute < 0:
            minute += 60
            hour -= 1

        return Time(f"{hour}:{minute}")

    def __str__(self) -> str:
        return f"{self.hour} gio {self.minute} phut"

    def __lt__(self, other: Time) -> bool:
        if self.hour != other.hour:
            return self.hour < other.hour

        return self.minute < other.minute


@dataclass
class Gamer:
    id: str
    name: str
    duration: Time

    def __str__(self) -> str:
        return f"{self.id} {self.name} {self.duration}"


size = int(input())

gamers = []

for _ in range(size):
    id = input()
    name = input()

    begin = Time(input())
    end = Time(input())

    gamers.append(
        Gamer(
            id,
            name,
            duration=end - begin,
        )
    )

gamers.sort(key=lambda g: g.duration, reverse=True)

for gamer in gamers:
    print(gamer)

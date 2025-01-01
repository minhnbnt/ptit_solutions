from __future__ import annotations
from dataclasses import dataclass
from typing import Dict


class Time:
    def __init__(self, string: str):
        self.hour, self.minute = (  #
            int(token) for token in string.split(":")
        )

    def __sub__(self, other: Time) -> float:
        return (
            (self.hour - other.hour)  #
            + (self.minute - other.minute) / 60
        )


@dataclass
class Location:
    id: str
    name: str
    duration: float
    total_rain_fall: float

    def __str__(self) -> str:
        avg_rain_fall = self.total_rain_fall / self.duration
        return f"{self.id} {self.name} {avg_rain_fall:.2f}"


cases = int(input())

locations: Dict[str, Location] = dict()
for i in range(cases):
    location_name = input()

    location = locations.get(location_name)
    if location is None:
        id_number = len(locations) + 1
        location = Location(
            id=f"T{id_number:02}",
            name=location_name,
            total_rain_fall=0,
            duration=0,
        )

        locations[location_name] = location

    start = Time(input())
    end = Time(input())

    rain_fall = float(input())

    location.duration += end - start
    location.total_rain_fall += rain_fall

for location in locations.values():
    print(location)

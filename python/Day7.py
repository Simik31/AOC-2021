import sys


def part_1() -> None:
    positions: list[int] = []

    with open("../data/day7.txt", "r") as dFile:
        for num_s in dFile.readline().split(","):
            positions.append(int(num_s))

    min_cost = sys.maxsize

    for end_position in set(positions):
        position_cost: int = sum(
            max(crab_position, end_position) - min(crab_position, end_position)
            for crab_position in positions
        )

        min_cost = min(min_cost, position_cost)

    print("Day:  7 | Part: 1 | Result:", min_cost)


def part_2() -> None:
    positions: list[int] = []

    with open("../data/day7.txt", "r") as dFile:
        for num_s in dFile.readline().split(","):
            positions.append(int(num_s))

    min_cost: int = sys.maxsize

    for end_position in range(1, max(positions)):
        min_cost = min(
            min_cost,
            sum(
                sum(range(1, abs(end_position - crab_position) + 1))
                for crab_position in positions
            ),
        )

    print("Day:  7 | Part: 2 | Result:", min_cost)


if __name__ == "__main__":
    part_1()
    part_2()

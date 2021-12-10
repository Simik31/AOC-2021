def part_1() -> None:
    result: int = 0
    with open("../data/day_8.txt") as dFile:
        result = sum(
            sum(
                len(output) in [2, 4, 3, 7]
                for output in row.split(" | ")[1].strip().split(" ")
            )
            for row in dFile.readlines()
        )

    print("Day:  8 | Part 1 | Result:", result)


if __name__ == "__main__":
    part_1()

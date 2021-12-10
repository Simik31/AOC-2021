def part_1() -> None:
    ages: dict[int, int] = {age: 0 for age in range(-1, 9)}

    with open("../data/day6.txt", "r") as dFile:
        for num_s in dFile.readline().split(","):
            ages[int(num_s)] += 1

    for _ in range(80):
        ages = {age: ages[age + 1] for age in range(-1, 8)}
        ages[6] += ages[-1]
        ages[8] = ages[-1]

    print("Day:  6 | Part: 1 | Result:", sum(ages[day] for day in range(9)))


def part_2() -> None:
    ages: dict[int, int] = {age: 0 for age in range(-1, 9)}

    with open("../data/day6.txt", "r") as dFile:
        for num_s in dFile.readline().split(","):
            ages[int(num_s)] += 1

    for _ in range(256):
        ages = {age: ages[age + 1] for age in range(-1, 8)}
        ages[6] += ages[-1]
        ages[8] = ages[-1]

    print("Day:  6 | Part: 2 | Result:", sum(ages[day] for day in range(9)))


if __name__ == "__main__":
    part_1()
    part_2()

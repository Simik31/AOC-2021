def part_1() -> None:
    last: int = -1
    count: int = 0

    with open("../data/day1.txt", "r") as dFile:
        for row in dFile.readlines():
            num = int(row)

            if last > 0 and num > last:
                count += 1

            last = num

    print("Day:  1 | Part: 1 | Result:", count)


def part_2() -> None:
    nums: list[int] = list()

    with open("../data/day1.txt", "r") as dFile:
        nums = [int(row) for row in dFile.readlines()]

    last: int = -1
    count: int = 0

    for index in range(len(nums) - 2):
        num: int = sum(nums[index + off] for off in range(3))

        if last > 0 and num > last:
            count += 1

        last = num

    print("Day:  1 | Part: 2 | Result:", count)


if __name__ == "__main__":
    part_1()
    part_2()

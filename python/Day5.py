def part_1() -> None:
    x1: list[int] = []
    y1: list[int] = []
    x2: list[int] = []
    y2: list[int] = []

    with open("../data/day5.txt", "r") as dFile:
        for row in dFile.readlines():
            one, two = row.split(" -> ")
            x_one, y_one = one.split(",")
            x_two, y_two = two.split(",")

            x1.append(int(x_one))
            y1.append(int(y_one))
            x2.append(int(x_two))
            y2.append(int(y_two))

    max_x: int = max(max(x1), max(x2))
    max_y: int = max(max(y1), max(y2))

    vents: list[list[int]] = [[0 for _ in range(max_x + 1)] for _ in range(max_y + 1)]

    for index in range(len(x1)):
        x_one: int = x1[index]
        y_one: int = y1[index]
        x_two: int = x2[index]
        y_two: int = y2[index]

        if x_one > x_two:
            x_one, x_two = x_two, x_one
        if y_one > y_two:
            y_one, y_two = y_two, y_one

        if x_one == x_two:
            for y in range(y_one, y_two + 1):
                vents[y][x_one] += 1
        elif y_one == y_two:
            for x in range(x_one, x_two + 1):
                vents[y_one][x] += 1

    counter: int = 0
    for row in vents:
        for cell in row:
            if cell >= 2:
                counter += 1

    print("Day:  5 | Part: 1 | Result:", counter)


def part_2() -> None:
    x1: list[int] = []
    y1: list[int] = []
    x2: list[int] = []
    y2: list[int] = []

    with open("../data/day5.txt", "r") as dFile:
        for row in dFile.readlines():
            one, two = row.split(" -> ")
            x_one, y_one = one.split(",")
            x_two, y_two = two.split(",")

            x1.append(int(x_one))
            y1.append(int(y_one))
            x2.append(int(x_two))
            y2.append(int(y_two))

    max_x: int = max(max(x1), max(x2))
    max_y: int = max(max(y1), max(y2))

    vents: list[list[int]] = [[0 for _ in range(max_x + 1)] for _ in range(max_y + 1)]

    for index in range(len(x1)):
        x_one: int = x1[index]
        y_one: int = y1[index]
        x_two: int = x2[index]
        y_two: int = y2[index]

        if x_one == x_two:
            if y_one > y_two:
                y_one, y_two = y_two, y_one

            for y in range(y_one, y_two + 1):
                vents[y][x_one] += 1
        elif y_one == y_two:
            if x_one > x_two:
                x_one, x_two = x_two, x_one

            for x in range(x_one, x_two + 1):
                vents[y_one][x] += 1
        else:
            if x_one > x_two:
                x_one, x_two = x_two, x_one
                y_one, y_two = y_two, y_one

            for o in range(x_two - x_one + 1):
                vents[y_one + o if y_one < y_two else y_one - o][x_one + o] += 1

    counter: int = 0
    for row in vents:
        for cell in row:
            if cell >= 2:
                counter += 1

    print("Day:  5 | Part: 2 | Result:", counter)


if __name__ == "__main__":
    part_1()
    part_2()

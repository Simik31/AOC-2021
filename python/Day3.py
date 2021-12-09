def part_1() -> None:
    data: list[str] = []

    with open("../data/day3.txt", "r") as dFile:
        data = [row.strip() for row in dFile.readlines()]

    gama: int = 0
    epsilon: int = 0

    for i in range(len(data[0])):
        counter: list = [0, 0]

        for row in data:
            counter[int(row[i])] += 1

        gama = (gama << 1) + counter.index(max(counter))
        epsilon = (epsilon << 1) + counter.index(min(counter))

    print("Day:  3 | Part: 1 | Result:", gama * epsilon)


def part_2() -> None:
    data_og: list[str] = []

    with open("../data/day3.txt", "r") as dFile:
        data_og = [row.strip() for row in dFile.readlines()]

    data_co2s: list[str] = data_og.copy()

    for i in range(len(data_og[0])):
        if len(data_og) > 1:
            counter: list = [0, 0]

            for row in data_og:
                counter[int(row[i])] += 1

            data_og = list(
                filter(
                    lambda r: r[i] == ("1" if counter[1] >= counter[0] else "0"),
                    data_og,
                )
            )

        if len(data_co2s) > 1:
            counter: list = [0, 0]

            for row in data_co2s:
                counter[int(row[i])] += 1

            data_co2s = list(
                filter(
                    lambda r: r[i] == ("0" if counter[1] >= counter[0] else "1"),
                    data_co2s,
                )
            )

        if len(data_og) == 1 and len(data_co2s) == 1:
            break

    print("Day:  3 | Part: 2 | Result:", int(data_og[0], 2) * int(data_co2s[0], 2))


if __name__ == "__main__":
    part_1()
    part_2()

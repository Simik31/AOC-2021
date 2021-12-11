def part_1() -> None:
    height_map: list[list[int]] = []
    lowest_truths: list[list[bool]] = []

    with open("../data/day9.txt") as dFile:
        for row in dFile.readlines():
            if (row := row.strip()) != "":
                height_map.append([])
                lowest_truths.append([])
                for num in row:
                    height_map[-1].append(int(num))
                    lowest_truths[-1].append(False)

    for r in range(len(height_map)):
        for c in range(len(height_map[r])):
            truths: list[bool] = []
            if r >= 1:
                truths.append(height_map[r][c] < height_map[r - 1][c])
            if r + 1 < len(height_map):
                truths.append(height_map[r][c] < height_map[r + 1][c])
            if c >= 1:
                truths.append(height_map[r][c] < height_map[r][c - 1])
            if c + 1 < len(height_map[r]):
                truths.append(height_map[r][c] < height_map[r][c + 1])

            lowest_truths[r][c] = False not in truths

    result: int = sum(
        height_map[r][c] + 1
        for r in range(len(height_map))
        for c in range(len(height_map[r]))
        if lowest_truths[r][c]
    )

    print("Day:  9 | Part: 1 | Result: ", result)


def backtrack_basin(
    height_map: list[list[int]],
    r: int,
    c: int,
    counter: int,
    visited: list[tuple[int, int]],
) -> int:
    if (r, c) in visited:
        return counter

    visited.append((r, c))

    if height_map[r][c] == 9:
        return counter

    counter += 1

    if r >= 1:
        counter = backtrack_basin(height_map, r - 1, c, counter, visited)
    if r + 1 < len(height_map):
        counter = backtrack_basin(height_map, r + 1, c, counter, visited)
    if c >= 1:
        counter = backtrack_basin(height_map, r, c - 1, counter, visited)
    if c + 1 < len(height_map[r]):
        counter = backtrack_basin(height_map, r, c + 1, counter, visited)

    return counter


def part_2() -> None:
    height_map: list[list[int]] = []
    lowest_truths: list[list[bool]] = []

    with open("../data/day9.txt") as dFile:
        for row in dFile.readlines():
            if (row := row.strip()) != "":
                height_map.append([])
                lowest_truths.append([])
                for num in row:
                    height_map[-1].append(int(num))
                    lowest_truths[-1].append(False)

    for r in range(len(height_map)):
        for c in range(len(height_map[r])):
            truths: list[bool] = []
            if r >= 1:
                truths.append(height_map[r][c] < height_map[r - 1][c])
            if r + 1 < len(height_map):
                truths.append(height_map[r][c] < height_map[r + 1][c])
            if c >= 1:
                truths.append(height_map[r][c] < height_map[r][c - 1])
            if c + 1 < len(height_map[r]):
                truths.append(height_map[r][c] < height_map[r][c + 1])

            lowest_truths[r][c] = False not in truths

    basins: list[int] = []

    for r in range(len(height_map)):
        for c in range(len(height_map[r])):
            if lowest_truths[r][c]:
                basins.append(backtrack_basin(height_map, r, c, 0, []))

    basins.sort()
    print(basins)
    result: int = basins[-1] * basins[-2] * basins[-3]

    print("Day:  9 | Part: 2 | Result: ", result)


if __name__ == "__main__":
    part_1()
    part_2()

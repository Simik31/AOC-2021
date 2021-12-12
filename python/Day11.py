def flash(grid: list[list[list[int, bool]]], x: int, y: int, counter: int) -> int:
    if grid[y][x][1]:
        return counter

    grid[y][x][0] += 1

    if grid[y][x][0] > 9:
        grid[y][x][0] = 0
        grid[y][x][1] = True
        counter += 1

        for y_off in [-1, 0, 1]:
            for x_off in [-1, 0, 1]:
                if y + y_off in range(len(grid)) and x + x_off in range(
                    len(grid[y + y_off])
                ):
                    counter = flash(grid, x + x_off, y + y_off, counter)

    return counter


def part_1() -> None:
    grid: list[list[list[int, bool]]] = []

    with open("../data/day11.txt", "r") as dFile:
        for line in dFile.readlines():
            grid.append([])
            for num in line.strip():
                grid[-1].append([int(num), False])

    counter: int = 0
    for _ in range(1, 101):
        for row in grid:
            for col in row:
                col[1] = False

        for row in range(len(grid)):
            for col in range(len(grid[row])):
                counter = flash(grid, col, row, counter)

    print("Day: 11 | Part: 1 | Result:", counter)


def part_2() -> None:
    grid: list[list[list[int, bool]]] = []

    with open("../data/day11.txt", "r") as dFile:
        for line in dFile.readlines():
            grid.append([])
            for num in line.strip():
                grid[-1].append([int(num), False])

    step: int = 0
    while not all(map(lambda row: all(map(lambda col: col[1], row)), grid)):
        step += 1
        for row in grid:
            for col in row:
                col[1] = False

        for row in range(len(grid)):
            for col in range(len(grid[row])):
                flash(grid, col, row, 0)

    print("Day: 11 | Part: 2 | Result:", step)


if __name__ == "__main__":
    part_1()
    part_2()

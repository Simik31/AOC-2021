import re


def test_board_for_bingo(marked: list[list[bool]]) -> bool:
    for row_id in range(len(marked)):
        row_true: bool = True
        col_true: bool = True

        for cell_id in range(len(marked[row_id])):
            if not marked[row_id][cell_id]:
                row_true = False

            if not marked[cell_id][row_id]:
                col_true = False

        if row_true or col_true:
            return True

    return False


def part_1() -> None:
    rows: list[list[list[int]]] = []
    mark: list[list[list[bool]]] = []

    lines: list[str] = list()
    with open("../data/day4.txt", "r") as dFile:
        lines = [row for row in dFile.readlines()]

    order: list[int] = [int(num) for num in lines[0].split(",")]

    for line in lines[1:]:
        if line == "\n":
            rows.append([])
            mark.append([])
        else:
            rows[-1].append([])
            mark[-1].append([])

            for num_s in re.split("([^\\d])", line):
                if num_s not in ["", " ", "\n"]:
                    rows[-1][-1].append(int(num_s))
                    mark[-1][-1].append(False)

    bingo: int = -1
    last_draw: int = None

    for draw in order:
        for b in range(len(rows)):
            for r in range(len(rows[b])):
                for n in range(len(rows[b][r])):
                    if rows[b][r][n] == draw:
                        mark[b][r][n] = True

        last_draw = draw

        for index in range(len(mark)):
            if test_board_for_bingo(mark[index]):
                bingo = index

        if bingo != -1:
            break

    board_sum: int = 0

    for r in range(len(rows[bingo])):
        for n in range(len(rows[bingo][r])):
            if not mark[bingo][r][n]:
                board_sum += rows[bingo][r][n]

    print("Day:  4 | Part: 1 | Result:", board_sum * last_draw)


def part_2() -> None:
    bins: list[bool] = []
    rows: list[list[list[int]]] = []
    mark: list[list[list[bool]]] = []

    lines: list[str] = list()
    with open("../data/day4.txt", "r") as dFile:
        lines = [row for row in dFile.readlines()]

    order: list[int] = [int(num) for num in lines[0].split(",")]

    for line in lines[1:]:
        if line == "\n":
            bins.append(False)
            rows.append([])
            mark.append([])
        else:
            rows[-1].append([])
            mark[-1].append([])

            for num_s in re.split("([^\\d])", line):
                if num_s not in ["", " ", "\n"]:
                    rows[-1][-1].append(int(num_s))
                    mark[-1][-1].append(False)

    bingo: int = -1
    last_draw: int = -1
    bingo_count: int = 0

    for draw in order:
        for b in range(len(rows)):
            for r in range(len(rows[b])):
                for n in range(len(rows[b][r])):
                    if rows[b][r][n] == draw:
                        mark[b][r][n] = True

        last_draw = draw

        for index in range(len(mark)):
            if not bins[index] and test_board_for_bingo(mark[index]):
                bins[index] = True
                bingo_count += 1
                bingo = index

        if bingo_count == len(bins):
            break

    board_sum: int = 0

    for r in range(len(rows[bingo])):
        for n in range(len(rows[bingo][r])):
            if not mark[bingo][r][n]:
                board_sum += rows[bingo][r][n]

    print("Day:  4 | Part: 2 | Result:", board_sum * last_draw)

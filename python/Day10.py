def part_1() -> None:
    opens: list[str] = ["(", "[", "{", "<"]
    closes: list[str] = [")", "]", "}", ">"]
    incorects: dict[str, int] = {char: 0 for char in closes}

    with open("../data/day10.txt", "r") as dFile:
        for line in dFile.readlines():
            pairs: list[str] = []
            for char in line.strip():
                if char in opens:
                    pairs.append(char)
                elif opens.index(pairs[-1]) == closes.index(char):
                    pairs.pop()
                else:
                    incorects[char] += 1
                    break

    result: int = (
        incorects[")"] * 3
        + incorects["]"] * 57
        + incorects["}"] * 1197
        + incorects[">"] * 25137
    )

    print("Day: 10 | Part: 1 | Result:", result)


def part_2() -> None:
    opens: list[str] = ["(", "[", "{", "<"]
    closes: list[str] = [")", "]", "}", ">"]
    scores: list[list[str]] = []

    with open("../data/day10.txt", "r") as dFile:
        for line in dFile.readlines():
            pairs: list[str] = []
            score: int = 0
            corrupted: bool = False

            for char in line.strip():
                if char in opens:
                    pairs.append(char)
                elif opens.index(pairs[-1]) == closes.index(char):
                    pairs.pop()
                else:
                    corrupted = True
                    break

            if not corrupted:
                while pairs:
                    score = score * 5 + opens.index(pairs.pop()) + 1
                    scores.append(score)

    scores.sort()
    result: int = scores[int(len(scores) / 2)]

    print("Day: 10 | Part: 2 | Result:", result)


if __name__ == "__main__":
    part_1()
    part_2()

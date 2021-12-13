def part_1() -> None:
    paper: list[list[bool]] = []

    with open("../data/day13.txt", "r") as dFile:
        while (line := dFile.readline().strip()) != "":
            x, y = line.split(",")
            x, y = int(x), int(y)

            while y not in range(len(paper)):
                paper.append([])

            while x not in range(len(paper[y])):
                paper[y].append(False)

            paper[y][x] = True

        longest: int = max(len(line) for line in paper)
        for line in paper:
            while len(line) < longest:
                line.append(False)

        fold_line = dFile.readline()
        interest = fold_line[fold_line.strip().rfind(" ") + 1 :]
        fold_axis, fold_index = interest.split("=")
        fold_index = int(fold_index)

        if fold_axis == "x":
            for line in range(len(paper)):
                for index in range(longest - fold_index - 1):
                    paper[line][index] |= paper[line][longest - index - 1]
                paper[line] = paper[line][:fold_index]

        elif fold_axis == "y":
            for line in range(len(paper) - fold_index - 1):
                for index in range(longest):
                    paper[line][index] |= paper[len(paper) - line - 1][index]
            paper = paper[:fold_index]

        result = sum(1 for line in paper for char in line if char)

        print("Day: 13 | Part: 1 | Result:", result)


def part_2() -> None:
    paper: list[list[bool]] = []

    with open("../data/day13.txt", "r") as dFile:
        while (line := dFile.readline().strip()) != "":
            x, y = line.split(",")
            x, y = int(x), int(y)

            while y not in range(len(paper)):
                paper.append([])

            while x not in range(len(paper[y])):
                paper[y].append(False)

            paper[y][x] = True

        longest: int = max(len(line) for line in paper)
        for line in paper:
            while len(line) < longest:
                line.append(False)

        for fold_line in dFile.readlines():

            interest = fold_line[fold_line.strip().rfind(" ") + 1 :]
            fold_axis, fold_index = interest.split("=")
            fold_index = int(fold_index)

            longest = max(len(line) for line in paper)

            if fold_axis == "x":
                for line in range(len(paper)):
                    for index in range(longest - fold_index - 1):
                        paper[line][index] |= paper[line][longest - index - 1]
                    paper[line] = paper[line][:fold_index]

            elif fold_axis == "y":
                for line in range(len(paper) - fold_index - 1):
                    for index in range(longest):
                        paper[line][index] |= paper[len(paper) - line - 1][index]
                paper = paper[:fold_index]

        print("Day: 13 | Part: 2 | Result:")
        for line in paper:
            for char in line:
                print("#" if char else " ", end="")
            print()


if __name__ == "__main__":
    part_1()
    part_2()

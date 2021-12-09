def part_1() -> None:   
    h_pos: int = 0
    v_pos: int = 0
     
    with open("../data/day2.txt", "r") as dFile:
        for row in dFile.readlines():     
            value: int = int(row.split(" ")[1])
            
            match row.split(" ")[0]:
                case "forward":
                    h_pos += value
                case "down":
                    v_pos += value
                case "up":
                    v_pos -= value
                case _:
                    raise ValueError(f"Unsupported command {row.split(' ')[0]}")

    print("Day:  2 | Part: 1 | Result:", h_pos * v_pos)


def part_2() -> None:
    h_pos: int = 0
    v_pos: int = 0
    aim : int = 0
     
    with open("../data/day2.txt", "r") as dFile:
        for row in dFile.readlines():     
            value: int = int(row.split(" ")[1])
            
            match row.split(" ")[0]:
                case "forward":
                    h_pos += value
                    v_pos += value * aim
                case "down":
                    aim += value
                case "up":
                    aim -= value
                case _:
                    raise ValueError(f"Unsupported command {row.split(' ')[0]}")

    print("Day:  2 | Part: 2 | Result:", h_pos * v_pos)


if __name__ == "__main__":
    part_1()
    part_2()

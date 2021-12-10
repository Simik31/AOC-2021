<?php
    require_once('Utils.php');

    function Day2_Part1() {
        $h_pos = 0;
        $v_pos = 0;

        foreach (read_file_lines("../data/day2.txt") as $line) {
            $value = (int) explode(' ',  $line)[1];

            switch (explode(' ', $line)[0]) {
                case "forward":
                    $h_pos += $value;
                    break;
                case "down":
                    $v_pos += $value;
                    break;
                case "up":
                    $v_pos -= $value;
                    break;
                default:
                    throw new Exception("Unsupported direction " . explode(' ', $line)[0]);
            }
        }
        
        echo "Day:  2 | Part: 1 | Result: " . ($h_pos * $v_pos) . "<br>";
    }

    function Day2_Part2() {
        $h_pos = 0;
        $v_pos = 0;
        $aim = 0;

        foreach (read_file_lines("../data/day2.txt") as $line) {
            $value = (int) explode(' ',  $line)[1];

            switch (explode(' ', $line)[0]) {
                case "forward":
                    $h_pos += $value;
                    $v_pos += $value * $aim;
                    break;
                case "down":
                    $aim += $value;
                    break;
                case "up":
                    $aim -= $value;
                    break;
                default:
                    throw new Exception("Unsupported direction " . explode(' ', $line)[0]);
            }
        }
        
        echo "Day:  2 | Part: 1 | Result: " . ($h_pos * $v_pos) . "<br>";

    }

    Day2_Part1();
    Day2_Part2();
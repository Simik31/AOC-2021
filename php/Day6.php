<?php
    require_once('Utils.php');

    function Day6_Part1() {
        $ages = array(-1 => 0, 0 => 0, 1 => 0, 2 => 0, 3 => 0, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0);

        foreach (explode(",", read_file_lines("../data/day6.txt")[0]) as $num) {
            $ages[$num]++;
        }


        for ($day = 0; $day < 80; $day++) {
            for ($age = -1; $age < 8; $age++)
                $ages[$age] = $ages[$age + 1];
            
            $ages[6] += $ages[-1];
            $ages[8] = $ages[-1];
        }

        $result = 0;
        for ($age = 0; $age < 9; $age++) {
            $result += $ages[$age];
        }

        echo "Day:  6 | Part: 1 | Result: " . $result . "<br>";
    }

    function Day6_Part2() {
        $ages = array(-1 => 0, 0 => 0, 1 => 0, 2 => 0, 3 => 0, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0);

        foreach (explode(",", read_file_lines("../data/day6.txt")[0]) as $num) {
            $ages[$num]++;
        }


        for ($day = 0; $day < 256; $day++) {
            for ($age = -1; $age < 8; $age++)
                $ages[$age] = $ages[$age + 1];
            
            $ages[6] += $ages[-1];
            $ages[8] = $ages[-1];
        }

        $result = 0;
        for ($age = 0; $age < 9; $age++) {
            $result += $ages[$age];
        }

        echo "Day:  6 | Part: 2 | Result: " . $result . "<br>";
    }

    Day6_Part1();
    Day6_Part2();
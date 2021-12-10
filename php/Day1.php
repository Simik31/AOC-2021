<?php
    require_once('Utils.php');

    function Day1_Part1() {
        $last = -1;
        $count = 0;

        foreach (read_file_lines("../data/day1.txt", "r") as $line) {
            if ($last > 0 && (int) $line > $last)
                $count++;

            $last = (int) $line;
        }

        echo "Day:  1 | Part: 1 | Result: " . $count . "<br>";
    } 

    
    function Day1_Part2() {
        $file = fopen("../data/day1.txt", "r");
        $lines = read_file_lines("../data/day1.txt", "r");
        
        $last = -1;
        $count = 0;

        for ($index = 0; $index < count($lines) - 2; $index++) {
            $sum = $lines[$index] + $lines[$index + 1] + $lines[$index + 2];

            if ($last > 0 && $sum > $last)
                $count++;

            $last = $sum;
        }

        echo "Day:  1 | Part: 2 | Result: " . $count . "<br>";
    } 

    Day1_Part1();
    Day1_Part2();
    
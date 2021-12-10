<?php
    require_once('Utils.php');

    function Day5_Part1() {
        $x1 = array();
        $y1 = array();
        $x2 = array();
        $y2 = array();

        foreach (read_file_lines("../data/day5.txt") as $row) {
            array_push($x1, (int) explode(",", explode(" -> ", $row)[0])[0]);
            array_push($y1, (int) explode(",", explode(" -> ", $row)[0])[1]);
            array_push($x2, (int) explode(",", explode(" -> ", $row)[1])[0]);
            array_push($y2, (int) explode(",", explode(" -> ", $row)[1])[1]);
        }

        $max_x = max(max($x1), max($x2));
        $max_y = max(max($y1), max($y2));

        $vents = array();
        for ($y = 0; $y < $max_y + 1; $y++) {
            array_push($vents, array());
            for ($x = 0; $x < $max_x + 1; $x++)
            array_push($vents[$y], 0);
        }

        for ($index = 0; $index < count($x1); $index++) {
            $x_one = $x1[$index];
            $y_one = $y1[$index];
            $x_two = $x2[$index];
            $y_two = $y2[$index];

            if ($x_one > $x_two) {
                $tmp = $x_one;
                $x_one = $x_two;
                $x_two = $tmp;
            }
            if ($y_one > $y_two) {
                $tmp = $y_one;
                $y_one = $y_two;
                $y_two = $tmp;
            }

            if ($x_one == $x_two)
                for ($y = $y_one; $y < $y_two + 1; $y++)
                    $vents[$y][$x_one]++;

            else if ($y_one == $y_two)
                for ($x = $x_one; $x < $x_two + 1; $x++)
                    $vents[$y_one][$x]++;
        }
    
        $counter = 0;
    
        foreach ($vents as $row) {
            foreach ($row as $cell) {
                if ($cell >= 2) $counter++;
            }
        }

        echo "Day:  5 | Part: 1 | Result: " . $counter . "<br>";
    }

    function Day5_Part2() {
        $x1 = array();
        $y1 = array();
        $x2 = array();
        $y2 = array();

        foreach (read_file_lines("../data/day5.txt") as $row) {
            array_push($x1, (int) explode(",", explode(" -> ", $row)[0])[0]);
            array_push($y1, (int) explode(",", explode(" -> ", $row)[0])[1]);
            array_push($x2, (int) explode(",", explode(" -> ", $row)[1])[0]);
            array_push($y2, (int) explode(",", explode(" -> ", $row)[1])[1]);
        }

        $max_x = max(max($x1), max($x2));
        $max_y = max(max($y1), max($y2));

        $vents = array();
        for ($y = 0; $y < $max_y + 1; $y++) {
            array_push($vents, array());
            for ($x = 0; $x < $max_x + 1; $x++)
            array_push($vents[$y], 0);
        }

        for ($index = 0; $index < count($x1); $index++) {
            $x_one = $x1[$index];
            $y_one = $y1[$index];
            $x_two = $x2[$index];
            $y_two = $y2[$index];

            if ($x_one == $x_two) {                    
                if ($y_one > $y_two) {
                    $tmp = $y_one;
                    $y_one = $y_two;
                    $y_two = $tmp;
                }

                for ($y = $y_one; $y < $y_two + 1; $y++)
                    $vents[$y][$x_one]++;
            } else if ($y_one == $y_two) {
                if ($x_one > $x_two) {
                    $tmp = $x_one;
                    $x_one = $x_two;
                    $x_two = $tmp;
                }
                
                for ($x = $x_one; $x < $x_two + 1; $x++)
                    $vents[$y_one][$x]++;
            } else {
                if ($x_one > $x_two) {
                    $tmp = $x_one;
                    $x_one = $x_two;
                    $x_two = $tmp;
                    $tmp = $y_one;
                    $y_one = $y_two;
                    $y_two = $tmp;
                }

                
                for ($o = 0; $o < $x_two - $x_one + 1; $o++)
                    $vents[$y_one < $y_two ? $y_one + $o : $y_one - $o][$x_one + $o]++;
            }
        }
    
        $counter = 0;
    
        foreach ($vents as $row) {
            foreach ($row as $cell) {
                if ($cell >= 2) $counter++;
            }
        }

        echo "Day:  5 | Part: 2 | Result: " . $counter . "<br>";
    }

    Day5_Part1();
    Day5_Part2();
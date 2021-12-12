<?php
    require_once('Utils.php');

    function Day11_flash(&$grid, $x, $y, &$counter) {
        if ($grid[$y][$x][1])
            return;
    
        $grid[$y][$x][0] += 1;
    
        if ($grid[$y][$x][0] > 9) {
            $grid[$y][$x][0] = 0;
            $grid[$y][$x][1] = True;
            $counter += 1;
    
            for ($y_off = -1; $y_off < 2; $y_off++)
                for ($x_off = -1; $x_off < 2; $x_off++)
                    if ($y + $y_off >= 0 && $y + $y_off < count($grid) && $x + $x_off >= 0 && $x + $x_off < count($grid[$y + $y_off]))
                        Day11_flash($grid, $x + $x_off, $y + $y_off, $counter);
        }
    }

    function Day11_Part1() {
        $grid = array();

        foreach (read_file_lines("../data/day11.txt") as $line) {
            array_push($grid, array());
            foreach (str_split($line) as $num) {
                array_push($grid[count($grid) - 1], array((int) $num, false));
            }
        }
        
        $counter = 0;
        for ($step = 0; $step < 100; $step++) {
            for ($row = 0; $row < count($grid); $row++)
                for ($col = 0; $col < count($grid[$row]); $col++)
                    $grid[$row][$col][1] = false;

            for ($row = 0; $row < count($grid); $row++)
                for ($col = 0; $col < count($grid[$row]); $col++)
                    Day11_flash($grid, $col, $row, $counter);
        }

        echo "Day: 11 | Part: 1 | Result: " . $counter . "<br>";
    }

    function Day11_Part2() {
        $grid = array();

        foreach (read_file_lines("../data/day11.txt") as $line) {
            array_push($grid, array());
            foreach (str_split($line) as $num) {
                array_push($grid[count($grid) - 1], array((int) $num, false));
            }
        }
        
        $ignore = 0;
        $step = 0;
        $all_true = false;
        for (; !$all_true; $step++) {
            for ($row = 0; $row < count($grid); $row++)
                for ($col = 0; $col < count($grid[$row]); $col++)
                    $grid[$row][$col][1] = false;

            for ($row = 0; $row < count($grid); $row++)
                for ($col = 0; $col < count($grid[$row]); $col++)
                    Day11_flash($grid, $col, $row, $ignore);

            $all_true = true;            
            for ($row = 0; $all_true && $row < count($grid); $row++)
                for ($col = 0; $all_true && $col < count($grid[$row]); $col++)
                    if (!$grid[$row][$col][1])
                        $all_true = false;
        }

        echo "Day: 11 | Part: 1 | Result: " . $step . "<br>";
    }

    Day11_Part1();
    Day11_Part2();
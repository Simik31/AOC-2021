<?php
    require_once('Utils.php');

    function Day9_Part1() {
        $height_map = array();
        $lowest_truths = array();

        foreach (read_file_lines("../data/day9.txt") as $row) {
            if ($row != "")
            {
                array_push($height_map, array());
                array_push($lowest_truths, array());

                foreach (str_split($row) as $num) {
                    array_push($height_map[count($height_map) - 1], (int) $num);
                    array_push($lowest_truths[count($lowest_truths) - 1], false);
                }
            }
        }

        for ($r = 0; $r < count($height_map); $r++)
            for ($c = 0; $c < count($height_map[$r]); $c++) {
                $truths = array();

                if ($r >= 1)
                    array_push($truths, $height_map[$r][$c] < $height_map[$r - 1][$c]);
                if ($r + 1 < count($height_map))
                    array_push($truths, $height_map[$r][$c] < $height_map[$r + 1][$c]);
                if ($c >= 1)
                    array_push($truths, $height_map[$r][$c] < $height_map[$r][$c - 1]);
                if ($c + 1 < count($height_map[$r]))
                    array_push($truths, $height_map[$r][$c] < $height_map[$r][$c + 1]);

                $lowest_truths[$r][$c] = in_array(false, $truths) == false;
            }

        
        $result = 0;
        for ($r = 0; $r < count($height_map); $r++)
            for ($c = 0; $c < count($height_map[$r]); $c++)
                if ($lowest_truths[$r][$c])
                    $result += $height_map[$r][$c] + 1;
    
        echo "Day:  9 | Part: 1 | Result: " . $result . "<br>";
    }

    function backtrack_basin(&$height_map, $r, $c, $counter, &$visited) {
        if (in_array(array($r, $c), $visited))
            return $counter;
    
        array_push($visited, array($r, $c));
    
        if ($height_map[$r][$c] == 9)
            return $counter;
    
        $counter += 1;
    
        if ($r >= 1)
            $counter = backtrack_basin($height_map, $r - 1, $c, $counter, $visited);
        if ($r + 1 < count($height_map))
            $counter = backtrack_basin($height_map, $r + 1, $c, $counter, $visited);
        if ($c >= 1)
            $counter = backtrack_basin($height_map, $r, $c - 1, $counter, $visited);
        if ($c + 1 < count($height_map[$r]))
            $counter = backtrack_basin($height_map, $r, $c + 1, $counter, $visited);
    
        return $counter;
    }

    function Day9_Part2() {
        $height_map = array();
        $lowest_truths = array();

        foreach (read_file_lines("../data/day9.txt") as $row) {
            if ($row != "")
            {
                array_push($height_map, array());
                array_push($lowest_truths, array());

                foreach (str_split($row) as $num) {
                    array_push($height_map[count($height_map) - 1], (int) $num);
                    array_push($lowest_truths[count($lowest_truths) - 1], false);
                }
            }
        }

        for ($r = 0; $r < count($height_map); $r++)
            for ($c = 0; $c < count($height_map[$r]); $c++) {
                $truths = array();

                if ($r >= 1)
                    array_push($truths, $height_map[$r][$c] < $height_map[$r - 1][$c]);
                if ($r + 1 < count($height_map))
                    array_push($truths, $height_map[$r][$c] < $height_map[$r + 1][$c]);
                if ($c >= 1)
                    array_push($truths, $height_map[$r][$c] < $height_map[$r][$c - 1]);
                if ($c + 1 < count($height_map[$r]))
                    array_push($truths, $height_map[$r][$c] < $height_map[$r][$c + 1]);

                $lowest_truths[$r][$c] = in_array(false, $truths) == false;
            }

        $basins = array();
        $visited = array();

        for ($r = 0; $r < count($height_map); $r++)
            for ($c = 0; $c < count($height_map[$r]); $c++)
                if ($lowest_truths[$r][$c])
                    array_push($basins, backtrack_basin($height_map, $r, $c, 0, $visited));

        rsort($basins);
        $result = $basins[0] * $basins[1] * $basins[2];

        echo "Day:  9 | Part: 2 | Result: " . $result . "<br>";
    }

    Day9_Part1();
    Day9_Part2();
<?php
    require_once('Utils.php');

    function Day7_Part1() {
        $positions = array();

        foreach(explode(",", read_file_lines("../data/day7.txt")[0]) as $num) {
            array_push($positions, $num);
        }

        $min_cost = PHP_INT_MAX;

        for ($position_end_id = 0; $position_end_id < count($positions); $position_end_id++) {
            $position_cost = 0;
    
            for ($position_crab_id = 0; $position_crab_id < count($positions); $position_crab_id++)
                $position_cost += abs($positions[$position_end_id] - $positions[$position_crab_id]);
    
            $min_cost = min($min_cost, $position_cost);
        }
    
        echo "Day:  7 | Part: 1 | Result: " . $min_cost . "<br>";
    }

    function Day7_Part2() {
        $positions = array();
        $costs = array();

        foreach(explode(",", read_file_lines("../data/day7.txt")[0]) as $num) {
            array_push($positions, $num);
        }

        $min_cost = PHP_INT_MAX;
        
        for ($position_end = min($positions); $position_end < max($positions); $position_end++) {
            $position_cost = 0;
    
            for ($position_crab_id = 0; $position_crab_id < count($positions); $position_crab_id++)
                for ($step = 1; $step <= abs($position_end - $positions[$position_crab_id]); $step++)
                    $position_cost += $step;

        
            $min_cost = min($min_cost, $position_cost);
        }
    
        echo "Day:  7 | Part: 2 | Result: " . $min_cost . "<br>";
    }

    Day7_Part1();
    Day7_Part2();
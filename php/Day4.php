<?php
    require_once('Utils.php');

    function Day4_TestBoardForBingo($marked)
    {
        for ($row_id = 0; $row_id < count($marked); $row_id++)
        {
            $row_true = true;
            $col_true = true;

            for ($cell_id = 0; $cell_id < count($marked[$row_id]); $cell_id++)
            {
                if ($marked[$row_id][$cell_id] == false)
                    $row_true = false;
    
                if ($marked[$cell_id][$row_id] == false)
                    $col_true = false;
            }
            if ($row_true || $col_true)
                return true;
        }
    
        return false;
    }

    function Day4_Part1() {
        $rows = array();
        $mark = array();
        
        $lines = read_file_lines('../data/day4.txt');
        $order = array();
        
        foreach (explode(',', $lines[0]) as $number) {
            array_push($order, (int) $number);
        }

	    $board_id = -1;
        $line_id = 0;

        for ($i = 1; $i < count($lines); $i++)
        {
            if ($lines[$i] == '') {
                $board_id++;
                $line_id = 0;

                array_push($rows, array());
                array_push($mark, array());
            } else {
                array_push($rows[$board_id], array());
                array_push($mark[$board_id], array());
                
                foreach (preg_split('/[^\d]/', $lines[$i]) as $num) {
                    if ($num != '') {
                        array_push($rows[$board_id][$line_id], (int) $num);
                        array_push($mark[$board_id][$line_id], 0);
                    }
                }

                $line_id++;
            }
        }
        
	    $bingo = -1;
        $last_draw = -1;

        for ($draw_id = 0; $draw_id < count($order); $draw_id++) 
        {
            $draw = $order[$draw_id];

            for ($b = 0; $b < count($rows); $b++)
                for ($r = 0; $r < count($rows[$b]); $r++)
                    for ($n = 0; $n < count($rows[$b][$r]); $n++)
                        if ($rows[$b][$r][$n] == $draw)
                            $mark[$b][$r][$n] = true;

            $last_draw = $draw;
    
            for ($index = 0; $index < count($mark); $index++)
                if (Day4_TestBoardForBingo($mark[$index]))
                    $bingo = $index;
    
            if ($bingo != -1)
                break;
        }

        $board_sum = 0;
        for ($r = 0; $r < count($rows[$bingo]); $r++) {
            for ($n = 0; $n < count($rows[$bingo][$r]); $n++)
                if ($mark[$bingo][$r][$n] == false)
                    $board_sum += $rows[$bingo][$r][$n];
        }

        echo "Day:  4 | Part: 1 | Result: " . ($board_sum * $last_draw) . "<br>";
    }

    
    function Day4_Part2() {
        $bins = array();
        $rows = array();
        $mark = array();
        
        $lines = read_file_lines('../data/day4.txt');
        $order = array();
        
        foreach (explode(',', $lines[0]) as $number) {
            array_push($order, (int) $number);
        }

	    $board_id = -1;
        $line_id = 0;

        for ($i = 1; $i < count($lines); $i++)
        {
            if ($lines[$i] == '') {
                $board_id++;
                $line_id = 0;

                array_push($bins, 0);
                array_push($rows, array());
                array_push($mark, array());
            } else {
                array_push($rows[$board_id], array());
                array_push($mark[$board_id], array());
                
                foreach (preg_split('/[^\d]/', $lines[$i]) as $num) {
                    if ($num != '') {
                        array_push($rows[$board_id][$line_id], (int) $num);
                        array_push($mark[$board_id][$line_id], 0);
                    }
                }

                $line_id++;
            }
        }
        
	    $bingo = -1;
        $last_draw = -1;
        $bingo_counter = 0;

        for ($draw_id = 0; $draw_id < count($order); $draw_id++) 
        {
            $draw = $order[$draw_id];

            for ($b = 0; $b < count($rows); $b++)
                for ($r = 0; $r < count($rows[$b]); $r++)
                    for ($n = 0; $n < count($rows[$b][$r]); $n++)
                        if ($rows[$b][$r][$n] == $draw)
                            $mark[$b][$r][$n] = true;

            $last_draw = $draw;
    
            for ($index = 0; $index < count($mark); $index++)
                if ($bins[$index] == false && Day4_TestBoardForBingo($mark[$index])) {
                    $bins[$index] = 1;
                    $bingo_counter++;
                    $bingo = $index;
                }
    
            if ($bingo_counter == count($bins))
                break;
        }

        $board_sum = 0;
        for ($r = 0; $r < count($rows[$bingo]); $r++) {
            for ($n = 0; $n < count($rows[$bingo][$r]); $n++)
                if ($mark[$bingo][$r][$n] == false)
                    $board_sum += $rows[$bingo][$r][$n];
        }

        echo "Day:  4 | Part: 2 | Result: " . ($board_sum * $last_draw) . "<br>";
    }

    Day4_Part1();
    Day4_Part2();
<?php
    require_once('Utils.php');
    
    function Day10_Part1() {
        $opens = array("(", "[", "{", "<");
        $closes = array(")", "]", "}", ">");
        $incorrects = array(")" => 0, "]" => 0, "}" => 0, ">" => 0);

        foreach (read_file_lines("../data/day10.txt") as $line) {
            $pairs = array();
            foreach (str_split($line) as $char) {
                if (in_array($char, $opens))
                    array_push($pairs, $char);
                else if (array_search($pairs[count($pairs) - 1], $opens) == array_search($char, $closes))
                    array_pop($pairs);
                else {
                    $incorrects[$char]++;
                    break;
                }
            }
        }

        $result = $incorrects[")"] * 3 + $incorrects["]"] * 57 + $incorrects["}"] * 1197 + $incorrects[">"] * 25137;

        echo "Day: 10 | Part: 1 | Result: " . $result . "<br>";
    }

    function Day10_Part2() {
        $opens = array("(", "[", "{", "<");
        $closes = array(")", "]", "}", ">");
        $scores = array();

        foreach (read_file_lines("../data/day10.txt") as $line) {
            $pairs = array();
            $score = 0;
            $corrupted = false;

            foreach (str_split($line) as $char) {
                if (in_array($char, $opens))
                    array_push($pairs, $char);
                else if (array_search($pairs[count($pairs) - 1], $opens) == array_search($char, $closes))
                    array_pop($pairs);
                else {
                    $corrupted = true;
                    break;
                }
            }

            if ($corrupted == false)
            {
                while (count($pairs) > 0)
                    $score = $score * 5 + array_search(array_pop($pairs), $opens) + 1;
                array_push($scores, $score);
            }
        }

        sort($scores);
        $result = $scores[count($scores) / 2];

        echo "Day: 10 | Part: 1 | Result: " . $result . "<br>";
    }

    Day10_Part1();
    Day10_Part2();
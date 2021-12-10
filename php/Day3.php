<?php
    require_once('Utils.php');

    function Day3_Part1() {
        $data = read_file_lines("../data/day3.txt");

        $gama = 0;
        $epsilon = 0;

        for ($i = 0; $i < strlen($data[0]); $i++)
        {
            $counter = array(0, 0);

            foreach ($data as $row) $counter[$row[$i]]++;

            $gama = ($gama << 1) + ($counter[0] > $counter[1] ? 0 : 1);
            $epsilon = ($epsilon << 1) + ($counter[0] > $counter[1] ? 1 : 0);
        }

        echo "Day:  3 | Part: 1 | Result: " . ($gama * $epsilon) . "<br>";
    }

    function Day3_Part2() {
        $data_og = read_file_lines("../data/day3.txt");
        $data_co2s = (new ArrayObject($data_og))->getArrayCopy();

        for ($i = 0; $i < strlen($data_og[0]); $i++)
        {
            if (count($data_og) > 1) {
                $counter = array(0, 0);
                
                foreach ($data_og as $row) $counter[$row[$i]]++;

                $new_og = array();
                for ($d = count($data_og) - 1; $d >= 0; $d--)
                    if ($data_og[$d][$i] == ($counter[1] >= $counter[0] ? '1' : '0'))
                        array_push($new_og, $data_og[$d]);
                $data_og = $new_og;
            }

            if (count($data_co2s) > 1) {
                $counter = array(0, 0);
                
                foreach ($data_co2s as $row) $counter[$row[$i]]++;

                $new_co2s = array();
                for ($d = count($data_co2s) - 1; $d >= 0; $d--)
                    if ($data_co2s[$d][$i] == ($counter[1] >= $counter[0] ? '0' : '1'))
                    array_push($new_co2s, $data_co2s[$d]);
                $data_co2s = $new_co2s;
            }

            if (count($data_og) == 1 && count($data_co2s) == 1)
                break;
        }

        echo "Day:  3 | Part: 2 | Result: " . (bindec($data_og[0]) * bindec($data_co2s[0])) . "<br>";
    }

    Day3_Part1();
    Day3_Part2();
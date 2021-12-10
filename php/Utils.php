<?php
    function read_file_lines($filename) {
        $file = fopen($filename, 'r');

        if ($file === false) {
            throw new Exception("Could not open file '" . $filename . "'.");
        }

        $lines = array();

        while (($line = fgets($file)) !== false) {
            array_push($lines, trim($line));
        }

        return $lines;
    }
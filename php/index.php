<?php
    set_time_limit(3600);
    
    for ($day = 1; $day <= 9; $day++) {
        if ($day == 8)
            continue;
            
        require_once('Day' . $day . '.php');
    }
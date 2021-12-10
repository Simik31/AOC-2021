package cz.simik31.aoc2021;

import java.util.HashMap;
import java.util.Map;

public class Day6 {
    public static void part_1() {
        Map<Integer, Integer> ages = new HashMap<>();
        for (int age = -1; age < 9; age++)
            ages.put(age, 0);

        for (String num_s : Utils.readFileLines("../data/day6.txt").get(0).split(","))
            ages.put(Integer.parseInt(num_s), ages.get(Integer.parseInt(num_s)) + 1);

        for (int day = 0; day < 80; day++) {
            for (int age = -1; age < 8; age++)
                ages.put(age, ages.get(age + 1));
            ages.put(6, ages.get(6) + ages.get(-1));
            ages.put(8, ages.get(-1));
        }

        int result = 0;
        for (int day = 0; day < 9; day++)
            result += ages.get(day);

        System.out.println("Day:  6 | Part: 1 | Result: " + result);
    }

    public static void part_2() {
        Map<Integer, Long> ages = new HashMap<>();
        for (int age = -1; age < 9; age++)
            ages.put(age, 0L);

        for (String num_s : Utils.readFileLines("../data/day6.txt").get(0).split(","))
            ages.put(Integer.parseInt(num_s), ages.get(Integer.parseInt(num_s)) + 1);

        for (int day = 0; day < 256; day++) {
            for (int age = -1; age < 8; age++)
                ages.put(age, ages.get(age + 1));
            ages.put(6, ages.get(6) + ages.get(-1));
            ages.put(8, ages.get(-1));
        }

        long result = 0;
        for (int day = 0; day < 9; day++)
            result += ages.get(day);

        System.out.println("Day:  6 | Part: 2 | Result: " + result);
    }
}

package cz.simik31.aoc2021;

import java.util.List;

public class Day1 {
    public static void part_1() {
        int last = -1, count = 0;

        for (int num : Utils.readFileLines("../data/day1.txt").stream().map(Integer::parseInt).toList()) {
            if (last > 0 && num > last)
                count++;
            last = num;
        }

        System.out.println("Day:  1 | Part: 1 | Result: " + count);
    }

    public static void part_2() {
        List<Integer> nums = Utils.readFileLines("../data/day1.txt").stream().map(Integer::parseInt).toList();

        int last = -1, count = 0;

        for (int index = 0; index < nums.size() - 2; index++) {
            int sum = nums.get(index) + nums.get(index + 1) + nums.get(index + 2);

            if (last > 0 && sum > last)
                count++;

            last = sum;
        }

        System.out.println("Day:  1 | Part: 2 | Result: " + count);
    }
}

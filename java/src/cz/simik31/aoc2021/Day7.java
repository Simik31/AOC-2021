package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Day7 {
    public static void part_1() {
        List<Integer> positions = new ArrayList<>();

        for (String num_s : Utils.readFileLines("../data/day7.txt").get(0).split(","))
            positions.add(Integer.parseInt(num_s));

        int min_cost = Integer.MAX_VALUE;

        for (int end_position : new HashSet<>(positions)) {
            int position_cost = 0;
            for (int crab_position : positions)
                position_cost += Math.abs(crab_position - end_position);

            min_cost = Math.min(min_cost, position_cost);
        }

        System.out.println("Day:  7 | Part: 1 | Result: " + min_cost);
    }

    public static void part_2() {
        List<Integer> positions = new ArrayList<>();

        for (String num_s : Utils.readFileLines("../data/day7.txt").get(0).split(","))
            positions.add(Integer.parseInt(num_s));

        int min_cost = Integer.MAX_VALUE;

        for (int end_position = 1; end_position < positions.stream().max(Integer::compareTo)
                .orElseThrow(); end_position++) {
            int position_cost = 0;

            for (int crab_position : positions)
                for (int step = 1; step <= Math.abs(end_position - crab_position); step++)
                    position_cost += step;

            min_cost = Math.min(min_cost, position_cost);
        }

        System.out.println("Day:  7 | Part: 2 | Result: " + min_cost);
    }
}

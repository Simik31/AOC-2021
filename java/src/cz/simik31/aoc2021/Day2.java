package cz.simik31.aoc2021;

import java.util.List;

public class Day2 {
    public static void part_1() {
        List<String> input = Utils.readFileLines("../data/day2.txt");

        int h_pos = 0, v_pos = 0;

        for (String command : input) {
            String direction = command.split(" ")[0];
            int value = Integer.parseInt(command.split(" ")[1]);

            switch (direction) {
                case "forward" -> h_pos += value;
                case "down" -> v_pos += value;
                case "up" -> v_pos -= value;
                default -> throw new IllegalArgumentException("Unsupported command " + direction);
            }
        }

        System.out.println("Day:  2 | Part: 1 | Result: " + (h_pos * v_pos));
    }

    public static void part_2() {
        List<String> input = Utils.readFileLines("../data/day2.txt");

        int h_pos = 0, v_pos = 0,aim = 0;

        for (String command : input) {
            String direction = command.split(" ")[0];
            int value = Integer.parseInt(command.split(" ")[1]);

            switch (direction) {
                case "forward" -> {
                    h_pos += value;
                    v_pos += aim * value;
                }
                case "down" -> aim += value;
                case "up" -> aim -= value;
                default -> throw new IllegalArgumentException("Unsupported command " + direction);
            }
        }

        System.out.println("Day:  2 | Part: 2 | Result: " + (h_pos * v_pos));
    }
}

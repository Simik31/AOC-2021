package cz.simik31.aoc2021;


import java.util.ArrayList;
import java.util.List;

public class Day5 {
    public static void part_1() {
        List<Integer> x1 = new ArrayList<>();
        List<Integer> y1 = new ArrayList<>();
        List<Integer> x2 = new ArrayList<>();
        List<Integer> y2 = new ArrayList<>();

        for (String line : Utils.readFileLines("../data/day5.txt")) {
            x1.add(Integer.parseInt(line.split(" -> ")[0].split(",")[0]));
            y1.add(Integer.parseInt(line.split(" -> ")[0].split(",")[1]));
            x2.add(Integer.parseInt(line.split(" -> ")[1].split(",")[0]));
            y2.add(Integer.parseInt(line.split(" -> ")[1].split(",")[1]));
        }

        int max_x = Math.max(
                x1.stream().max(Integer::compareTo).orElseThrow(),
                x2.stream().max(Integer::compareTo).orElseThrow()
        );
        int max_y = Math.max(
                y1.stream().max(Integer::compareTo).orElseThrow(),
                y2.stream().max(Integer::compareTo).orElseThrow()
        );

        List<List<Integer>> vents = new ArrayList<>(max_y + 1);

        for (int y = 0; y <= max_y; y++) {
            vents.add(new ArrayList<>(max_x + 1));
            for (int x = 0; x <= max_x; x++)
                vents.get(y).add(0);
        }

        for (int index = 0; index < x1.size(); index++) {
            int x_one = x1.get(index);
            int y_one = y1.get(index);
            int x_two = x2.get(index);
            int y_two = y2.get(index);

            if (x_one > x_two) {
                int tmp = x_one;
                x_one = x_two;
                x_two = tmp;
            }
            if (y_one > y_two) {
                int tmp = y_one;
                y_one = y_two;
                y_two = tmp;
            }

            if (x_one == x_two)
                for (int y = y_one; y <= y_two; y++)
                    vents.get(y).set(x_one, vents.get(y).get(x_one) + 1);

            else if (y_one == y_two)
                for (int x = x_one; x <= x_two; x++)
                    vents.get(y_one).set(x, vents.get(y_one).get(x) + 1);
        }

        int counter = 0;
        for (List<Integer> row : vents)
            for (int cell : row)
                if (cell >= 2)
                    counter++;

        System.out.println("Day:  5 | Part: 1 | Result: " + counter);
    }

    public static void part_2() {
        List<Integer> x1 = new ArrayList<>();
        List<Integer> y1 = new ArrayList<>();
        List<Integer> x2 = new ArrayList<>();
        List<Integer> y2 = new ArrayList<>();

        for (String line : Utils.readFileLines("../data/day5.txt")) {
            x1.add(Integer.parseInt(line.split(" -> ")[0].split(",")[0]));
            y1.add(Integer.parseInt(line.split(" -> ")[0].split(",")[1]));
            x2.add(Integer.parseInt(line.split(" -> ")[1].split(",")[0]));
            y2.add(Integer.parseInt(line.split(" -> ")[1].split(",")[1]));
        }

        int max_x = Math.max(
                x1.stream().max(Integer::compareTo).orElseThrow(),
                x2.stream().max(Integer::compareTo).orElseThrow()
        );
        int max_y = Math.max(
                y1.stream().max(Integer::compareTo).orElseThrow(),
                y2.stream().max(Integer::compareTo).orElseThrow()
        );

        List<List<Integer>> vents = new ArrayList<>(max_y + 1);

        for (int y = 0; y <= max_y; y++) {
            vents.add(new ArrayList<>(max_x + 1));
            for (int x = 0; x <= max_x; x++)
                vents.get(y).add(0);
        }

        for (int index = 0; index < x1.size(); index++) {
            int x_one = x1.get(index);
            int y_one = y1.get(index);
            int x_two = x2.get(index);
            int y_two = y2.get(index);

            if (x_one == x_two) {
                if (y_one > y_two) {
                    int tmp = y_one;
                    y_one = y_two;
                    y_two = tmp;
                }

                for (int y = y_one; y <= y_two; y++)
                    vents.get(y).set(x_one, vents.get(y).get(x_one) + 1);
            }

            else if (y_one == y_two) {
                if (x_one > x_two) {
                    int tmp = x_one;
                    x_one = x_two;
                    x_two = tmp;
                }

                for (int x = x_one; x <= x_two; x++)
                    vents.get(y_one).set(x, vents.get(y_one).get(x) + 1);
            }

            else {
                if (x_one > x_two) {
                    int tmp = x_one;
                    x_one = x_two;
                    x_two = tmp;
                    tmp = y_one;
                    y_one = y_two;
                    y_two = tmp;
                }

                for (int o = 0; o <= x_two - x_one; o++) {
                    int y = y_one < y_two ? y_one + o : y_one - o;
                    vents.get(y).set(x_one + o, vents.get(y).get(x_one + o) + 1);
                }
            }
        }

        int counter = 0;
        for (List<Integer> row : vents)
            for (int cell : row)
                if (cell >= 2)
                    counter++;

        System.out.println("Day:  5 | Part: 1 | Result: " + counter);
    }
}
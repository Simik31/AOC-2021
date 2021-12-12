package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.List;

public class Day11 {
    private static int flash(List<List<Pair<Integer, Boolean>>> grid, int x, int y, int counter) {
        if (grid.get(y).get(x).second)
            return counter;

        grid.get(y).get(x).first++;

        if (grid.get(y).get(x).first > 9) {
            grid.get(y).get(x).first = 0;
            grid.get(y).get(x).second = true;
            counter++;

            for (int y_off = -1; y_off < 2; y_off++)
                for (int x_off = -1; x_off < 2; x_off++)
                    if (y + y_off >= 0 && y + y_off < grid.size() && x + x_off >= 0 && x + x_off < grid.get(y + y_off).size())
                        counter = flash(grid, x + x_off, y + y_off, counter);
        }

        return counter;
    }

    public static void part_1() {
        List<List<Pair<Integer, Boolean>>> grid = new ArrayList<>();

        Utils.readFileLines("../data/day11.txt").forEach(line -> {
            grid.add(new ArrayList<>());
            for (char num : line.toCharArray()) {
                grid.get(grid.size() - 1).add(new Pair<>(num - '0', false));
            }
        });

        int counter = 0;
        for (int step = 0; step < 100; step++) {
            for (List<Pair<Integer, Boolean>> row : grid)
                for (Pair<Integer, Boolean> col : row)
                    col.second = false;

            for (int row = 0; row < grid.size(); row++)
                for (int col = 0; col < grid.get(row).size(); col++)
                    counter = flash(grid, col, row, counter);
        }

        System.out.println("Day: 11 | Part: 1 | Result: " + counter);
    }

    public static void part_2() {
        List<List<Pair<Integer, Boolean>>> grid = new ArrayList<>();

        Utils.readFileLines("../data/day11.txt").forEach(line -> {
            grid.add(new ArrayList<>());
            for (char num : line.toCharArray()) {
                grid.get(grid.size() - 1).add(new Pair<>(num - '0', false));
            }
        });

        int step = 0;
        for (; !grid.stream().allMatch(row -> row.stream().allMatch(col -> col.second)); step++) {
            for (List<Pair<Integer, Boolean>> row : grid)
                for (Pair<Integer, Boolean> col : row)
                    col.second = false;

            for (int row = 0; row < grid.size(); row++)
                for (int col = 0; col < grid.get(row).size(); col++)
                    flash(grid, col, row, 0);
        }

        System.out.println("Day: 11 | Part: 1 | Result: " + step);
    }
}

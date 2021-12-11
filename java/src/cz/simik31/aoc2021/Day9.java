package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.List;

public class Day9 {
    public static void part_1() {
        List<List<Integer>> height_map = new ArrayList<>();
        List<List<Boolean>> lowest_truths = new ArrayList<>();

        for (String row : Utils.readFileLines("../data/day9.txt")) {
            if (!row.equals("")) {
                height_map.add(new ArrayList<>());
                lowest_truths.add(new ArrayList<>());

                for (char num : row.toCharArray()) {
                    height_map.get(height_map.size() - 1).add(num - '0');
                    lowest_truths.get(lowest_truths.size() - 1).add(false);
                }
            }
        }

        for (int r = 0; r < height_map.size(); r++)
            for (int c = 0; c < height_map.get(r).size(); c++) {
                List<Boolean> truths = new ArrayList<>();

                if (r >= 1)
                    truths.add(height_map.get(r).get(c) < height_map.get(r - 1).get(c));
                if (r + 1 < height_map.size())
                    truths.add(height_map.get(r).get(c) < height_map.get(r + 1).get(c));
                if (c >= 1)
                    truths.add(height_map.get(r).get(c) < height_map.get(r).get(c - 1));
                if (c + 1 < height_map.get(r).size())
                    truths.add(height_map.get(r).get(c) < height_map.get(r).get(c + 1));

                lowest_truths.get(r).set(c, !truths.contains(false));
            }

        int result = 0;
        for (int r = 0; r < height_map.size(); r++)
            for (int c = 0; c < height_map.get(r).size(); c++)
                if (lowest_truths.get(r).get(c))
                    result += height_map.get(r).get(c) + 1;

        System.out.println("Day:  9 | Part: 1 | Result: " + result);
    }

    private static int backtrackBasin(List<List<Integer>> height_map, int r, int c, int counter,
            List<Pair<Integer, Integer>> visited) {
        if (visited.contains(new Pair<>(r, c)))
            return counter;

        visited.add(new Pair<>(r, c));

        if (height_map.get(r).get(c) == 9)
            return counter;

        counter++;

        if (r >= 1)
            counter = backtrackBasin(height_map, r - 1, c, counter, visited);
        if (r + 1 < height_map.size())
            counter = backtrackBasin(height_map, r + 1, c, counter, visited);
        if (c >= 1)
            counter = backtrackBasin(height_map, r, c - 1, counter, visited);
        if (c + 1 < height_map.get(r).size())
            counter = backtrackBasin(height_map, r, c + 1, counter, visited);

        return counter;
    }

    public static void part_2() {
        List<List<Integer>> height_map = new ArrayList<>();
        List<List<Boolean>> lowest_truths = new ArrayList<>();

        for (String row : Utils.readFileLines("../data/day9.txt")) {
            if (!row.equals("")) {
                height_map.add(new ArrayList<>());
                lowest_truths.add(new ArrayList<>());

                for (char num : row.toCharArray()) {
                    height_map.get(height_map.size() - 1).add(num - '0');
                    lowest_truths.get(lowest_truths.size() - 1).add(false);
                }
            }
        }

        for (int r = 0; r < height_map.size(); r++)
            for (int c = 0; c < height_map.get(r).size(); c++) {
                List<Boolean> truths = new ArrayList<>();

                if (r >= 1)
                    truths.add(height_map.get(r).get(c) < height_map.get(r - 1).get(c));
                if (r + 1 < height_map.size())
                    truths.add(height_map.get(r).get(c) < height_map.get(r + 1).get(c));
                if (c >= 1)
                    truths.add(height_map.get(r).get(c) < height_map.get(r).get(c - 1));
                if (c + 1 < height_map.get(r).size())
                    truths.add(height_map.get(r).get(c) < height_map.get(r).get(c + 1));

                lowest_truths.get(r).set(c, !truths.contains(false));
            }

        List<Integer> basins = new ArrayList<>();

        for (int r = 0; r < height_map.size(); r++)
            for (int c = 0; c < height_map.get(r).size(); c++)
                if (lowest_truths.get(r).get(c))
                    basins.add(backtrackBasin(height_map, r, c, 0, new ArrayList<>()));

        basins.sort(Integer::compareTo);
        int result = basins.get(basins.size() - 1) * basins.get(basins.size() - 2) * basins.get(basins.size() - 3);

        System.out.println("Day:  9 | Part: 1 | Result: " + result);
    }
}

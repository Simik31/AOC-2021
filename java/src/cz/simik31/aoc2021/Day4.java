package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Day4 {
    private static boolean testBoardForBingo(List<List<Boolean>> marked) {
        if (marked.stream().anyMatch(row -> row.stream().allMatch(mark -> mark)))
            return true;

        for (int i = 0; i < marked.get(0).size(); i++) {
            int finalI = i;
            if (marked.stream().allMatch(row -> row.get(finalI)))
                return true;
        }

        return false;
    }

    public static void part_1() {
        List<String> lines = Utils.readFileLines("../data/day4.txt");
        List<List<List<Integer>>> rows = new ArrayList<>();
        List<List<List<Boolean>>> mark = new ArrayList<>();
        List<Integer> order = Arrays.stream(lines.get(0).split(",")).map(Integer::parseInt).toList();

        int board_id = -1, line_id = 0;

        for (int i = 1; i < lines.size(); i++) {
            if (lines.get(i).equals("")) {
                board_id++;
                line_id = 0;

                rows.add(new ArrayList<>());
                mark.add(new ArrayList<>());
            } else {
                rows.get(board_id).add(new ArrayList<>());
                mark.get(board_id).add(new ArrayList<>());

                for (String num_s : lines.get(i).split("([^\\d])"))
                    if (!num_s.strip().equals("")) {
                        rows.get(board_id).get(line_id).add(Integer.parseInt(num_s.strip()));
                        mark.get(board_id).get(line_id).add(false);
                    }

                line_id++;
            }
        }

        int bingo = -1, last_draw = -1;

        for (int draw : order) {
            for (int b = 0; b < rows.size(); b++)
                for (int r = 0; r < rows.get(b).size(); r++)
                    for (int n = 0; n < rows.get(b).get(r).size(); n++)
                        if (rows.get(b).get(r).get(n) == draw)
                            mark.get(b).get(r).set(n, true);

            last_draw = draw;

            for (int index = 0; index < mark.size(); index++)
                if (testBoardForBingo(mark.get(index)))
                    bingo = index;

            if (bingo != -1)
                break;
        }

        int boardSum = 0;

        for (int r = 0; r < rows.get(bingo).size(); r++) {
            for (int n = 0; n < rows.get(bingo).get(r).size(); n++)
                if (!mark.get(bingo).get(r).get(n))
                    boardSum += rows.get(bingo).get(r).get(n);
        }

        System.out.println("Day:  4 | Part: 1 | Result: " + boardSum * last_draw);
    }

    public static void part_2() {
        List<String> lines = Utils.readFileLines("../data/day4.txt");
        List<Boolean> bins = new ArrayList<>();
        List<List<List<Integer>>> rows = new ArrayList<>();
        List<List<List<Boolean>>> mark = new ArrayList<>();
        List<Integer> order = Arrays.stream(lines.get(0).split(",")).map(Integer::parseInt).toList();

        int board_id = -1, line_id = 0;

        for (int i = 1; i < lines.size(); i++) {
            if (lines.get(i).equals("")) {
                board_id++;
                line_id = 0;

                bins.add(false);
                rows.add(new ArrayList<>());
                mark.add(new ArrayList<>());
            } else {
                rows.get(board_id).add(new ArrayList<>());
                mark.get(board_id).add(new ArrayList<>());

                for (String num_s : lines.get(i).split("([^\\d])"))
                    if (!num_s.strip().equals("")) {
                        rows.get(board_id).get(line_id).add(Integer.parseInt(num_s.strip()));
                        mark.get(board_id).get(line_id).add(false);
                    }

                line_id++;
            }
        }

        int bingo = -1, last_draw = -1, bingo_count = 0;

        for (int draw : order) {
            for (int b = 0; b < rows.size(); b++)
                for (int r = 0; r < rows.get(b).size(); r++)
                    for (int n = 0; n < rows.get(b).get(r).size(); n++)
                        if (rows.get(b).get(r).get(n) == draw)
                            mark.get(b).get(r).set(n, true);

            last_draw = draw;

            for (int index = 0; index < mark.size(); index++)
                if (!bins.get(index) && testBoardForBingo(mark.get(index))) {
                    bins.set(index, true);
                    bingo_count++;
                    bingo = index;
                }

            if (bingo_count == bins.size())
                break;
        }

        int boardSum = 0;

        for (int r = 0; r < rows.get(bingo).size(); r++) {
            for (int n = 0; n < rows.get(bingo).get(r).size(); n++)
                if (!mark.get(bingo).get(r).get(n))
                    boardSum += rows.get(bingo).get(r).get(n);
        }

        System.out.println("Day:  4 | Part: 2 | Result: " + boardSum * last_draw);
    }
}

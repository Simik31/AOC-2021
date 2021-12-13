package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Day13 {
    public static void part_1() {
        List<List<Boolean>> paper = new ArrayList<>();
        List<String> lines = Utils.readFileLines("../data/day13.txt");
        int folding_section_start = 0;

        for (String s : lines) {
            folding_section_start++;
            if (s.equals("")) break;

            List<Integer> ln = Arrays.stream(s.split(",")).map(Integer::parseInt).toList();
            int x = ln.get(0), y = ln.get(1);

            while (paper.size() <= y) paper.add(new ArrayList<>());
            while (paper.get(y).size() <= x) paper.get(y).add(false);

            paper.get(y).set(x, true);
        }

        int longest = 0;
        for (List<Boolean> line : paper) longest = Math.max(longest, line.size());

        for (List<Boolean> line : paper) while (line.size() < longest) line.add(false);

        String fold_line = lines.get(folding_section_start);
        int fold_index = Integer.parseInt(fold_line.substring(fold_line.lastIndexOf(" ")).split("=")[1]);

        for (List<Boolean> line : paper) {
            for (int index = 0; index < longest - fold_index - 1; index++)
                line.set(index, line.get(index) | line.get(longest - index - 1));

            for (int remove = 0; remove <= fold_index; remove++)
                line.remove(fold_index);
        }

        int result = 0;
        for (List<Boolean> line : paper)
            for (boolean c : line)
                if (c) result++;

        System.out.println("Day: 13 | Part: 1 | Result: " + result);
    }

    public static void part_2() {
        List<List<Boolean>> paper = new ArrayList<>();
        List<String> lines = Utils.readFileLines("../data/day13.txt");
        int folding_section_start = 0;

        for (String s : lines) {
            folding_section_start++;
            if (s.equals("")) break;

            List<Integer> ln = Arrays.stream(s.split(",")).map(Integer::parseInt).toList();
            int x = ln.get(0), y = ln.get(1);

            while (paper.size() <= y) paper.add(new ArrayList<>());
            while (paper.get(y).size() <= x) paper.get(y).add(false);

            paper.get(y).set(x, true);
        }

        int longest = 0;
        for (List<Boolean> line : paper) longest = Math.max(longest, line.size());

        for (List<Boolean> line : paper) while (line.size() < longest) line.add(false);

        for (int fold_line_id = folding_section_start; fold_line_id < lines.size(); fold_line_id++) {
            longest = 0;
            for (List<Boolean> line : paper) longest = Math.max(longest, line.size());

            String fold_line = lines.get(fold_line_id);
            String[] interest = fold_line.substring(fold_line.lastIndexOf(" ") + 1).split("=");
            String fold_axis = interest[0];
            int fold_index = Integer.parseInt(interest[1]);

            if (fold_axis.equals("x")) {
                for (List<Boolean> line : paper) {
                    for (int index = 0; index < longest - fold_index - 1; index++)
                        line.set(index, line.get(index) | line.get(longest - index - 1));

                    for (int remove = 0; remove <= fold_index; remove++)
                        line.remove(fold_index);
                }
            }
            else if (fold_axis.equals("y")) {
                for (int line = 0; line < paper.size() - fold_index - 1; line++)
                    for (int index = 0; index < paper.get(line).size(); index++)
                        paper.get(line).set(index, paper.get(line).get(index) | paper.get(paper.size() - line - 1).get(index));

                for (int remove = 0; remove <= fold_index; remove++)
                    paper.remove(fold_index);
            }
        }

        System.out.println("Day: 13 | Part: 1 | Result:");

        for (List<Boolean> line : paper) {
            for (boolean c : line)
                System.out.print(c ? "#" : " ");
            System.out.println();
        }

    }
}

package cz.simik31.aoc2021;

import java.util.*;

public class Day10 {
    public static void part_1() {
        List<Character> opens = Arrays.asList('(', '[', '{', '<');
        List<Character> closes = Arrays.asList(')', ']', '}', '>');
        Map<Character, Integer> incorrects = new HashMap<>(Map.of(')', 0, ']', 0, '}', 0, '>', 0));

        for (String line : Utils.readFileLines("../data/day10.txt")) {
            List<Character> pairs = new ArrayList<>();

            for (char c : line.strip().toCharArray()) {
                if (opens.contains(c))
                    pairs.add(c);
                else if (opens.indexOf(pairs.get(pairs.size() - 1)) == closes.indexOf(c))
                    pairs.remove(pairs.size() - 1);
                else {
                    incorrects.put(c, incorrects.get(c) + 1);
                    break;
                }
            }
        }

        int result = incorrects.get(')') * 3 + incorrects.get(']') * 57 + incorrects.get('}') * 1197 + incorrects.get('>') * 25137;

        System.out.println("Day: 10 | Part: 1 | Result: " + result);
    }

    public static void part_2() {
        List<Character> opens = Arrays.asList('(', '[', '{', '<');
        List<Character> closes = Arrays.asList(')', ']', '}', '>');
        List<Long> scores = new ArrayList<>();

        for (String line : Utils.readFileLines("../data/day10.txt")) {
            List<Character> pairs = new ArrayList<>();
            long score = 0;
            boolean corrupted = false;

            for (char c : line.strip().toCharArray()) {
                if (opens.contains(c))
                    pairs.add(c);
                else if (opens.indexOf(pairs.get(pairs.size() - 1)) == closes.indexOf(c))
                    pairs.remove(pairs.size() - 1);
                else {
                    corrupted = true;
                    break;
                }
            }

            if (!corrupted) {
                while (pairs.size() > 0)
                {
                    score = score * 5 + opens.indexOf(pairs.get(pairs.size() - 1)) + 1;
                    pairs.remove(pairs.size() - 1);
                }
                scores.add(score);
            }
        }

        scores.sort(Long::compareTo);
        long result = scores.get(scores.size() / 2);

        System.out.println("Day: 10 | Part: 2 | Result: " + result);
    }
}

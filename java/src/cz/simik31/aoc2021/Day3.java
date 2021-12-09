package cz.simik31.aoc2021;

import java.util.ArrayList;
import java.util.List;

public class Day3 {
    public static void part_1() {
        List<String> data = Utils.readFileLines("../data/day3.txt");

        int gama = 0;
        int epsilon = 0;

        for (int i = 0; i < data.get(0).length(); i++) {
            int[] counter = new int[] { 0, 0 };

            for (String row : data)
                counter[row.charAt(i) - '0']++;

            gama = (gama << 1) + (counter[0] > counter[1] ? 0 : 1);
            epsilon = (epsilon << 1) + (counter[0] > counter[1] ? 1 : 0);
        }

        System.out.println("Day:  3 | Part: 1 | Result: " + (gama * epsilon));
    }

    public static void part_2() {
        List<String> data_og = Utils.readFileLines("../data/day3.txt");
        List<String> data_co2s = new ArrayList<>(data_og);

        for (int i = 0; i < data_og.get(0).length(); i++) {
            if (data_og.size() > 1) {
                int[] counter = new int[]{0, 0};

                for (String row : data_og)
                    counter[Integer.parseInt(row.substring(i, i + 1))]++;

                int finalI = i;
                data_og.removeIf(r -> r.substring(finalI, finalI + 1).equals(counter[1] >= counter[0] ? "1" : "0"));
            }

            if (data_co2s.size() > 1) {
                int[] counter = new int[] { 0, 0 };

                for (String row : data_co2s)
                    counter[Integer.parseInt(row.substring(i, i + 1))]++;

                int finalI = i;
                data_co2s.removeIf(r -> r.substring(finalI, finalI + 1).equals(counter[1] >= counter[0] ? "0" : "1"));
            }

            if (data_og.size() == 1 && data_co2s.size() == 1)
                break;
        }

        System.out.println("Day:  3 | Part: 2 | Result: "
                + (Integer.parseInt(data_og.get(0), 2) * Integer.parseInt(data_co2s.get(0), 2)));
    }
}

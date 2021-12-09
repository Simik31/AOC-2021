package cz.simik31.aoc2021;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Utils {
    public static List<String> readFileLines(String filename) {
        Scanner file;

        try {
            file = new Scanner(new File(filename));
        } catch (Exception e) {
            throw new RuntimeException("Error while opening file '" + filename + "':", e);
        }

        List<String> lines = new ArrayList<>();

        while (file.hasNext())
            lines.add(file.nextLine());

        return lines;
    }
}

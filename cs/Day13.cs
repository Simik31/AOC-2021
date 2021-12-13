using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day13
    {
        public static void Part1()
        {
            List<List<bool>> paper = new List<List<bool>>();
            List<string> lines = File.ReadLines(@"../../../../../data/day13.txt").ToList().Select(line => line.Trim()).ToList();
            int folding_section_start = 0;

            for (int line_id = 0; line_id < lines.Count; line_id++)
            {
                folding_section_start++;
                string line = lines[line_id];
                if (line == "") break;

                List<int> ln = line.Split(",").Select(q => int.Parse(q)).ToList();
                int x = ln[0], y = ln[1];

                while (paper.Count <= y) paper.Add(new List<bool>());
                while (paper[y].Count <= x) paper[y].Add(false);

                paper[y][x] = true;
            }

            int longest = 0;
            foreach (List<bool> line in paper) longest = Math.Max(longest, line.Count);

            foreach (List<bool> line in paper) while (line.Count < longest) line.Add(false);

            string fold_line = lines[folding_section_start];
            string insterest = fold_line[(fold_line.LastIndexOf(" ") + 1)..];
            string fold_axis = insterest.Split("=")[0];
            int fold_index = int.Parse(insterest.Split("=")[1]);

            if (fold_axis == "x")
                for (int line = 0; line < paper.Count; line++)
                {
                    for (int index = 0; index < longest - fold_index - 1; index++)
                        paper[line][index] |= paper[line][longest - index - 1];
                    paper[line].RemoveRange(fold_index, fold_index + 1);
                }

            else if (fold_axis == "y")
            {
                for (int line = 0; line < paper.Count - fold_index - 1; line++)
                    for (int index = 0; index < longest; index++)
                        paper[line][index] |= paper[paper.Count - line - 1][index];
                paper.RemoveRange(fold_index, fold_index + 1);
            }

            int result = 0;
            foreach (List<bool> line in paper)
                foreach (bool c in line)
                    if (c) result++;

            Console.WriteLine("Day: 13 | Part: 1 | Result: " + result);
        }

        public static void Part2()
        {
            List<List<bool>> paper = new List<List<bool>>();
            List<string> lines = File.ReadLines(@"../../../../../data/day13.txt").ToList().Select(line => line.Trim()).ToList();
            int folding_section_start = 0;

            for (int line_id = 0; line_id < lines.Count; line_id++)
            {
                folding_section_start++;
                string line = lines[line_id];
                if (line == "") break;

                List<int> ln = line.Split(",").Select(q => int.Parse(q)).ToList();
                int x = ln[0], y = ln[1];

                while (paper.Count <= y) paper.Add(new List<bool>());
                while (paper[y].Count <= x) paper[y].Add(false);

                paper[y][x] = true;
            }

            int longest = 0;
            foreach (List<bool> line in paper) longest = Math.Max(longest, line.Count);

            foreach (List<bool> line in paper) while (line.Count < longest) line.Add(false);

            foreach (string fold_line in lines.Where(line => lines.IndexOf(line) >= folding_section_start))
            {
                longest = 0;
                foreach (List<bool> line in paper) longest = Math.Max(longest, line.Count);

                string insterest = fold_line[(fold_line.LastIndexOf(" ") + 1)..];
                string fold_axis = insterest.Split("=")[0];
                int fold_index = int.Parse(insterest.Split("=")[1]);

                if (fold_axis == "x")
                    for (int line = 0; line < paper.Count; line++)
                    {
                        for (int index = 0; index < longest - fold_index - 1; index++)
                            paper[line][index] |= paper[line][longest - index - 1];
                        paper[line].RemoveRange(fold_index, fold_index + 1);
                    }

                else if (fold_axis == "y")
                {
                    for (int line = 0; line < paper.Count - fold_index - 1; line++)
                        for (int index = 0; index < longest; index++)
                            paper[line][index] |= paper[paper.Count - line - 1][index];
                    paper.RemoveRange(fold_index, fold_index + 1);
                }
            }

            Console.WriteLine("Day: 13 | Part: 2 | Result:");
            foreach (List<bool> line in paper)
            {
                foreach (bool c in line)
                    Console.Write(c ? "#" : " ");
                Console.WriteLine();
            }
        }
    }
}
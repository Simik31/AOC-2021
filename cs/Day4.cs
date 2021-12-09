using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace cs
{
    class Day4
    {
        private static bool TestBoardForBingo(List<List<bool>> marked)
        {
            if (marked.Any(row => row.All(mark => mark))) return true;

            for (int i = 0; i < marked[0].Count; i++)
                if (marked.All(row => row[i])) return true;

            return false;
        }

        public static void Part1()
        {
            List<string> lines = File.ReadAllLines(@"../../../../../data/day4.txt").Select(l => l.Trim()).ToList();
            List<List<List<int>>> rows = new List<List<List<int>>>();
            List<List<List<bool>>> mark = new List<List<List<bool>>>();
            List<int> order = lines[0].Split(',').Select(n => int.Parse(n)).ToList();

            for (int i = 1; i < lines.Count; i++)
            {
                if (lines[i] == "")
                {
                    rows.Add(new List<List<int>>());
                    mark.Add(new List<List<bool>>());
                }
                else
                {
                    rows.Last().Add(new List<int>());
                    mark.Last().Add(new List<bool>());

                    foreach (string num_s in Regex.Split(lines[i], "([^\\d])"))
                    {
                        if (num_s.Trim() != "")
                        {
                            rows.Last().Last().Add(int.Parse(num_s));
                            mark.Last().Last().Add(false);
                        }
                    }
                }

            }

            int bingo = -1, last_draw = -1;

            foreach (int draw in order)
            {
                for (int b = 0; b < rows.Count; b++)
                    for (int r = 0; r < rows[b].Count; r++)
                        for (int n = 0; n < rows[b][r].Count; n++)
                            if (rows[b][r][n] == draw)
                                mark[b][r][n] = true;

                last_draw = draw;

                for (int index = 0; index < mark.Count; index++)
                    if (TestBoardForBingo(mark[index]))
                        bingo = index;

                if (bingo != -1)
                    break;
            }

            int boardSum = 0;

            for (int r = 0; r < rows[bingo].Count; r++)
                for (int n = 0; n < rows[bingo][r].Count; n++)
                    if (mark[bingo][r][n] == false)
                        boardSum += rows[bingo][r][n];

            Console.WriteLine("Day:  4 | Part: 1 | Result: " + boardSum * last_draw);
        }


        public static void Part2()
        {
            List<string> lines = File.ReadAllLines(@"../../../../../data/day4.txt").Select(l => l.Trim()).ToList();
            List<bool> bins = new List<bool>();
            List<List<List<int>>> rows = new List<List<List<int>>>();
            List<List<List<bool>>> mark = new List<List<List<bool>>>();
            List<int> order = lines[0].Split(',').Select(n => int.Parse(n)).ToList();
            
            for (int i = 1; i < lines.Count; i++)
            {
                if (lines[i] == "")
                {
                    bins.Add(false);
                    rows.Add(new List<List<int>>());
                    mark.Add(new List<List<bool>>());
                }
                else
                {
                    rows.Last().Add(new List<int>());
                    mark.Last().Add(new List<bool>());

                    foreach (string num_s in Regex.Split(lines[i], "([^\\d])"))
                        if (num_s.Trim() != "")
                        {
                            rows.Last().Last().Add(int.Parse(num_s));
                            mark.Last().Last().Add(false);
                        }
                }

            }

            int bingo = -1, last_draw = -1, bingo_count = 0;

            foreach (int draw in order)
            {
                for (int b = 0; b < rows.Count; b++)
                    for (int r = 0; r < rows[b].Count; r++)
                        for (int n = 0; n < rows[b][r].Count; n++)
                            if (rows[b][r][n] == draw)
                                mark[b][r][n] = true;

                last_draw = draw;

                for (int index = 0; index < mark.Count; index++)
                    if (!bins[index] && TestBoardForBingo(mark[index]))
                    {
                        bins[index] = true;
                        bingo_count++;
                        bingo = index;
                    }

                if (bingo_count == bins.Count)
                    break;
            }

            int boardSum = 0;

            for (int r = 0; r < rows[bingo].Count; r++)
                for (int n = 0; n < rows[bingo][r].Count; n++)
                    if (mark[bingo][r][n] == false)
                        boardSum += rows[bingo][r][n];

            Console.WriteLine("Day:  4 | Part: 2 | Result: " + boardSum * last_draw);
        }
    }
}

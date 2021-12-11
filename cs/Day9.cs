using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day9
    {
        public static void Part1()
        {
            List<List<int>> height_map = new List<List<int>>();
            List<List<bool>> lowest_truths = new List<List<bool>>();

            File.ReadLines(@"../../../../../data/day9.txt").ToList().ForEach(row =>
            {
                if (row.Trim() != "")
                {
                    height_map.Add(new List<int>());
                    lowest_truths.Add(new List<bool>());

                    foreach (char num in row)
                    {
                        height_map.Last().Add(num - '0');
                        lowest_truths.Last().Add(false);
                    }
                }
            });

            for (int r = 0; r < height_map.Count; r++)
                for (int c = 0; c < height_map[r].Count; c++)
                {
                    List<bool> truths = new List<bool>();

                    if (r >= 1)
                        truths.Add(height_map[r][c] < height_map[r - 1][c]);
                    if (r + 1 < height_map.Count)
                        truths.Add(height_map[r][c] < height_map[r + 1][c]);
                    if (c >= 1)
                        truths.Add(height_map[r][c] < height_map[r][c - 1]);
                    if (c + 1 < height_map[r].Count)
                        truths.Add(height_map[r][c] < height_map[r][c + 1]);

                    lowest_truths[r][c] = truths.Contains(false) == false;
                }

            int result = 0;

            for (int r = 0; r < height_map.Count; r++)
                for (int c = 0; c < height_map[r].Count; c++)
                    if (lowest_truths[r][c])
                        result += height_map[r][c] + 1;

            Console.WriteLine("Day:  9 | Part: 1 | Result: " + result);
        }

        private static int BacktrackBasin(ref List<List<int>> height_map, int r, int c, int counter, ref List<Tuple<int, int>> visited)
        {
            if (visited.Contains(new Tuple<int, int>(r, c)))
                return counter;

            visited.Add(new Tuple<int, int>(r, c));

            if (height_map[r][c] == 9)
                return counter;

            counter++;

            if (r >= 1)
                counter = BacktrackBasin(ref height_map, r - 1, c, counter, ref visited);
            if (r + 1 < height_map.Count)
                counter = BacktrackBasin(ref height_map, r + 1, c, counter, ref visited);
            if (c >= 1)
                counter = BacktrackBasin(ref height_map, r, c - 1, counter, ref visited);
            if (c + 1 < height_map[r].Count)
                counter = BacktrackBasin(ref height_map, r, c + 1, counter, ref visited);

            return counter;
        }

        public static void Part2()
        {
            List<List<int>> height_map = new List<List<int>>();
            List<List<bool>> lowest_truths = new List<List<bool>>();

            File.ReadLines(@"../../../../../data/day9.txt").ToList().ForEach(row =>
            {
                if (row.Trim() != "")
                {
                    height_map.Add(new List<int>());
                    lowest_truths.Add(new List<bool>());

                    foreach (char num in row)
                    {
                        height_map.Last().Add(num - '0');
                        lowest_truths.Last().Add(false);
                    }
                }
            });

            for (int r = 0; r < height_map.Count; r++)
                for (int c = 0; c < height_map[r].Count; c++)
                {
                    List<bool> truths = new List<bool>();

                    if (r >= 1)
                        truths.Add(height_map[r][c] < height_map[r - 1][c]);
                    if (r + 1 < height_map.Count)
                        truths.Add(height_map[r][c] < height_map[r + 1][c]);
                    if (c >= 1)
                        truths.Add(height_map[r][c] < height_map[r][c - 1]);
                    if (c + 1 < height_map[r].Count)
                        truths.Add(height_map[r][c] < height_map[r][c + 1]);

                    lowest_truths[r][c] = truths.Contains(false) == false;
                }

            List<int> basins = new List<int>();
            List<Tuple<int, int>> visited = new List<Tuple<int, int>>();  

            for (int r = 0; r < height_map.Count; r++)
                for (int c = 0; c < height_map[r].Count; c++)
                    if (lowest_truths[r][c])
                        basins.Add(BacktrackBasin(ref height_map, r, c, 0, ref visited));

            basins.Sort();
            int result = basins[^1] * basins[^2] * basins[^3];

            Console.WriteLine("Day:  9 | Part: 1 | Result: " + result);
        }
    }
}

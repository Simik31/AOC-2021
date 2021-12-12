using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace cs
{
    class Day11
    {
        private static void flash(List<List<Tuple<int, bool>>> grid, int x, int y, ref int counter)
        {
            if (grid[y][x].Item2)
                return;

            grid[y][x] = new Tuple<int, bool>(grid[y][x].Item1 + 1, false);

            if (grid[y][x].Item1 > 9)
            {
                grid[y][x] = new Tuple<int, bool>(0, true);
                counter++;

                foreach (int y_off in new int[] { -1, 0, 1 })
                    foreach (int x_off in new int[] { -1, 0, 1 })
                        if (y + y_off >= 0 && y + y_off < grid.Count && x + x_off >= 0 && x + x_off < grid[y + y_off].Count)
                            flash(grid, x + x_off, y + y_off, ref counter);
            }
        }

        public static void Part1()
        {
            List<List<Tuple<int, bool>>> grid = new List<List<Tuple<int, bool>>>();

            File.ReadLines(@"../../../../../data/day11.txt").ToList().ForEach(line =>
            {
                grid.Add(new List<Tuple<int, bool>>());
                line.ToCharArray().ToList().ForEach(num =>
                {
                    grid.Last().Add(new Tuple<int, bool>(num - '0', false));
                });
            });

            int counter = 0;
            for (int step = 0; step < 100; step++)
            {
                for (int row = 0; row < grid.Count; row++)
                    for (int col = 0; col < grid[row].Count; col++)
                        grid[row][col] = new Tuple<int, bool>(grid[row][col].Item1, false);

                for (int row = 0; row < grid.Count; row++)
                    for (int col = 0; col < grid[row].Count; col++)
                        flash(grid, col, row, ref counter);
            }

            Console.WriteLine("Day: 11 | Part: 1 | Result: " + counter);
        }

        public static void Part2()
        {
            List<List<Tuple<int, bool>>> grid = new List<List<Tuple<int, bool>>>();

            File.ReadLines(@"../../../../../data/day11.txt").ToList().ForEach(line =>
            {
                grid.Add(new List<Tuple<int, bool>>());
                line.ToCharArray().ToList().ForEach(num =>
                {
                    grid.Last().Add(new Tuple<int, bool>(num - '0', false));
                });
            });

            int ignore = 0;
            int step = 0;
            for (; grid.All(row => row.All(col => col.Item2)) == false; step++)
            {
                for (int row = 0; row < grid.Count; row++)
                    for (int col = 0; col < grid[row].Count; col++)
                        grid[row][col] = new Tuple<int, bool>(grid[row][col].Item1, false);

                for (int row = 0; row < grid.Count; row++)
                    for (int col = 0; col < grid[row].Count; col++)
                        flash(grid, col, row, ref ignore);
            }

            Console.WriteLine("Day: 11 | Part: 2 | Result: " + step);
        }
    }
}

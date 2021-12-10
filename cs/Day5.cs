using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day5
    {
        private static readonly string[] arrow = new string[] { " -> " };

        public static void Part1()
        {
            List<int> x1 = new List<int>();
            List<int> y1 = new List<int>();
            List<int> x2 = new List<int>();
            List<int> y2 = new List<int>();

            foreach (string row in File.ReadAllLines(@"../../../../../data/day5.txt"))
            {
                x1.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[0].Split(',')[0]));
                y1.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[0].Split(',')[1]));
                x2.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[1].Split(',')[0]));
                y2.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[1].Split(',')[1]));
            }

            int max_x = Math.Max(x1.Max(), x2.Max());
            int max_y = Math.Max(y1.Max(), y2.Max());

            List<List<int>> vents = new List<List<int>>(max_y + 1);

            for (int y = 0; y <= max_y; y++)
            {
                vents.Add(new List<int>(max_x + 1));
                for (int x = 0; x <= max_x; x++)
                    vents[y].Add(0);
            }

            for (int index = 0; index < x1.Count; index++)
            {
                int x_one = x1[index];
                int y_one = y1[index];
                int x_two = x2[index];
                int y_two = y2[index];

                if (x_one > x_two)
                {
                    int tmp = x_one;
                    x_one = x_two;
                    x_two = tmp;
                }
                if (y_one > y_two)
                {
                    int tmp = y_one;
                    y_one = y_two;
                    y_two = tmp;
                }

                if (x_one == x_two)
                    for (int y = y_one; y <= y_two; y++)
                        vents[y][x_one]++;

                else if (y_one == y_two)
                    for (int x = x_one; x <= x_two; x++)
                        vents[y_one][x]++;
            }


            int counter = 0;
            foreach (List<int> row in vents)
                foreach (int cell in row)
                    if (cell >= 2)
                        counter++;

            Console.WriteLine("Day:  5 | Part: 1 | Result: " + counter);
        }

        public static void Part2()
        {
            List<int> x1 = new List<int>();
            List<int> y1 = new List<int>();
            List<int> x2 = new List<int>();
            List<int> y2 = new List<int>();

            foreach (string row in File.ReadAllLines(@"../../../../../data/day5.txt"))
            {
                x1.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[0].Split(',')[0]));
                y1.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[0].Split(',')[1]));
                x2.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[1].Split(',')[0]));
                y2.Add(int.Parse(row.Split(arrow, StringSplitOptions.None)[1].Split(',')[1]));
            }

            int max_x = Math.Max(x1.Max(), x2.Max());
            int max_y = Math.Max(y1.Max(), y2.Max());

            List<List<int>> vents = new List<List<int>>(max_y + 1);

            for (int y = 0; y <= max_y; y++)
            {
                vents.Add(new List<int>(max_x + 1));
                for (int x = 0; x <= max_x; x++)
                    vents[y].Add(0);
            }

            for (int index = 0; index < x1.Count; index++)
            {
                int x_one = x1[index];
                int y_one = y1[index];
                int x_two = x2[index];
                int y_two = y2[index];

                if (x_one == x_two)
                {
                    if (y_one > y_two)
                    {
                        int tmp = y_one;
                        y_one = y_two;
                        y_two = tmp;
                    }

                    for (int y = y_one; y <= y_two; y++)
                        vents[y][x_one]++;
                }

                else if (y_one == y_two)
                {
                    if (x_one > x_two)
                    {
                        int tmp = x_one;
                        x_one = x_two;
                        x_two = tmp;
                    }

                    for (int x = x_one; x <= x_two; x++)
                        vents[y_one][x]++;
                }

                else
                {
                    if (x_one > x_two)
                    {
                        int tmp = x_one;
                        x_one = x_two;
                        x_two = tmp;
                        tmp = y_one;
                        y_one = y_two;
                        y_two = tmp;
                    }

                    for (int o = 0; o <= x_two - x_one; o++)
                        vents[y_one < y_two ? y_one + o : y_one - o][x_one + o]++;
                }
            }


            int counter = 0;
            foreach (List<int> row in vents)
                foreach (int cell in row)
                    if (cell >= 2)
                        counter++;

            Console.WriteLine("Day:  5 | Part: 2 | Result: " + counter);
        }
    }
}

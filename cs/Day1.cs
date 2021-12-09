using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace cs
{
    class Day1
    {
        public static void Part1()
        {
            int last = -1, count = 0;

            File.ReadAllLines(@"../../../../../data/day1.txt").Select(line => int.Parse(line)).ToList().ForEach(num =>
            {
                if (last > 0 && num > last)
                    count++;

                last = num;
            });

            Console.WriteLine("Day:  1 | Part: 1 | Result: " + count);
        }

        public static void Part2()
        {
            List<string> lines = File.ReadAllLines(@"../../../../../data/day1.txt").ToList();

            int last = -1, count = 0;

            for (int index = 0; index < lines.Count - 2; index++)
            {
                int sum = int.Parse(lines[index]) + int.Parse(lines[index + 1]) + int.Parse(lines[index + 2]);

                for (int off = 0; off < 3; off++) sum += int.Parse(lines[index + off]);

                if (last > 0 && sum > last)
                    count++;

                last = sum;
            }

            Console.WriteLine("Day:  1 | Part: 2 | Result: " + count);
        }
    }
}

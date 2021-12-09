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
            int last = -1;
            int count = 0;

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
            List<int> sums = new List<int>();

            for (int index = 0; index < lines.Count - 2; index++)
            {
                int sum = 0;
                for (int off = 0; off < 3; off++) sum += int.Parse(lines[index + off]);
                sums.Add(sum);
            }

            int last = -1;
            int count = 0;

            foreach (int sum in sums)
            {
                if (last > 0 && sum > last)
                    count++;
                last = sum;
            }

            Console.WriteLine("Day:  1 | Part: 2 | Result: " + count);
        }
    }
}

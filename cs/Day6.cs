using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day6
    {
        public static void Part1()
        {
            Dictionary<int, int> ages = new Dictionary<int, int>(10);
            for (int day = -1; day < 9; day++) ages.Add(day, 0);

            File.ReadLines(@"../../../../../data/day6.txt").First().Split(',').ToList().ForEach(num_s => ages[int.Parse(num_s)]++);

            for (int day = 0; day < 80; day++)
            {
                for (int age = -1; age < 8; age++) ages[age] = ages[age + 1];
                ages[6] += ages[-1];
                ages[8] = ages[-1];
            }

            Console.WriteLine("Day:  6 | Part: 1 | Result: " + (ages.Values.Sum() - ages[-1]));
        }

        public static void Part2()
        {
            Dictionary<int, long> ages = new Dictionary<int, long>(10);
            for (int day = -1; day < 9; day++) ages.Add(day, 0);

            File.ReadLines(@"../../../../../data/day6.txt").First().Split(',').ToList().ForEach(num_s => ages[int.Parse(num_s)]++);

            for (int day = 0; day < 256; day++)
            {
                for (int age = -1; age < 8; age++) ages[age] = ages[age + 1];
                ages[6] += ages[-1];
                ages[8] = ages[-1];
            }

            Console.WriteLine("Day:  6 | Part: 2 | Result: " + (ages.Values.Sum() - ages[-1]));
        }
    }
}

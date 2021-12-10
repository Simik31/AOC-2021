using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day7
    {
        public static void Part1()
        {
            List<int> positions = File.ReadLines(@"../../../../../data/day7.txt").First().Split(',').Select(num_s => int.Parse(num_s)).ToList();

            int min_cost = int.MaxValue;

            foreach (int end_position in new HashSet<int>(positions))
            {
                int position_cost = 0;

                foreach (int crab_position in positions)
                    position_cost += Math.Abs(crab_position - end_position);

                min_cost = Math.Min(min_cost, position_cost);
            }

            Console.WriteLine("Day:  7 | Part: 1 | Result: " + min_cost);
        }

        public static void Part2()
        {
            List<int> positions = File.ReadLines(@"../../../../../data/day7.txt").First().Split(',').Select(num_s => int.Parse(num_s)).ToList();

            int min_cost = int.MaxValue;

            for (int end_position = 1; end_position < positions.Max(); end_position++)
            {
                int position_cost = 0;

                foreach (int crab_position in positions)
                    for (int step = 1; step <= Math.Abs(end_position - crab_position); step++)
                        position_cost += step;

                min_cost = Math.Min(min_cost, position_cost);
            }

            Console.WriteLine("Day:  7 | Part: 2 | Result: " + min_cost);
        }
    }
}

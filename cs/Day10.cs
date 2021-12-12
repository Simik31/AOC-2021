using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day10
    {
        public static void Part1()
        {
            List<char> opens = new List<char>() { '(', '[', '{', '<' };
            List<char> closes = new List<char>() { ')', ']', '}', '>' };
            Dictionary<char, int> incorrects = new Dictionary<char, int>() { { ')', 0 }, { ']', 0 }, { '}', 0 }, { '>', 0 } };

            File.ReadLines(@"../../../../../data/day10.txt").ToList().ForEach(line =>
            {
                List<char> pairs = new List<char>();
                for (int index = 0; index < line.Trim().Length; index++)
                {
                    char c = line[index];
                    if (opens.Contains(c))
                        pairs.Add(c);
                    else if (opens.IndexOf(pairs.Last()) == closes.IndexOf(c))
                        pairs.RemoveAt(pairs.Count - 1);
                    else
                    {
                        incorrects[c]++;
                        break;
                    }
                }
            });

            int result = incorrects[')'] * 3 + incorrects[']'] * 57 + incorrects['}'] * 1197 + incorrects['>'] * 25137;

            Console.WriteLine("Day: 10 | Part: 1 | Result: " + result);
        }

        public static void Part2()
        {
            List<char> opens = new List<char>() { '(', '[', '{', '<' };
            List<char> closes = new List<char>() { ')', ']', '}', '>' };
            List<long> scores = new List<long>();

            File.ReadLines(@"../../../../../data/day10.txt").ToList().ForEach(line =>
            {
                List<char> pairs = new List<char>();
                long score = 0;
                bool corrupted = false;

                for (int index = 0; index < line.Trim().Length; index++)
                {
                    char c = line[index];
                    if (opens.Contains(c))
                        pairs.Add(c);
                    else if (opens.IndexOf(pairs.Last()) == closes.IndexOf(c))
                        pairs.RemoveAt(pairs.Count - 1);
                    else
                    {
                        corrupted = true;
                        break;
                    }
                }

                if (!corrupted)
                {
                    while (pairs.Count > 0)
                    {
                        score = score * 5 + opens.IndexOf(pairs.Last()) + 1;
                        pairs.RemoveAt(pairs.Count - 1);
                    }
                    scores.Add(score);
                }
            });

            scores.Sort();
            long result = scores[scores.Count / 2];

            Console.WriteLine("Day: 10 | Part: 1 | Result: " + result);
        }
    }
}

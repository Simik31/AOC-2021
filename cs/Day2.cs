using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day2
    {
        public static void Part1()
        {
            int h_pos = 0, v_pos = 0;

            File.ReadAllLines(@"../../../../../data/day2.txt").ToList().ForEach(line =>
            {
                int value = int.Parse(line.Split(' ')[1]);
                switch (line.Split(' ')[0])
                {
                    case "forward":
                        h_pos += value;
                        break;
                    case "down":
                        v_pos += value;
                        break;
                    case "up":
                        v_pos -= value;
                        break;
                    default:
                        throw new Exception("Unsupported disrection " + line.Split(' ')[0]);
                }
            });
            
            Console.WriteLine("Day:  2 | Part: 1 | Result: " + (h_pos * v_pos));
        }

        public static void Part2()
        {
            int h_pos = 0, v_pos = 0, aim = 0;

            File.ReadAllLines(@"../../../../../data/day2.txt").ToList().ForEach(line => 
            {
                int value = int.Parse(line.Split(' ')[1]);

                switch (line.Split(' ')[0])
                {
                    case "forward":
                        h_pos += value;
                        v_pos += aim * value;
                        break;
                    case "down":
                        aim += value;
                        break;
                    case "up":
                        aim -= value;
                        break;
                    default:
                        throw new Exception("Unsupported disrection " + line.Split(' ')[0]);
                }
            });

            Console.WriteLine("Day:  2 | Part: 2 | Result: " + (h_pos * v_pos));
        }
    }
}

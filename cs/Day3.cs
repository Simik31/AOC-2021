using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace cs
{
    class Day3
    {
        public static void Part1()
        {
            List<string> data = File.ReadAllLines(@"../../../../../data/day3.txt").ToList();

            int gama = 0, epsilon = 0;

            for (int i = 0; i < data[0].Length; i++)
            {
                int[] counter = new int[] { 0, 0 };

                foreach (string row in data) counter[row[i] - '0']++;

                gama = (gama << 1) + (counter[0] > counter[1] ? 0 : 1);
                epsilon = (epsilon << 1) + (counter[0] > counter[1] ? 1 : 0);
            }

            Console.WriteLine("Day:  3 | Part: 1 | Result: " + (gama * epsilon));
        }

        public static void Part2()
        {
            List<string> data_og = File.ReadAllLines(@"../../../../../data/day3.txt").ToList();
            List<string> data_co2s = new List<string>(data_og);

            for (int i = 0; i < data_og[0].Length; i++)
            {
                if (data_og.Count > 1)
                {
                    int[] counter = new int[] { 0, 0 };

                    foreach (string row in data_og) counter[row[i] - '0']++;
                
                    data_og = data_og.Where(r => r[i] == (counter[1] >= counter[0] ? '1' : '0')).ToList();
                }

                if (data_co2s.Count > 1)
                {
                    int[] counter = new int[] { 0, 0 };
                
                    foreach (string row in data_co2s) counter[row[i] - '0']++;
                
                    data_co2s = data_co2s.Where(r => r[i] == (counter[1] >= counter[0] ? '0' : '1')).ToList();
                }

                if (data_og.Count == 1 && data_co2s.Count == 1)
                    break;
            }

            Console.WriteLine("Day:  3 | Part: 2 | Result: " + (Convert.ToInt32(data_og[0], 2) * Convert.ToInt32(data_co2s[0], 2)));
        }
    }
}

#include "Day3.h"

void Day3::part1()
{
    vector<string> data;
    Utils::read_lines_from_file("../data/day3.txt", data);

    int gama = 0;
    int epsilon = 0;

    for (int i = 0; i < data[0].size(); i++)
    {
        int* counter = new int[] {0, 0};

        for (string row : data)
            counter[row.at(i) - '0']++;

        gama = (gama << 1) + (counter[0] > counter[1] ? 0 : 1);
        epsilon = (epsilon << 1) + (counter[0] > counter[1] ? 1 : 0);
    }

    cout << "Day:  3 | Part: 1 | Result: " << gama * epsilon << endl;
}

void Day3::part2()
{
    vector<string> data_og;
    Utils::read_lines_from_file("../data/day3.txt", data_og);

    vector<string> data_co2s(data_og);

    for (int i = 0; i < data_og[0].size(); i++)
    {
        if (data_og.size() > 1) {
            int* counter = new int[] {0, 0};

            for (string row : data_og)
                counter[row.at(i) - '0']++;

            data_og.erase(
                remove_if(data_og.begin(), data_og.end(), [i, counter](string row) { return row.at(i) == (counter[1] >= counter[0] ? '1' : '0'); }),
                data_og.end()
            );
        }

        if (data_co2s.size() > 1) {
            int* counter = new int[] {0, 0};

            for (string row : data_co2s)
                counter[row.at(i) - '0']++;

            data_co2s.erase(
                remove_if(data_co2s.begin(), data_co2s.end(), [i, counter](string row) { return row.at(i) == (counter[1] >= counter[0] ? '0' : '1'); }),
                data_co2s.end()
            );
        }

        if (data_og.size() == 1 && data_co2s.size() == 1)
            break;
    }

    cout << "Day:  3 | Part: 2 | Result: " << stoi(data_og[0], nullptr, 2) * stoi(data_co2s[0], nullptr, 2) << endl;
}
#include "Day3.h"

void Day3::part1()
{
    std::vector<std::string> data;
    Utils::read_lines_from_file("../data/day3.txt", data);

    int gama = 0;
    int epsilon = 0;

    for (int i = 0; i < data[0].size(); i++)
    {
        int* counter = new int[] {0, 0};

        for (std::string row : data)
            counter[row.at(i) - '0']++;

        gama = (gama << 1) + (counter[0] > counter[1] ? 0 : 1);
        epsilon = (epsilon << 1) + (counter[0] > counter[1] ? 1 : 0);
    }

    std::cout << "Day:  3 | Part: 1 | Result: " << gama * epsilon << std::endl;
}

void Day3::part2()
{
    std::vector<std::string> data_og;
    Utils::read_lines_from_file("../data/day3.txt", data_og);

    std::vector<std::string> data_co2s(data_og);

    for (int i = 0; i < data_og[0].size(); i++)
    {
        if (data_og.size() > 1) {
            int* counter = new int[] {0, 0};

            for (std::string row : data_og)
                counter[row.at(i) - '0']++;

            data_og.erase(
                std::remove_if(data_og.begin(), data_og.end(), [i, counter](std::string row) { return row.at(i) == (counter[1] >= counter[0] ? '1' : '0'); }),
                data_og.end()
            );
        }

        if (data_co2s.size() > 1) {
            int* counter = new int[] {0, 0};

            for (std::string row : data_co2s)
                counter[row.at(i) - '0']++;

            data_co2s.erase(
                std::remove_if(data_co2s.begin(), data_co2s.end(), [i, counter](std::string row) { return row.at(i) == (counter[1] >= counter[0] ? '0' : '1'); }),
                data_co2s.end()
            );
        }

        if (data_og.size() == 1 && data_co2s.size() == 1)
            break;
    }

    std::cout << "Day:  3 | Part: 2 | Result: " << std::stoi(data_og[0], nullptr, 2) * std::stoi(data_co2s[0], nullptr, 2) << std::endl;
}
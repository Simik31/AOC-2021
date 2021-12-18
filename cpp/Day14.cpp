#include "Day14.h"

void Day14::part1()
{
    map<string, string> rules{};
    set<string> chars{};

    vector<string> lines{};
    Utils::read_lines_from_file("../data/day14.txt", lines);
    
    string polymer = lines[0];

    for (int line_id = 2; line_id < lines.size(); line_id++)
    {
        vector<string> line_parts{};
        Utils::split_string(lines[line_id], " -> ", line_parts);

        chars.insert(line_parts[1]);
        rules.insert(pair<string, string>(line_parts[0], line_parts[1] + line_parts[0][1]));
    }

    for (int step = 0; step < 10; step++)
    {
        string new_polymer = polymer.substr(0, 1);

        for (int pair_id = 0; pair_id < polymer.length() - 1; pair_id++)
            new_polymer += rules[polymer.substr(pair_id, 2)];

        polymer = new_polymer;
    }

    vector<size_t> count = {};
    for (string c : chars)
        count.push_back(Utils::count_substring(polymer, c));

    size_t result = *max_element(count.begin(), count.end()) - *min_element(count.begin(), count.end());

    cout << "Day: 14 | Part: 1 | Result:" << result << endl;
}

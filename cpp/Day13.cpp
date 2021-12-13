#include "Day13.h"

void Day13::part1()
{
    vector<vector<bool>> paper;

    vector<string> lines;
    Utils::read_lines_from_file("../data/day13.txt", lines);
    int folding_section_start = 0;

    for (int line_id = 0; line_id < lines.size(); line_id++)
    {
        folding_section_start++;
        string line = lines[line_id];
        if (line == "") break;

        vector<string> ln;
        Utils::split_string(line, ",", ln);
        int x = stoi(ln[0]), y = stoi(ln[1]);

        while (paper.size() <= y) paper.push_back(vector<bool>());
        while (paper[y].size() <= x) paper[y].push_back(false);

        paper[y][x] = true;
    }

    size_t longest = 0;
    for (vector<bool> line : paper) longest = max(longest, line.size());

    for (int line = 0; line < lines.size(); line++) while (paper[line].size() < longest) paper[line].push_back(false);

    string fold_line = lines[folding_section_start];

    vector<string> parts;
    Utils::split_string(fold_line, " ", parts);

    vector<string> fold;
    Utils::split_string(parts[parts.size() - 1], "=", fold);

    int fold_index = stoi(fold[1]);

    for (int line = 0; line < paper.size(); line++)
    {
        for (int index = 0; index < longest - fold_index - 1; index++)
            paper[line][index] = paper[line][index] | paper[line][longest - index - 1];
        paper[line].erase(paper[line].begin() + fold_index, paper[line].end());
    }

    int result = 0;
    for (vector<bool> line : paper)
        for (bool c : line)
            if (c) result++;

    cout << "Day: 13 | Part: 1 | Result: " << result << endl;
}

void Day13::part2()
{
    vector<vector<bool>> paper;

    vector<string> lines;
    Utils::read_lines_from_file("../data/day13.txt", lines);
    int folding_section_start = 0;

    for (int line_id = 0; line_id < lines.size(); line_id++)
    {
        folding_section_start++;
        string line = lines[line_id];
        if (line == "") break;

        vector<string> ln;
        Utils::split_string(line, ",", ln);
        int x = stoi(ln[0]), y = stoi(ln[1]);

        while (paper.size() <= y) paper.push_back(vector<bool>());
        while (paper[y].size() <= x) paper[y].push_back(false);

        paper[y][x] = true;
    }

    size_t longest = 0;
    for (vector<bool> line : paper) longest = max(longest, line.size());

    for (int line = 0; line < lines.size(); line++) while (paper[line].size() < longest) paper[line].push_back(false);

    for (int fold_line_id = folding_section_start; fold_line_id < lines.size(); fold_line_id++)
    {
        longest = 0;
        for (vector<bool> line : paper) longest = max(longest, line.size());

        string fold_line = lines[fold_line_id];

        vector<string> parts;
        Utils::split_string(fold_line, " ", parts);

        vector<string> fold;
        Utils::split_string(parts[parts.size() - 1], "=", fold);

        string fold_axis = fold[0];
        int fold_index = stoi(fold[1]);

        if (fold_axis == "x")
            for (int line = 0; line < paper.size(); line++)
            {
                for (int index = 0; index < longest - fold_index - 1; index++)
                    paper[line][index] = paper[line][index] | paper[line][longest - index - 1];
                paper[line].erase(paper[line].begin() + fold_index, paper[line].end());
            }

        else if (fold_axis == "y")
        {
            for (int line = 0; line < paper.size() - fold_index - 1; line++)
                for (int index = 0; index < longest; index++)
                    paper[line][index] = paper[line][index] | paper[paper.size() - line - 1][index];
            paper.erase(next(paper.begin(), fold_index), paper.end());
        }
    }

    cout << "Day: 13 | Part: 2 | Result: " << endl;

    for (vector<bool> line : paper)
    {
        for (bool c : line)
            cout << (c ? "#" : " ");
        cout << endl;
    }
}
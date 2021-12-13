require('./utils.js');

module.exports = {
    this:part1 = function () {
        var paper = [];
        var lines = readFile("../data/day13.txt");
        var folding_section_start = 0;

        for (var line_id = 0; line_id < lines.length; line_id++) {
            folding_section_start++;
            var line = lines[line_id];         
            if (line == "") break;

            var ln = line.split(",");
            var x = parseInt(ln[0]), y = parseInt(ln[1]);

            while (paper.length <= y) paper.push([]);
            while (paper[y].length <= x) paper[y].push(false);

            paper[y][x] = true;
        }

        var longest = 0;
        paper.forEach(line => longest = Math.max(longest, line.length));

        paper.forEach(line => {
            while (line.length < longest) line.push(false)
        });

        var fold_line = lines[folding_section_start];
        var fold_index = parseInt(fold_line.substring(fold_line.lastIndexOf(" ") + 1).split("=")[1]);

        for (var line_id = 0; line_id < paper.length; line_id++) {   
            for (var index = 0; index < longest - fold_index - 1; index++)
                paper[line_id][index] = paper[line_id][index] | paper[line_id][longest - index - 1];

            for (var remove = 0; remove <= fold_index; remove++)
                paper[line_id].pop();
        }

        var result = 0;
        paper.forEach(line => {
            line.forEach(c => {
                if (c) result++;
            });
        });

        console.info("Day: 13 | Part: 1 | Result: " + result);
    },

    this:part2 = function () {
        var paper = [];
        var lines = readFile("../data/day13.txt");
        var folding_section_start = 0;

        for (var line_id = 0; line_id < lines.length; line_id++) {
            folding_section_start++;
            var line = lines[line_id];         
            if (line == "") break;

            var ln = line.split(",");
            var x = parseInt(ln[0]), y = parseInt(ln[1]);

            while (paper.length <= y) paper.push([]);
            while (paper[y].length <= x) paper[y].push(false);

            paper[y][x] = true;
        }

        var longest = 0;
        paper.forEach(line => longest = Math.max(longest, line.length));

        paper.forEach(line => {
            while (line.length < longest) line.push(false)
        });

        for (var fold_line_id = folding_section_start; fold_line_id < lines.length; fold_line_id++) {
            longest = 0;
            paper.forEach(line => longest = Math.max(longest, line.length));

            var fold_line = lines[fold_line_id];
            var interest = fold_line.substring(fold_line.lastIndexOf(" ") + 1);
            var fold_axis = interest.split("=")[0];
            var fold_index = parseInt(interest.split("=")[1]);

            if (fold_axis == "x") {
                for (var line_id = 0; line_id < paper.length; line_id++) {   
                    for (var index = 0; index < longest - fold_index - 1; index++)
                        paper[line_id][index] = paper[line_id][index] | paper[line_id][longest - index - 1];

                    for (var remove = 0; remove <= fold_index; remove++)
                        paper[line_id].pop();
                }
            } else if (fold_axis == "y") {
                for (var line = 0; line < paper.length - fold_index - 1; line++)
                    for (var index = 0; index < longest; index++)
                        paper[line][index] = paper[line][index] | paper[paper.length - line - 1][index];

                for (var remove = 0; remove <= fold_index; remove++)
                    paper.pop();
            }
        }

        console.info("Day: 13 | Part: 2 | Result:");

        paper.forEach(line => {
            line.forEach(c => {
                process.stdout.write(c ? "#" : " ");
            });
            process.stdout.write("\n");
        });
    }
}
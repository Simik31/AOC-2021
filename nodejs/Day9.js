require('./utils.js');

module.exports = {
    this:part1 = function () {
        var height_map = [];
        var lowest_truths = [];

        readFile('../data/day9.txt').forEach((row) => {
            if (row != "") {
                height_map.push([]);
                lowest_truths.push([]);

                Array.from(row).forEach((char) => {
                    height_map[height_map.length - 1].push(parseInt(char));
                    lowest_truths[height_map.length - 1].push(false);
                });
            }
        });

        for (var r = 0; r < height_map.length; r++) {
            for (var c = 0; c < height_map[r].length; c++) {
                var truths = [];

                if (r >= 1)
                    truths.push(height_map[r][c] < height_map[r - 1][c])
                if (r + 1 < height_map.length)
                    truths.push(height_map[r][c] < height_map[r + 1][c])
                if (c >= 1)
                    truths.push(height_map[r][c] < height_map[r][c - 1])
                if (c + 1 < height_map[r].length)
                    truths.push(height_map[r][c] < height_map[r][c + 1])

                    lowest_truths[r][c] = truths.includes(false) == false
            }
        }

        var result = 0;        
        for (var r = 0; r < height_map.length; r++)
            for (var c = 0; c < height_map[r].length; c++)
                if (lowest_truths[r][c])
                    result += height_map[r][c] + 1;
    
        console.info("Day:  9 | Part: 1 | Result: " + result);
    },

    this:part2 = function () {
        var height_map = [];
        var lowest_truths = [];

        readFile('../data/day9.txt').forEach((row) => {
            if (row != "") {
                height_map.push([]);
                lowest_truths.push([]);

                Array.from(row).forEach((char) => {
                    height_map[height_map.length - 1].push(parseInt(char));
                    lowest_truths[height_map.length - 1].push(false);
                });
            }
        });

        for (var r = 0; r < height_map.length; r++) {
            for (var c = 0; c < height_map[r].length; c++) {
                var truths = [];

                if (r >= 1)
                    truths.push(height_map[r][c] < height_map[r - 1][c])
                if (r + 1 < height_map.length)
                    truths.push(height_map[r][c] < height_map[r + 1][c])
                if (c >= 1)
                    truths.push(height_map[r][c] < height_map[r][c - 1])
                if (c + 1 < height_map[r].length)
                    truths.push(height_map[r][c] < height_map[r][c + 1])

                    lowest_truths[r][c] = truths.includes(false) == false
            }
        }

        var basins = []
    
        for (var r = 0; r < height_map.length; r++)
            for (var c = 0; c < height_map[r].length; c++)
                if (lowest_truths[r][c])
                    basins.push(backtrack_basin(height_map, r, c, 0, []));


        basins.sort((a, b) => { return a - b; });
        var result = basins.pop() * basins.pop() * basins.pop();
    
        console.info("Day:  9 | Part: 2 | Result: " + result);
    }
}

function backtrack_basin(height_map, r, c, counter, visited) {
    if (searchForArray(visited, [r, c]) > -1)
        return counter;    

    visited.push([r, c]);

    if (height_map[r][c] == 9)
        return counter;

    counter += 1;

    if (r >= 1)
        counter = backtrack_basin(height_map, r - 1, c, counter, visited);
    if (r + 1 < height_map.length)
        counter = backtrack_basin(height_map, r + 1, c, counter, visited);
    if (c >= 1)
        counter = backtrack_basin(height_map, r, c - 1, counter, visited);
    if (c + 1 < height_map[r].length)
        counter = backtrack_basin(height_map, r, c + 1, counter, visited);

    return counter;
}
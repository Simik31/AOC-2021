require('./utils.js');

module.exports = {
    this:part1 = function () {
        var x1 = [];
        var y1 = [];
        var x2 = [];
        var y2 = [];

        readFile('../data/day5.txt').forEach((row) => {
            x1.push(parseInt(row.split(" -> ")[0].split(",")[0]));
            y1.push(parseInt(row.split(" -> ")[0].split(",")[1]));
            x2.push(parseInt(row.split(" -> ")[1].split(",")[0]));
            y2.push(parseInt(row.split(" -> ")[1].split(",")[1]));
        });

        var max_x = Math.max(Math.max(...x1), Math.max(...x2));
        var max_y = Math.max(Math.max(...y1), Math.max(...y2));

        var vents = [];
        for (var y = 0; y < max_y + 1; y++) {
            vents.push([]);
            for (var x = 0; x < max_x + 1; x++)
                vents[y].push(0);
        }

        for (var index = 0; index < x1.length; index++) {
            x_one = x1[index];
            y_one = y1[index];
            x_two = x2[index];
            y_two = y2[index];

            if (x_one > x_two) [x_one, x_two] = [x_two, x_one]
            if (y_one > y_two) [y_one, y_two] = [y_two, y_one]

            if (x_one == x_two)
                for (var y = y_one; y < y_two + 1; y++)
                    vents[y][x_one]++;

            else if (y_one == y_two)
                for (var x = x_one; x < x_two + 1; x++)
                    vents[y_one][x]++;
        }
    
        var counter = 0
    
        vents.forEach((row) => {
            row.forEach((cell) => {
                if (cell >= 2) counter++;
            });
        });

        console.info("Day:  5 | Part: 1 | Result: " + counter);
    },

    this:part2 = function () {
        var x1 = [];
        var y1 = [];
        var x2 = [];
        var y2 = [];

        readFile('../data/day5.txt').forEach((row) => {
            x1.push(parseInt(row.split(" -> ")[0].split(",")[0]));
            y1.push(parseInt(row.split(" -> ")[0].split(",")[1]));
            x2.push(parseInt(row.split(" -> ")[1].split(",")[0]));
            y2.push(parseInt(row.split(" -> ")[1].split(",")[1]));
        });

        var max_x = Math.max(Math.max(...x1), Math.max(...x2));
        var max_y = Math.max(Math.max(...y1), Math.max(...y2));

        var vents = [];
        for (var y = 0; y < max_y + 1; y++) {
            vents.push([]);
            for (var x = 0; x < max_x + 1; x++)
                vents[y].push(0);
        }

        for (var index = 0; index < x1.length; index++) {
            x_one = x1[index];
            y_one = y1[index];
            x_two = x2[index];
            y_two = y2[index];

            if (x_one == x_two) {                
                if (y_one > y_two) [y_one, y_two] = [y_two, y_one];
                for (var y = y_one; y < y_two + 1; y++)
                    vents[y][x_one]++;
            }

            else if (y_one == y_two) {
                if (x_one > x_two) [x_one, x_two] = [x_two, x_one];
                for (var x = x_one; x < x_two + 1; x++)
                    vents[y_one][x]++;
            }

            else {
                if (x_one > x_two) {
                    [x_one, x_two] = [x_two, x_one];
                    [y_one, y_two] = [y_two, y_one];
                }

                for (var o = 0; o < x_two - x_one + 1; o++)
                    vents[y_one < y_two ? y_one + o : y_one - o][x_one + o]++;
            }
        }
    
        var counter = 0
    
        vents.forEach((row) => {
            row.forEach((cell) => {
                if (cell >= 2) counter++;
            });
        });

        console.info("Day:  5 | Part: 2 | Result: " + counter);
    }
}
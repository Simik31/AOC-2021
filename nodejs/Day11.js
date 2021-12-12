require('./utils.js');

module.exports = {
    this:part1 = function () {
        var grid = [];
        
        readFile("../data/day11.txt").forEach((line) => {
            grid.push([]);
            Array.from(line).forEach((char) => {
                grid[grid.length - 1].push([Number(char), false]);
            });
        });

        var counter = 0;
        for (var step = 0; step < 100; step++) {
            for (var row = 0; row < grid.length; row++) {
                for (var col = 0; col < grid[row].length; col++) {
                    grid[row][col][1] = false;
                }
            }

            for (var row = 0; row < grid.length; row++) {
                for (var col = 0; col < grid[row].length; col++) {
                    counter = flash(grid, col, row, counter);
                }
            }
        }

        console.info("Day: 11 | Part: 1 | Result: " + counter);
    },

    this:part2 = function () {
        var grid = [];
        
        readFile("../data/day11.txt").forEach((line) => {
            grid.push([]);
            Array.from(line).forEach((char) => {
                grid[grid.length - 1].push([Number(char), false]);
            });
        });

        var step = 0;
        for (; !grid.every(row => row.every(col => col[1])); step++) {
            for (var row = 0; row < grid.length; row++) {
                for (var col = 0; col < grid[row].length; col++) {
                    grid[row][col][1] = false;
                }
            }

            for (var row = 0; row < grid.length; row++) {
                for (var col = 0; col < grid[row].length; col++) {
                    flash(grid, col, row, 0);
                }
            }
        }

        console.info("Day: 11 | Part: 2 | Result: " + step);
    }
}

function flash(grid, x, y, counter) {
	if (grid[y][x][1])
		return counter;

	grid[y][x][0] += 1

	if (grid[y][x][0] > 9) {
		grid[y][x][0] = 0;
		grid[y][x][1] = true;
		counter++;

		for (var y_off = -1; y_off < 2; y_off++)
			for (var x_off = -1; x_off < 2; x_off++)
				if (y + y_off >= 0 && y + y_off < grid.length && x + x_off >= 0 && x + x_off < grid[y+y_off].length)
					counter = flash(grid, x+x_off, y+y_off, counter);
	}

    return counter
}
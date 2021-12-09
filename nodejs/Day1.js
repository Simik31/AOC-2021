require('./utils.js');

module.exports = {
    this:part1 = function () {
        var last = -1, count = 0;

        readFile('../data/day1.txt').forEach((line) => {
            var num = Number(line);

            if (last > 0 && num > last)
                count++;

            last = num;
        })

        console.info("Day:  1 | Part: 1 | Result: " + count)
    },

    this:part2 = function () {
        var lines = readFile('../data/day1.txt');

        var last = -1, count = 0;

        for (var index = 0; index < lines.length - 2; index++) {
            var sum = Number(lines[index]) + Number(lines[index + 1]) + Number(lines[index + 2]);
            
            if (last > 0 && sum > last)
                count++;

            last = sum;
        }

        console.info("Day:  1 | Part: 2 | Result: " + count)
    }
}

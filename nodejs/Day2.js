require('./utils.js');

module.exports = {
    this:part1 = function () {
        var h_pos = 0, v_pos = 0;

        readFile('../data/day2.txt').forEach((line) => {
            var value = Number(line.split(' ')[1]);

            switch (line.split(' ')[0])
            {
                case "forward":
                    h_pos += value;
                    break;
                case "down":
                    v_pos += value;
                    break;
                case "up":
                    v_pos -= value;
                    break;
                default:
                    console.error("Unsupported direction " + line.split(' ')[0]);
            }
        })

        console.info("Day:  2 | Part: 1 | Result: " + (h_pos * v_pos))
    },

    this:part2 = function () {
        var h_pos = 0, v_pos = 0, aim = 0;

        readFile('../data/day2.txt').forEach((line) => {
            var value = Number(line.split(' ')[1]);

            switch (line.split(' ')[0])
            {
                case "forward":
                    h_pos += value;
                    v_pos += value * aim;
                    break;
                case "down":
                    aim += value;
                    break;
                case "up":
                    aim -= value;
                    break;
                default:
                    console.error("Unsupported direction " + line.split(' ')[0]);
            }
        })

        console.info("Day:  2 | Part: 2 | Result: " + (h_pos * v_pos))
    }
}

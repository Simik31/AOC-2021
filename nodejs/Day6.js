require('./utils.js');

module.exports = {
    this:part1 = function () {
        var ages = new Map();
        for (var age = -1; age < 9; age++) ages.set(age, 0);

        readFile("../data/day6.txt")[0].split(",").forEach((num_s) => { ages.set(parseInt(num_s), ages.get(parseInt(num_s)) + 1) });


        for (var day = 0; day < 80; day++) {
            for (var age = -1; age < 8; age++)
                ages.set(age, ages.get(age+1));
            
            ages.set(6, ages.get(-1) + ages.get(6));
            ages.set(8, ages.get(-1));
        }

        var result = 0
        for (var age = 0; age < 9; age++) {
            result += ages.get(age);
        }

        console.info("Day:  6 | Part: 1 | Result: " + result);
    },

    this:part2 = function () {
        var ages = new Map();
        for (var age = -1; age < 9; age++) ages.set(age, 0);

        readFile("../data/day6.txt")[0].split(",").forEach((num_s) => { ages.set(parseInt(num_s), ages.get(parseInt(num_s)) + 1) });


        for (var day = 0; day < 256; day++) {
            for (var age = -1; age < 8; age++)
                ages.set(age, ages.get(age+1));
            
            ages.set(6, ages.get(-1) + ages.get(6));
            ages.set(8, ages.get(-1));
        }

        var result = 0
        for (var age = 0; age < 9; age++) {
            result += ages.get(age);
        }

        console.info("Day:  6 | Part: 2 | Result: " + result);
    }
}
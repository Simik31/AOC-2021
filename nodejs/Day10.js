require('./utils.js');

module.exports = {
    this:part1 = function () {
        var opens = ["(", "[", "{", "<"];
        var closes = [")", "]", "}", ">"];
        var incorects = new Map([[")", 0], ["]", 0], ["}", 0], [">", 0]]);

        readFile("../data/day10.txt").forEach((line) => {
            var pairs = [];
            
            for (var index = 0; index < line.length; index++) {
                var char = line.charAt(index);
                if (opens.includes(char))
                    pairs.push(char);
                else if (opens.indexOf(pairs[pairs.length - 1]) == closes.indexOf(char))
                    pairs.pop();
                else {
                    incorects.set(char, incorects.get(char) + 1);
                    break;
                }
            }
        });

        var result = incorects.get(")") * 3 + incorects.get("]") * 57 + incorects.get("}") * 1197 + incorects.get(">") * 25137;
        console.info("Day: 10 | Part: 1 | Result: " + result);
    },

    this:part2 = function () {
        var opens = ["(", "[", "{", "<"];
        var closes = [")", "]", "}", ">"];
        var scores = [];

        readFile("../data/day10.txt").forEach((line) => {
            var pairs = [];
            var score = 0;
            var corrupted = false;
            
            for (var index = 0; index < line.length; index++) {
                var char = line.charAt(index);
                if (opens.includes(char))
                    pairs.push(char);
                else if (opens.indexOf(pairs[pairs.length - 1]) == closes.indexOf(char))
                    pairs.pop();
                else {
                    corrupted = true;
                    break;
                }
            }

            if (corrupted == false)
            {
                while(pairs.length > 0)
                    score = score * 5 + opens.indexOf(pairs.pop()) + 1;
                scores.push(score);
            }
        });

        scores.sort((a, b) => { return a - b; });
        var result = scores[Math.floor(scores.length / 2)];
        console.info("Day: 10 | Part: 2 | Result: " + result);
    }
}

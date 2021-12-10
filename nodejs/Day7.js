require('./utils.js');

module.exports = {
    this:part1 = function () {
        var positions = []

        readFile('../data/day7.txt')[0].split(",").forEach((num_s) => {
            positions.push(parseInt(num_s));
        });

        var min_cost = Number.MAX_VALUE;

        for (var position_end_id = 0; position_end_id < positions.length; position_end_id++) {
            var position_cost = 0
    
            for (var position_crab_id = 0; position_crab_id < positions.length; position_crab_id++)
                position_cost += Math.abs(positions[position_end_id] - positions[position_crab_id]);
    
            min_cost = Math.min(min_cost, position_cost);
        }
    
        console.info("Day:  7 | Part: 1 | Result:", min_cost)
    },

    this:part2 = function () {
        var positions = []

        readFile('../data/day7.txt')[0].split(",").forEach((num_s) => {
            positions.push(parseInt(num_s));
        });

        var min_cost = Number.MAX_VALUE;

        for (var position_end = 0; position_end < Math.max(...positions); position_end++) {
            var position_cost = 0
    
            for (var position_crab_id = 0; position_crab_id < positions.length; position_crab_id++)
                for (var step = 1; step <= Math.abs(position_end - positions[position_crab_id]); step++)
                    position_cost += step
    
            min_cost = Math.min(min_cost, position_cost);
        }

        console.info("Day:  7 | Part: 2 | Result:", min_cost)
    }
}
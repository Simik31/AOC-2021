require('./utils.js');

module.exports = {
    this:part1 = function () {
        var data = readFile('../data/day3.txt');
       
        var gama = 0;
        var epsilon = 0;

        for (var i = 0; i < data[0].length; i++) {
            counter = [0, 0];

            data.forEach((row) => { counter[row.at(i)]++; })

            gama = (gama << 1) + (counter[0] > counter[1] ? 0 : 1);
            epsilon = (epsilon << 1) + (counter[0] > counter[1] ? 1 : 0);
        }        

        console.info("Day:  3 | Part: 1 | Result: " + (gama * epsilon))
    },
    
    this:part2 = function () {
        var data_og = []
        readFile('../data/day3.txt').forEach((line) => { data_og.push(line) });
        var data_co2s = [...data_og]

        for (var i = 0; i < data_og[0].length; i++) {
            if (data_og.length > 1) {
                var counter = [0, 0];

                data_og.forEach((row) => { counter[row.at(i)]++; })

                data_og = data_og.filter(function(value){ 
                    return value.at(i) == (counter[1] >= counter[0] ? '1' : '0')
                });
            }

            if (data_co2s.length > 1) {
                var counter = [0, 0];

                data_co2s.forEach((row) => { counter[row.at(i)]++; })

                data_co2s = data_co2s.filter(function(value){ 
                    return value.at(i) == (counter[1] >= counter[0] ? '0' : '1')
                });
            }

            if (data_og.length == 1 && data_co2s.length == 1) break;
        }        

        console.info("Day:  3 | Part: 2 | Result: " + (parseInt(data_og[0], 2) * parseInt(data_co2s[0], 2)))
    }
}

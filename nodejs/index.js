for (var day = 1; day <= 11; day++) {
    if (day === 8)
        continue;

    var Day = require('./Day' + day + '.js');

    Day:part1();
    Day:part2();
}
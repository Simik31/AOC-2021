for (var day = 1; day <= 9; day++) {
    if (day === 8)
        continue;

    var Day = require('./Day' + day + '.js');

    Day:part1();
    Day:part2();
}
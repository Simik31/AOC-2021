for (var day = 1; day <= 13; day++) {
    if (day === 8 || day === 12)
        continue;

    var Day = require('./Day' + day + '.js');

    Day:part1();
    Day:part2();
}
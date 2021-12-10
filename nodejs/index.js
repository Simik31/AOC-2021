for (var day = 1; day <= 5; day++) {
    var Day = require('./Day' + day + '.js');

    Day:part1();
    Day:part2();
}
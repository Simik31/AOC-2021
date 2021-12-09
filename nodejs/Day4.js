require('./utils.js');

function testBoardForBingo(marked)
{
	for (var row_id = 0; row_id < marked.length; row_id++)
	{
		var row_true = true;
        var col_true = true;

		for (var cell_id = 0; cell_id < marked[row_id].length; cell_id++)
		{
			if (marked[row_id][cell_id] == false)
				row_true = false;

			if (marked[cell_id][row_id] == false)
				col_true = false;
		}

		if (row_true || col_true)
			return true;
	}

	return false;
}

module.exports = {
    this:part1 = function () {
        var rows = [];
        var mark = [];
        
        var lines = readFile('../data/day4.txt');
        var order = [];
        
        lines[0].split(',').map((number) => { order.push(Number(number)) });
        
	    var board_id = -1, line_id = 0;

        for (var i = 1; i < lines.length; i++)
        {
            if (lines[i] == '') {
                board_id++;
                line_id = 0;

                rows.push([]);
                mark.push([]);
            } else {
                rows[board_id].push([]);
                mark[board_id].push([]);
                
                lines[i].split(/[^\d]/).forEach((num_s) => {
                    if (num_s != '') {
                        rows[board_id][line_id].push(parseInt(num_s));
                        mark[board_id][line_id].push(false);
                    } 
                });

                line_id++;
            }
        }
        
	    var bingo = -1, last_draw = -1;

        for (var draw_id = 0; draw_id < order.length; draw_id++) 
        {
            var draw = order[draw_id];

            for (var b = 0; b < rows.length; b++)
                for (var r = 0; r < rows[b].length; r++)
                    for (var n = 0; n < rows[b][r].length; n++)
                        if (rows[b][r][n] == draw)
                            mark[b][r][n] = true;

            last_draw = draw;
    
            for (var index = 0; index < mark.length; index++)
                if (testBoardForBingo(mark[index]))
                    bingo = index;
    
            if (bingo != -1)
                break;
        }

        var board_sum = 0;
        for (var r = 0; r < rows[bingo].length; r++) {
            for (var n = 0; n < rows[bingo][r].length; n++)
                if (mark[bingo][r][n] == false)
                    board_sum += rows[bingo][r][n];
        }

        console.info("Day:  4 | Part: 1 | Result: " + (board_sum * last_draw))
    },
    
    this:part2 = function () {
        var bins = [];
        var rows = [];
        var mark = [];
        
        var lines = readFile('../data/day4.txt');
        var order = [];
        
        lines[0].split(',').map((number) => { order.push(Number(number)) });
        
	    var board_id = -1, line_id = 0;

        for (var i = 1; i < lines.length; i++)
        {
            if (lines[i] == '') {
                board_id++;
                line_id = 0;

                bins.push(false);
                rows.push([]);
                mark.push([]);
            } else {
                rows[board_id].push([]);
                mark[board_id].push([]);
                
                lines[i].split(/[^\d]/).forEach((num_s) => {
                    if (num_s != '') {
                        rows[board_id][line_id].push(parseInt(num_s));
                        mark[board_id][line_id].push(false);
                    } 
                });

                line_id++;
            }
        }
        
	    var bingo = -1, last_draw = -1, bingo_count = 0;

        for (var draw_id = 0; draw_id < order.length; draw_id++) 
        {
            var draw = order[draw_id];

            for (var b = 0; b < rows.length; b++)
                for (var r = 0; r < rows[b].length; r++)
                    for (var n = 0; n < rows[b][r].length; n++)
                        if (rows[b][r][n] == draw)
                            mark[b][r][n] = true;

            last_draw = draw;
    
            for (var index = 0; index < mark.length; index++)
                if (!bins[index] && testBoardForBingo(mark[index])) {
                    bins[index] = true;
                    bingo_count++;
                    bingo = index;
                }
    
            if (bingo_count == bins.length)
                break;
        }

        var board_sum = 0;
        for (var r = 0; r < rows[bingo].length; r++) {
            for (var n = 0; n < rows[bingo][r].length; n++)
                if (mark[bingo][r][n] == false)
                    board_sum += rows[bingo][r][n];
        }

        console.info("Day:  4 | Part: 2 | Result: " + (board_sum * last_draw))
    }
}
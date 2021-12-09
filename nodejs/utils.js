const fs = require('fs');

module.exports = {
    this:readFile = function(filename) {
        try {
            return fs.readFileSync(filename, 'UTF-8').split(/\r\n/);
        } catch (err) {
            console.error(err);
        }
    }
}
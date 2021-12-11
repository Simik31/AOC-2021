const fs = require('fs');

module.exports = {
    this:readFile = function(filename) {
        try {
            return fs.readFileSync(filename, 'UTF-8').split(/\r\n/);
        } catch (err) {
            console.error(err);
        }
    },

    this:searchForArray = function(haystack, needle){
        var i, j, current;
        for(i = 0; i < haystack.length; ++i){
          if(needle.length === haystack[i].length){
            current = haystack[i];
            for(j = 0; j < needle.length && needle[j] === current[j]; ++j);
            if(j === needle.length)
              return i;
          }
        }
        return -1;
      }
}
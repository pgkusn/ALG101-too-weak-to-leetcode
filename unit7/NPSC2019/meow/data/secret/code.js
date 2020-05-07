var readline = require('readline');

let lines = [];
var rl = readline.createInterface({
    input: process.stdin
});

rl.on('line', function (line) {
    lines.push(line);
});
rl.on('close', function () {
    solve(lines);
});

function solve(lines) {
    let n = lines[0];
    if (n === 0) {
        console.log(1);
    }
    else if (n === 1) {
        console.log(2);
    }
    else {
        console.log(0);
    }
}
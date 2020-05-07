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
    let k = lines[0];
    for (let i = 1; i <= k; i++) {
        if (isValid(lines[i])) {
            console.log('YES');
        }
        else {
            console.log('NO');
        }
    }
}

function isValid(str) {
    let arr = str.split(' ');
    return arr[0] !== arr[1] && arr[1] !== arr[2] && arr[2] !== arr[0];
}
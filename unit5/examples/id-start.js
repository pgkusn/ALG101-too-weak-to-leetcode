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
    lines.forEach(line => {
        console.log(isValid(line));
    });
}

function isValid(str) {
    str = str.toString();

    // 格式驗證
    if (!(/^[A-Za-z][12]\d{8}$/.test(str))) return false;

    let sum = 0;
    
    // 加上字母代表的數字
    let n = alphabetToNumber(str[0]);
    sum += Math.floor(n / 10);
    sum += (n % 10) * 9;
    
    // 加上中間的數字依序乘上8~1
    for (let i = 1; i < str.length - 1; i++) {
        sum += str[i] * (9 - i);
    }

    // 加上最後一個數字
    sum += Number(str[str.length - 1]);

    return sum % 10 === 0;
}

function alphabetToNumber(str) {
    let mapping = {
        A: 10, B: 11, C: 12, D: 13, E: 14,
        F: 15, G: 16, H: 17, I: 34, J: 18,
        K: 19, L: 20, M: 21, N: 22, O: 35,
        P: 23, Q: 24, R: 25, S: 26, T: 27,
        U: 28, V: 29, W: 32, X: 30, Y: 31, Z: 33
    };
    return mapping[str];
}
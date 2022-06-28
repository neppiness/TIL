'use strict';

// code to solve a 1st-order system of equations using matrix calculation
// ax + by + c = 0 and a'x + b'y + c = 0

// input values
let factors_1st = [1, 2, 3];
let factors_2nd = [2, 4, 6];

console.log(solution(factors_1st, factors_2nd));

function solution(factors_1st, factors_2nd) {
    const a = factors_1st[0];
    const b = factors_1st[1];
    const c = factors_1st[2];
    const d = factors_2nd[0];
    const e = factors_2nd[1];
    const f = factors_2nd[2];

    const determinant = a*e - b*d;

    if (determinant == 0) {
        return "solution doesn't exist";
    }
    
    let inv_A = e/determinant;
    let inv_B = -b/determinant;
    let inv_C = -d/determinant;
    let inv_D = a/determinant;

    let x_sol = inv_A*(-c) + inv_B*(-f);
    let y_sol = inv_C*(-c) + inv_D*(-f);

    return `(${x_sol}, ${y_sol})`;
}
'use strict';

// The array of positive integers are given
// The array consists of same amount of even and odd numbers
// odd numbers should be sorted in ascending order
// even numbers should be sorted in descending order
// The resulted array should be an array start with an odd number and an even number
// Both should be evenly shuffled

const test_case = [4, 1, 3, 2, 6, 5];

test_case.sort(function(a, b) {
    return a - b;
});

let even_numbers = [];
let odd_numbers = [];

test_case.forEach((element) => {
    if (element % 2 == 0) {
        even_numbers.push(element);
    } else {
        odd_numbers.push(element);
    }
})

even_numbers = even_numbers.reverse();

const answer = [];
for (let i = 0; i < even_numbers.length; i++) {
    answer.push(odd_numbers[i]);
    answer.push(even_numbers[i]);
}

console.log(answer);

// for the test case, the answer is [1, 6, 3, 4, 5, 2]
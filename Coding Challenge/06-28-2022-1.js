'use strict';

// Test cases
let testCases = ["apple", "play", "moon", "$how"];

let keyboard =
    [["a","b","c","d","e","f"],
    ["g","o","i","j","k","l"],
    ["m","n","o","p","q","r"],
    ["s","t","u","v","w","x"],
    ["y","z","f","b","c","d"],
    ["j","i","h","v","f","e"]];

let foundLetterAndPositions = [];
let letterAndPositionsInOrder = [];
let noOfLetter = [];
let letterIndex = [];

let distances = [];

console.log(a)


function solution(word) {
    let fixedPositions = Array(5).fill(0).map(x => Array(2).fill(-1));

    findLettersInKeyboard(word);
    letterOrdering(word, foundLetterAndPositions);
    letterIndexing(noOfLetter);

    console.log(letterAndPositionsInOrder);
    console.log(letterIndex);

    fixPosition();

}

function findLettersInKeyboard(word) {
    let maxRow = keyboard.length;
    let maxCol = keyboard[0].length;

    for (let row = 0; row < maxRow; row++) {
        for (let col = 0; col < maxCol; col++) {
            for (let i = 0; i < word.length; i++)
                if (keyboard[row][col] == word[i]) {
                    foundLetterAndPositions.push([word[i], row, col]);
                }
        }
    }
}

function letterOrdering(word, fLAP) {
    let rowMax = fLAP.length;
    for (let i = 0; i < word.length; i++) {
        let count = 0;
        for (let row = 0; row < rowMax; row++) {
            if (word[i] == fLAP[row][0]) {
                count++;
                letterAndPositionsInOrder.push(fLAP[row]);
            }
        }
        noOfLetter.push(count);
    }
}

function letterIndexing(noOfLetter) {
    let temp = 0;
    noOfLetter.forEach((no) => {
        temp += no;
        letterIndex.push(temp);
    })
}

function fixposition() {
    // TODO: implementation of fixposition
}

let word = testCases[0];
solution(word);

/*
// Test cases excution
testCases.forEach((word) => {
    let temp = [];
    let output = solution(word);
    console.log(output);
})
*/
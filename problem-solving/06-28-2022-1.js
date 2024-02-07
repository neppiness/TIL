'use strict';

// Test cases
let testCases = ["ak", "apple", "play", "moon", "$how"];

let keyboard =
    [["a","b","c","d","e","f"],
    ["g","o","i","j","k","l"],
    ["m","n","o","p","q","r"],
    ["s","t","u","v","w","x"],
    ["y","z","f","b","c","d"],
    ["j","i","h","v","f","e"]];

let foundLetterAndPositions = [];
let lettersAndPositionsInOrder = [];

let noOfLetter = [];

function solution(word) {
    findLettersInKeyboard(word);
    letterOrdering(word, foundLetterAndPositions);

    let noOfDistances = calcNoOfDistances();
    let slicedPositions = sliceLettersAndPositions();
    let totalDistance = distancesCalc(slicedPositions);
    let result = [totalDistance, noOfDistances];

    return result; 
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
                lettersAndPositionsInOrder.push(fLAP[row]);
            }
        }
        noOfLetter.push(count);
    }
}

function calcNoOfDistances() {
    let noOfDistances = word.length;

    noOfLetter.forEach(number => {
        if (number == 0) {
            noOfDistances -= 1;
        }
    })

    return noOfDistances;
}

function sliceLettersAndPositions() {
    let result = [];
    let index = 0;

    noOfLetter.forEach(increment => {
        let temp = [];
        let indexLimit = index + increment;
        for (; index < indexLimit; index++) {
            temp.push(lettersAndPositionsInOrder[index].slice(1));
        }
        result.push(temp);
    })

    return result;
}

function distancesCalc(slicedPositions) {
    let len = word.length;
    let distance = 0;


    let determinedPositions = determinePositions(slicedPositions);

    for (let i = 1; i < len; i++) {
        let wordPosition1 = determinedPositions[i-1];
        let wordPosition2 = determinedPositions[i];

        if(wordPosition1 == false) {
            i = i + 1;
            distance += 20;
        } else if(wordPosition2 == []) {
            i = i + 2;
            distance += 20;
        } else {
            let increment = calcDistances(wordPosition1, wordPosition2);
            distance += increment;
        }
    }
    return distance;
}

function calcDistances(a, b) {
    let inc_x = Math.abs(a[0] - b[0]);
    let inc_y = Math.abs(a[1] - b[1]);

    return inc_x + inc_y;
}

function determinePositions(slicedPositions) {
    let determinedPositions = [];

    slicedPositions.forEach(positions => {
        if (positions.length == 0) {
            determinedPositions.push([]);
        } else if (positions.length == 1) {
            determinedPositions.push(positions[0]);
        } else {
            let minIndex = compareDistances(determinedPositions, positions);
            determinedPositions.push(positions[minIndex]);
        }
    })

    return determinedPositions;
}

function compareDistances(determinedPositions, positions) {
    let index = 0;
    let minIndex = 0;
    let positionA = determinedPositions.slice(-1);

    positions.forEach(positionB => {
        let min = 30;
        let dist = calcDistances(positionA, positionB);
        if (dist <= min) {
            minIndex = index;
        }
        index ++;
    });
    return minIndex;
}

let word = testCases[4];
let result = solution(word);
console.log(result);

/*
// Test cases excution
testCases.forEach((word) => {
    let temp = [];
    let output = solution(word);
    console.log(output);
})
*/
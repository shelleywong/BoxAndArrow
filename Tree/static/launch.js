// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// file: Tree/static/launch.js 

// Generate a formatted array of random integers 
// The user chooses the size of the array
document.querySelector('.randomarray')
.addEventListener('click', function() {
    var inputArray = [];
    var range = 101; // Range of 101 numbers
    var half = 50; // Subtract half the range to get pos & neg values
    var size = prompt('How many elements would you like in your array?');

    inputArray = Array.from(
        {length: size}, () => Math.floor(Math.random() * (range)) - half);

    //Print the array in the console.
    console.log(inputArray);
    document.getElementById("arrayvals").innerHTML = inputArray;
});

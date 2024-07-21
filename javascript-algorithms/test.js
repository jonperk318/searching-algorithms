const linearSearch = require("./linear-search.js");
const binarySearch = require("./binary-search.js");
const ternarySearch = require("./ternary-search.js");

let testArr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 30234]

console.log("Test array:\t", ...testArr);

console.log("\nLinear search key of 0 (not present):\t\t", linearSearch(testArr, 0));
console.log("Linear search key of 1 (1st element):\t\t", linearSearch(testArr, 1));
console.log("Linear search key of 30234 (9th element):\t", linearSearch(testArr, 30234));

console.log("\nBinary search key of 0 (not present):\t\t", binarySearch(testArr, 0));
console.log("Binary search key of 1 (1st element):\t\t", binarySearch(testArr, 1));
console.log("Binary search key of 30234 (9th element):\t", binarySearch(testArr, 30234));

console.log("\nTernary search key of 0 (not present):\t\t", ternarySearch(testArr, 0));
console.log("Ternary search key of 1 (1st element):\t\t", ternarySearch(testArr, 1));
console.log("Ternary search key of 30234 (9th element):\t", ternarySearch(testArr, 30234));
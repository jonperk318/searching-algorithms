const linearSearch = require("./linear-search.js");
const binarySearch = require("./binary-search.js");
const ternarySearch = require("./ternary-search.js");
const fs = require("fs");

// get sizes of sample arrays
let sampleSizesText = fs.readFileSync("../samples/sample-sizes.txt", "utf-8");
let sampleSizesStrings = sampleSizesText.split(",");
sampleSizesText.close;
let sampleSizes = sampleSizesStrings.map(Number);

// create array of arrays of input samples
let samples = [];
function getSamples(size) {
    let file = fs.readFileSync("../samples/" + String(size) + ".txt", "utf-8");
    let sampleString = file.split(",");
    file.close;
    let sample = sampleString.map(Number);
    samples.push(sample);
}
sampleSizes.forEach(getSamples);

// get array of random ints
let randomIntText = fs.readFileSync("../samples/random-ints.txt", "utf-8");
let randomIntStrings = randomIntText.split(",");
randomIntText.close;
let randomInts = randomIntStrings.map(Number);

let linearTimes1 = [], linearTimes2 = [], linearTimes3 = [], binaryTimes1 = [], binaryTimes2 = [],
    binaryTimes3 = [], ternaryTimes1 = [], ternaryTimes2 = [], ternaryTimes3 = [];

// RUN ALL SORTING FUNCTIONS
for (let i = 0; i < samples.length; i++) {

    let randomInt = randomInts[i];
    let notPresentInt = 1000001;

    // Linear search with random key
    let tick = process.hrtime();
    linearSearch(samples[i], randomInt);
    let tock = process.hrtime(tick);
    linearTimes1.push(tock[0] + tock[1]/1000000000);

    // Linear search with key equal to first element in array
    tick = process.hrtime();
    linearSearch(samples[i], samples[i][0]);
    tock = process.hrtime(tick);
    linearTimes2.push(tock[0] + tock[1]/1000000000);

    // Linear search with key not present in array
    tick = process.hrtime();
    linearSearch(samples[i], notPresentInt);
    tock = process.hrtime(tick);
    linearTimes3.push(tock[0] + tock[1]/1000000000);

    // Binary search with random key
    tick = process.hrtime();
    binarySearch(samples[i], randomInt);
    tock = process.hrtime(tick);
    binaryTimes1.push(tock[0] + tock[1]/1000000000);

    // Binary search with key equal to first element in array
    tick = process.hrtime();
    binarySearch(samples[i], samples[i][0]);
    tock = process.hrtime(tick);
    binaryTimes2.push(tock[0] + tock[1]/1000000000);

    // Binary search with key not present in array
    tick = process.hrtime();
    binarySearch(samples[i], notPresentInt);
    tock = process.hrtime(tick);
    binaryTimes3.push(tock[0] + tock[1]/1000000000);

    // Ternary search with random key
    tick = process.hrtime();
    ternarySearch(samples[i], randomInt);
    tock = process.hrtime(tick);
    ternaryTimes1.push(tock[0] + tock[1]/1000000000);

    // Ternary search with key equal to first element in array
    tick = process.hrtime();
    ternarySearch(samples[i], samples[i][0]);
    tock = process.hrtime(tick);
    ternaryTimes2.push(tock[0] + tock[1]/1000000000);

    // Ternary search with key not present in array
    tick = process.hrtime();
    ternarySearch(samples[i], notPresentInt);
    tock = process.hrtime(tick);
    ternaryTimes3.push(tock[0] + tock[1]/1000000000);

    console.log("Searched array of length " + sampleSizes[i]);
}

// write searching times to separate files
let searchingTimes = [linearTimes1, linearTimes2, linearTimes3, binaryTimes1,
    binaryTimes2, binaryTimes3, ternaryTimes1, ternaryTimes2, ternaryTimes3];
let searchingNames = ["linear-times-1", "linear-times-2", "linear-times-3", "binary-times-1",
    "binary-times-2", "binary-times-3", "ternary-times-1", "ternary-times-2", "ternary-times-3"];
let timeString;

for (let i = 0; i < searchingTimes.length; i++) {

    timeString = searchingTimes[i].join(",");

    fs.writeFile("./javascript-searching-times/javascript-" + searchingNames[i] + ".txt", timeString,
        err => {
            if (err) {
                console.error(err);
            } else {
                // file written successfully
            }
        });

}
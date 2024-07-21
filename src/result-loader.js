/*
* Convert output searching times to arrays to load into the charts
* */

const fs = require("fs");

// get sizes of sample arrays
let sampleSizesText = fs.readFileSync("../samples/sample-sizes.txt", "utf-8");
let sampleSizesStrings = sampleSizesText.split(",");
sampleSizesText.close;
let sampleSizes = sampleSizesStrings.map(Number);

let searchingNames = ["linear-times-1", "linear-times-2", "linear-times-3", "binary-times-1",
    "binary-times-2", "binary-times-3", "ternary-times-1", "ternary-times-2", "ternary-times-3"];

pythonTimes = [];
javaTimes = [];
cppTimes = [];
javaScriptTimes = [];

for (let i = 0; i < searchingNames.length; i++) { // reading times into arrays

    // Python searching times
    let pythonTimesString = fs.readFileSync("../python-algorithms/python-searching-times/python-" +
        searchingNames[i] + ".txt", "utf-8");
    let pythonTimesStrings = pythonTimesString.split(",");
    pythonTimesString.close;
    let pythonTimesNumbers = pythonTimesStrings.map(Number);
    pythonTimes.push(pythonTimesNumbers);

    // Java searching times
    let javaTimesString = fs.readFileSync("../java-algorithms/java-searching-times/java-" +
        searchingNames[i] + ".txt", "utf-8");
    let javaTimesStrings = javaTimesString.split(",");
    javaTimesString.close;
    let javaTimesNumbers = javaTimesStrings.map(Number);
    javaTimes.push(javaTimesNumbers);

    // C++ searching times
    let cppTimesString = fs.readFileSync("../cpp-algorithms/cpp-searching-times/cpp-" +
        searchingNames[i] + ".txt", "utf-8");
    let cppTimesStrings = cppTimesString.split(",");
    cppTimesString.close;
    let cppTimesNumbers = cppTimesStrings.map(Number);
    cppTimes.push(cppTimesNumbers);

    // JavaScript searching times
    let javaScriptTimesString = fs.readFileSync("../javascript-algorithms/javascript-searching-times/javascript-" +
        searchingNames[i] + ".txt", "utf-8");
    let javaScriptTimesStrings = javaScriptTimesString.split(",");
    javaScriptTimesString.close;
    let javaScriptTimesNumbers = javaScriptTimesStrings.map(Number);
    javaScriptTimes.push(javaScriptTimesNumbers);

}

let resultsArr = []; // array to be written to results.js
let times = [pythonTimes, javaTimes, cppTimes, javaScriptTimes];
let languageNames = ["Searching in Python", "Searching in Java", "Searching in C++", "Searching in JavaScript"];
let languageNamesCC = ["python", "java", "cpp", "javaScript"];
let searchingNamesDisplay = ["Linear Search with Random Key", "Linear Search for First Element",
    "Linear Search with Key Not Found", "Binary Search with Random Key", "Binary Search for First Element",
    "Binary Search with Key Not Found", "Ternary Search with Random Key", "Ternary Search for First Element",
    "Ternary Search with Key Not Found"];


// First, add searching function times for each language

for (let i = 0; i < languageNames.length; i++) { // 4 languages

    let results = [];

    for (let j = 0; j < sampleSizes.length; j++) { // 50 samples

        let resultsPerSampleSize = {};

        for (let k = 0; k < searchingNamesDisplay.length; k++) { // 3 searching functions, 3 trials each

            resultsPerSampleSize[searchingNamesDisplay[k]] = times[i][k][j];

        }
        results.push({"array":sampleSizes[j], "methods":resultsPerSampleSize});

    }
    resultsArr.push({"name":languageNames[i],"results":results})

}

// Second, add language searching speeds for each searching method

for (let i = 0; i < searchingNamesDisplay.length; i++) { // 3 searching functions, 3 trials each

    let results = [];

    for (let j = 0; j < sampleSizes.length; j++) { // 50 samples

        let resultsPerSampleSize = {};

        for (let k = 0; k < languageNamesCC.length; k++) { // 4 languages

            resultsPerSampleSize[languageNamesCC[k]] = times[k][i][j];

        }
        results.push({"array":sampleSizes[j], "methods":resultsPerSampleSize});

    }
    resultsArr.push({"name":searchingNamesDisplay[i],"results":results})

}

let args = process.argv.slice(2);
let resultsFilePath = args[0] || "../dist/results.js";

/**
 * Save generated results as results.js
 *
 * @param results
 */
const saveResults = function(results) {

    console.log("Saving results...");
    const source = "window.results=" + JSON.stringify(results);

    fs.writeFile(resultsFilePath, source, (err) => {
        if(err) {
            return console.log(err);
        }
        console.log("Done!");
    });
};

saveResults(resultsArr);
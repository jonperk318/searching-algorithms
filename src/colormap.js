/**
 * Map sort method name to fixed color
 *
 * @param sortName sort name
 * @returns {string} color
 */
function getColor(sortName) {
    var colors = {
        "Linear Search with Random Key": "#EFCA00",
        "Linear Search for First Element": "#FE433C",
        "Linear Search with Key Not Found": "#F31D64",
        "Binary Search with Random Key": "#A224AD",
        "Binary Search for First Element": "#6A38B3",
        "Binary Search with Key Not Found": "#3C5081",
        "Ternary Search with Random Key": "#0095EF",
        "Ternary Search for First Element": "#43C68B",
        "Ternary Search with Key Not Found": "#4A495A",

        python: "#3572a5",
        java: "#b07219",
        cpp: "#f34b7d",
        javaScript: "#f1e05a",

        other: "#BCBCBC"
    };

    var color = colors[sortName];

    return color ? color : colors["other"];
}

module.exports.getColor = getColor;
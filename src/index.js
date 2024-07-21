var Chart = require("./sorting-chart");
var Menu = require("./section-menu");

Menu.renderMenu();
var sortChart = Chart.renderChart();

window.addEventListener("hashchange", function() {
    Menu.renderMenu();
    Chart.updateChart(sortChart);
});
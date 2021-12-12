
src="//cdn.jsdelivr.net/terra/latest/mainfile";
//Rows Columns for Display

//const r =1000;
//const c = 1000;
//var genCounter = 0;
//var genTot = 500;

//using test data
const r = 10;
const c = 10;
var genCounter=0;
var genTot = 5;

//Arrays recording number of each type each gen.
var susArray = [];
var infectArray = [];
var deadArray = [];
var recoveredArray = [];

var generationArray = [];

//Array for Display of Simulation
var rowArray = [];

//Incrementing counters
var susCount= 0;
var infectCount= 0;
var deadCount= 0;
var recoveredCount= 0;

// read in the file
//takes in the values of text.txt and splits them into differect generations using the '.' as an indicator, they are then saved to the generations array
function load_file()
{
    var lineReader = require('line-reader');

    lineReader.eachLine('text.txt', function(line, last) {

        let generations = line.split(".");
        for (i = 0; i< generations.length;i++) {
            for (j = 0; j < generations[j].length; j++) {
                var line =generations[j];
                //loops through each gen, then each letter in each gen. For now it prints it to the console
                for (var i = 0; i< generations.length;i++) {
                    for (var j = 0; j < generations[j].length; j++) {
                        var line =generations[j];

                        console.log(line.charAt(j));

                    }
                }
            }
        }

        console.log(generations[1]);
        console.log(generations[2]);
        console.log(generations[3]);
        console.log(generations[4]);
        console.log(generations[8]);

    });


}

// draw the grid
function draw() {

}

function change(){

}

    document.getElementById('text.txt').addEventListener('change', function() {
        var fr=new FileReader();
        fr.onload=function(){
            document.getElementById('output').textContent=fr.result; }
        fr.readAsText(this.files[0]);})

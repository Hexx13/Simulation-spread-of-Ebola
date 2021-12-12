
src="//cdn.jsdelivr.net/terra/latest/mainfile";
//Rows Columns for Display

//const r =1000;
//const c = 1000;
//let genCounter = 0;
//let genTot = 500;

//using test data
const r = 10;
const c = 10;
let genCounter=0;
let genTot = 5;

//Arrays recording number of each type each gen.
let susArray = [];
let infectArray = [];
let deadArray = [];
let recoveredArray = [];

let generationArray = [];

//Array for Display of Simulation
let rowArray = [];

//Incrementing counters
let susCount= 0;
let infectCount= 0;
let deadCount= 0;
let recoveredCount= 0;

let generations;
let gridArray;
let lineReader = require('line-reader');

// read in the file
//takes in the values of text.txt and splits them into differect generations using the '.' as an indicator, they are then saved to the generations array
function load_file()
{


    lineReader.eachLine('text.txt', function(line, last) {
       generations = line.split(".");
    });

    for (let i = 0; i< generations.length;i++) {

        let rowcol = Math.sqrt(generations[i].length);
        console.log(generations[i].length);
        console.log(rowcol);


        for (let j = 0; j < generations[j].length; j++) {

            let line =generations[j];
            // console.log(line.charAt(j));
        }


        for(let j = 0; j < rowcol; j++ ){

            for(let i = 0; i < rowcol; i++ ){
                gridArray[j][i] = generations[i].charAt(i);

            }
        }
    }

    t.grid = t.makeGrid(gridArray);

}

function createDrawGrid( ){


}

// draw the grid
function draw() {

}

function change(){

}

    document.getElementById('text.txt').addEventListener('change', function() {
        let fr=new FileReader();
        fr.onload=function(){
            document.getElementById('output').textContent=fr.result; }
        fr.readAsText(this.files[0]);})


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
function load_file()
{
    let $get;
    $get.load(text.txt, function(data){
        let output = data;
        let generations = output.split(".");
        console.log(generations)
    })
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

var currentShape;
var currentTransformation;
var myRect, myTri, myLine, myCir, myPoly;

var canvas = document.getElementById("canvas")
var context = canvas.getContext("2d");
var mouseMovement = {};
var canvas_mouse_obj = {};
var save_image_data = null;
var drag = null

var shape = [];
var xPosNow, yPosNow, radiusNow, colorNow, numSideNow, widthNow, heightNow;

var windowToCanvas = function(x1 , y1){
    var left = canvas.getBoundingClientRect().left;
    var top = canvas.getBoundingClientRect().top;
    return{
        x:x1 - left,
        y:y1 - top
    }
}

var saveCurrentImage = function() {
    save_image_data = context.getImageData(0, 0, canvas.width, canvas.height)
}

var putCurrentImage = function() {
    context.putImageData(save_image_data, 0, 0)
    context.clearRect(0, 0, canvas.width, canvas.height);
}

canvas.onmousedown = function(e) {
    var mousedown_left = e.clientX;
    var mousedown_top = e.clientY;
    saveCurrentImage()
    canvas_mouse_obj = windowToCanvas(mousedown_left, mousedown_top)
    drag=true;
}

canvas.onmousemove = function(e) {
    if (drag) {
        putCurrentImage();
        mouseMovement = windowToCanvas(e.clientX, e.clientY);
        context.beginPath();
        context.moveTo(canvas_mouse_obj.x, canvas_mouse_obj.y);
        context.lineTo(mouseMovement.x, mouseMovement.y);
        context.strokeStyle="black"; context.fillStyle="black";
        context.stroke();
    }
}

canvas.onmouseup = function(e) {
    var endx = e.clientX;
    var endy = e.clientY;
    var end = windowToCanvas(endx, endy);
    var xPos_square = Math.abs(mouseMovement.x - canvas_mouse_obj.x);
    var yPos_square = Math.abs(mouseMovement.y - canvas_mouse_obj.y);
    var num_length= Math.sqrt(xPos_square * xPos_square + yPos_square * yPos_square);  //distance formula
    var radius = num_length / 2.0;
    var midPointX = (mouseMovement.x + canvas_mouse_obj.x) / 2;
    var midPointY = (mouseMovement.y + canvas_mouse_obj.y) / 2;
    var numberOfSides;
    var size;
    var Xcenter = midPointX;
    var Ycenter = midPointY;

    if (currentShape === 1) {   // rectangle
        context.beginPath();
        context.moveTo(canvas_mouse_obj.x, canvas_mouse_obj.y);
        context.lineTo(end.x, end.y);
        context.stroke();
        context.beginPath();
        context.rect(canvas_mouse_obj.x, canvas_mouse_obj.y, end.x-canvas_mouse_obj.x, end.y-canvas_mouse_obj.y);
        context.fill();
        myRect = context;
        shape.push({numSideNow:4, xPosNow: canvas_mouse_obj.x, yPosNow:canvas_mouse_obj.y, widthNow:end.x - canvas_mouse_obj.x, heightNow:end.y-canvas_mouse_obj.y, colorNow: "black"});
        drag = false;
    } else if (currentShape === 2) {    // circle
        context.beginPath()
        context.moveTo(canvas_mouse_obj.x, canvas_mouse_obj.y)
        context.lineTo(end.x, end.y)
        context.stroke()
        context.beginPath();
        context.arc(midPointX, midPointY, radius,0, 2*Math.PI)
        context.fill()
        drag=false;
    } else if (currentShape === 3) {    // line
        context.beginPath();
        context.moveTo(canvas_mouse_obj.x, canvas_mouse_obj.y);
        context.lineTo(end.x, end.y);
        context.stroke();
        context.beginPath();
        drag = false;
    } else if (currentShape === 4) {    // triangle
        numberOfSides = 3;
        size = num_length;
        context.beginPath();
        context.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
        for (var i = 1; i <= numberOfSides;i += 1) {
            context.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
        }
        context.stroke();
        context.fill();
        drag=false;
    } else if (currentShape === 5) {    // polygon
        numberOfSides = 6;
        size = num_length / 1.72;
        context.beginPath();
        context.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
        for (var i = 1; i <= numberOfSides;i += 1) {
            context.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
        }
        context.stroke();
        context.fill();
        drag=false;
    }

}

// Draw Shape
function drawRectangle() {
    currentShape = 1;
}

function drawCircle() {
    currentShape = 2;
}

function drawLine() {
    currentShape = 3;
}

function drawTriangle() {
    currentShape = 4;
}

function drawPolygon() {
    currentShape = 5;
}

function clearShape() {
    context.clearRect(0, 0, canvas.width, canvas.height);
}

// Transformation Functions
// function scaleShape() {
//     currentTransformation = "a";
//     // context.scale(2,2);
// }
//
// function rotateShape() {
//     currentTransformation = "b";
//     // context.rotate(45 * Math.PI / 180);
//     // context.fillRect(canvas_mouse_obj.x, canvas_mouse_obj.y, end.x-canvas_mouse_obj.x, end.y-canvas_mouse_obj.y);
// }
//
// function translateShape() {
//     currentTransformation = "c";
// }
//
// function clearTransformation() {
//     currentTransformation = "d";
// }



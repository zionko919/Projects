"use strict";

var canvas, gl, program;

var NumVertices = 36; //(6 faces)(2 triangles/face)(3 vertices/triangle)

var points = [];
var colors = [];

var vertices = [
    vec4( -0.5, -0.5,  0.5, 1.0 ),
    vec4( -0.5,  0.5,  0.5, 1.0 ),
    vec4(  0.5,  0.5,  0.5, 1.0 ),
    vec4(  0.5, -0.5,  0.5, 1.0 ),
    vec4( -0.5, -0.5, -0.5, 1.0 ),
    vec4( -0.5,  0.5, -0.5, 1.0 ),
    vec4(  0.5,  0.5, -0.5, 1.0 ),
    vec4(  0.5, -0.5, -0.5, 1.0 ),
];

// RGBA colors
var vertexColors = [
    vec4( 1.0, 1.0, 1.0, 1.0 ),  // white
    vec4( 1.0, 0.0, 0.0, 1.0 ),  // red
    vec4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    vec4( 0.0, 1.0, 0.0, 1.0 ),  // green
    vec4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    vec4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    vec4( 0.0, 0.0, 0.0, 1.0 ),  // black
    vec4( 0.0, 1.0, 1.0, 1.0 )   // cyan
];


// Parameters controlling the size of the Robot's arm

var BASE_HEIGHT      = 1.5;
var BASE_WIDTH       = 4.0;
var JOINT_1_HEIGHT   = 0.5;
var JOINT_1_WIDTH    = 0.5;
var LOWER_ARM_HEIGHT = 2.0;
var LOWER_ARM_WIDTH  = 0.5;
var UPPER_ARM_HEIGHT = 2.0;
var UPPER_ARM_WIDTH  = 0.5;
var HAND_HEIGHT = 1.0;
var HAND_WIDTH  = 1.0;
var FINGER_1_HEIGHT  = 1.0;
var FINGER_1_WIDTH   = 0.2;
var FINGER_2_HEIGHT  = 1.0;
var FINGER_2_WIDTH   = 0.2;
var FINGER_3_HEIGHT  = 1.0;
var FINGER_3_WIDTH   = 0.2;


// Shader transformation matrices

var modelViewMatrix, projectionMatrix;

// Array of rotation angles (in degrees) for each rotation axis

var Base = 0;
var LowerArm = 1;
var UpperArm = 2;
var Finger_1 = 3;
var Finger_2 = 4;
var Finger_3 = 5;
var Hand = 6;


var theta = [ 0, 0, 0, 0, 0, 0, 0];
var gamma = [ 0, 0, 0, 0, 0, 0, 0];
var alpha = [ 0, 0, 0, 0, 0, 0, 0];

var angle = 0;

var modelViewMatrixLoc;

var vBuffer, cBuffer;

//----------------------------------------------------------------------------

function quad(  a,  b,  c,  d ) {
    colors.push(vertexColors[a]);
    points.push(vertices[a]);
    colors.push(vertexColors[a]);
    points.push(vertices[b]);
    colors.push(vertexColors[a]);
    points.push(vertices[c]);
    colors.push(vertexColors[a]);
    points.push(vertices[a]);
    colors.push(vertexColors[a]);
    points.push(vertices[c]);
    colors.push(vertexColors[a]);
    points.push(vertices[d]);
}


function colorCube() {
    quad( 1, 0, 3, 2 );
    quad( 2, 3, 7, 6 );
    quad( 3, 0, 4, 7 );
    quad( 6, 5, 1, 2 );
    quad( 4, 5, 6, 7 );
    quad( 5, 4, 0, 1 );
}

//____________________________________________

// Remmove when scale in MV.js supports scale matrices

function scale4(a, b, c) {
   var result = mat4();
   result[0][0] = a;
   result[1][1] = b;
   result[2][2] = c;
   return result;
}


//--------------------------------------------------


window.onload = function init() {

    canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    gl.viewport( 0, 0, canvas.width, canvas.height );

    gl.clearColor( 1.0, 1.0, 1.0, 1.0 );
    gl.enable( gl.DEPTH_TEST );

    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders( gl, "vertex-shader", "fragment-shader" );

    gl.useProgram( program );

    colorCube();

    // Load shaders and use the resulting shader program

    program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );

    // Create and initialize  buffer objects

    vBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points), gl.STATIC_DRAW );


    var vPosition = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition );

    cBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, cBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(colors), gl.STATIC_DRAW );

    var vColor = gl.getAttribLocation( program, "vColor" );
    gl.vertexAttribPointer( vColor, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vColor );

    modelViewMatrixLoc = gl.getUniformLocation(program, "modelViewMatrix");

    projectionMatrix = ortho(-10, 10, -10, 10, -10, 10);
    gl.uniformMatrix4fv( gl.getUniformLocation(program, "projectionMatrix"),  false, flatten(projectionMatrix) );

    document.getElementById("slider1").oninput = function(event) {
        theta[0] = event.target.value;
    };
    document.getElementById("slider1b").oninput = function(event) {
        gamma[0] = event.target.value;
    };
    document.getElementById("slider1c").oninput = function(event) {
        alpha[0] = event.target.value;
    };

    document.getElementById("slider2").oninput = function(event) {
         theta[1] = event.target.value;
    };
    document.getElementById("slider2b").oninput = function(event) {
        gamma[1] = event.target.value;
    };
    document.getElementById("slider2c").oninput = function(event) {
        alpha[1] = event.target.value;
    };

    document.getElementById("slider3").oninput = function(event) {
         theta[2] =  event.target.value;
    };
    document.getElementById("slider3b").oninput = function(event) {
        gamma[2] =  event.target.value;
    };
    document.getElementById("slider3c").oninput = function(event) {
        alpha[2] =  event.target.value;
    };

    document.getElementById("slider4").oninput = function(event) {
        theta[3] =  event.target.value;
    };
    document.getElementById("slider4b").oninput = function(event) {
        gamma[3] =  event.target.value;
    };
    document.getElementById("slider4c").oninput = function(event) {
        alpha[3] =  event.target.value;
    };

    document.getElementById("slider5").oninput = function(event) {
        theta[4] =  event.target.value;
    };
    document.getElementById("slider5b").oninput = function(event) {
        gamma[4] =  event.target.value;
    };
    document.getElementById("slider5c").oninput = function(event) {
        alpha[4] =  event.target.value;
    };

    document.getElementById("slider6").oninput = function(event) {
        theta[5] =  event.target.value;
    };
    document.getElementById("slider6b").oninput = function(event) {
        gamma[5] =  event.target.value;
    };
    document.getElementById("slider6c").oninput = function(event) {
        alpha[5] =  event.target.value;
    };



    render();
}

//----------------------------------------------------------------------------

function base() {
    var s = scale4(BASE_WIDTH, BASE_HEIGHT, BASE_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * BASE_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv(modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------

function joint1() {
    var s = scale4(JOINT_1_WIDTH, JOINT_1_HEIGHT, JOINT_1_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * JOINT_1_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv(modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------

function lowerArm()
{
    var s = scale4(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * LOWER_ARM_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv( modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------


function upperArm() {
    var s = scale4(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
    var instanceMatrix = mult(translate( 0.0, 0.5 * UPPER_ARM_HEIGHT, 0.0 ),s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv( modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------

function hand() {
    var s = scale4(HAND_WIDTH, HAND_HEIGHT, HAND_WIDTH);
    var instanceMatrix = mult(translate( 0.0, 0.5 * HAND_HEIGHT, 0.0 ),s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv( modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------

function finger_1() {
    var s = scale4(FINGER_1_WIDTH, FINGER_1_HEIGHT, FINGER_1_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * FINGER_1_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv(modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------
function finger_2() {
    var s = scale4(FINGER_2_WIDTH, FINGER_2_HEIGHT, FINGER_2_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * FINGER_2_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv(modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------
function finger_3() {
    var s = scale4(FINGER_3_WIDTH, FINGER_3_HEIGHT, FINGER_3_WIDTH);
    var instanceMatrix = mult( translate( 0.0, 0.5 * FINGER_3_HEIGHT, 0.0 ), s);
    var t = mult(modelViewMatrix, instanceMatrix);
    gl.uniformMatrix4fv(modelViewMatrixLoc,  false, flatten(t) );
    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
}

//----------------------------------------------------------------------------



var render = function() {
    let stack = [];


    gl.clear( gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT );



    modelViewMatrix = rotate(theta[Base], 0, 1, 0 );
    modelViewMatrix = mult(modelViewMatrix,rotate(gamma[Base], 0, 0, 1 ));
    modelViewMatrix = mult(modelViewMatrix,rotate(alpha[Base], 1, 0, 0 ));
    base();

    modelViewMatrix = mult(modelViewMatrix, translate(0.0, BASE_HEIGHT, 0.0));
    joint1();

    modelViewMatrix = mult(modelViewMatrix, translate(0.0, JOINT_1_HEIGHT, 0.0));
    modelViewMatrix = mult(modelViewMatrix, rotate(theta[LowerArm], 0, 0, 1 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(gamma[LowerArm], 0, 1, 0 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(alpha[LowerArm], 1, 0, 0 ));
    lowerArm();


    modelViewMatrix  = mult(modelViewMatrix, translate(0.0, LOWER_ARM_HEIGHT, 0.0));
    modelViewMatrix  = mult(modelViewMatrix, rotate(theta[UpperArm], 0, 0, 1) );
    modelViewMatrix  = mult(modelViewMatrix, rotate(gamma[UpperArm], 0, 1, 0) );
    modelViewMatrix  = mult(modelViewMatrix, rotate(alpha[UpperArm], 1, 0, 0) );
    upperArm();

    modelViewMatrix  = mult(modelViewMatrix, translate(0.0, UPPER_ARM_HEIGHT, 0.0));
    modelViewMatrix  = mult(modelViewMatrix, rotate(theta[Hand], 0, 0, 1) );
    modelViewMatrix  = mult(modelViewMatrix, rotate(gamma[Hand], 0, 1, 0) );
    modelViewMatrix  = mult(modelViewMatrix, rotate(alpha[Hand], 1, 0, 0) );

    hand();

    stack.push(modelViewMatrix);

    modelViewMatrix = mult(modelViewMatrix, translate(0.4, HAND_HEIGHT, 0.0));
    modelViewMatrix = mult(modelViewMatrix, rotate(theta[Finger_1], 0, 0, 1 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(gamma[Finger_1], 0, 1, 0 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(alpha[Finger_1], 1, 0, 0 ));
    finger_1();

    modelViewMatrix = stack.pop();
    stack.push(modelViewMatrix);

    modelViewMatrix = mult(modelViewMatrix, translate(-0.4, HAND_HEIGHT, 0.4));
    modelViewMatrix = mult(modelViewMatrix, rotate(theta[Finger_2], 0, 0, 1 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(gamma[Finger_2], 0, 1, 0 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(alpha[Finger_2], 1, 0, 0 ));
    finger_2();

    modelViewMatrix = stack.pop();

    stack.push(modelViewMatrix);
    modelViewMatrix = mult(modelViewMatrix, translate(-0.4, HAND_HEIGHT, -0.4));
    modelViewMatrix = mult(modelViewMatrix, rotate(theta[Finger_3], 0, 0, 1 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(gamma[Finger_3], 0, 1, 0 ));
    modelViewMatrix = mult(modelViewMatrix, rotate(alpha[Finger_3], 1, 0, 0 ));
    finger_3();

    requestAnimFrame(render);
}

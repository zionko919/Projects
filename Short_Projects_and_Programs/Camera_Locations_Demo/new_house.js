"use strict";

var canvas;
var gl;

var NumVertices  = 51;

var pointsArray = [];
var colorsArray = [];

var animation_flag = false;
var animation_speed = false;

var vertices = [
    vec4(0, 0, .30),
    vec4(.16, 0, .30),
    vec4(.16, .10, .30),
    vec4(.08, .16, .30),
    vec4(0, .10, .30),
    vec4(0, 0, .54),
    vec4(.16, 0, .54),
    vec4(.16, .10, .54),
    vec4(.08, .16, .54),
    vec4(0, .10, .54),
];

var vertexColors = [
    vec4( 1.0, 1.0, 1.0, 1.0 ),  // white
    vec4( 1.0, 0.0, 0.0, 1.0 ),  // red
    vec4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    vec4( 0.0, 1.0, 0.0, 1.0 ),  // green
    vec4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    vec4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    vec4( 0.0, 1.0, 1.0, 1.0 ),  // cyan
    vec4( 0.0, 0.0, 0.0, 1.0 ),  // black
];

var x1 = 0.0, y1 = 0.0, z1 = 0.0, x2 = 0.0, y2 = 0.0, z2 = 0.0;

var near = 0.3;
var far = 8.0;
var radius = 2.0;
var theta  = 0.0;
var phi    = 0.0;
var dr = 5.0 * Math.PI/180.0;

var  fovy = 45.0;  // Field-of-view in Y direction angle (in degrees)
var  aspect = 1.0;       // Viewport aspect ratio

var modelViewMatrix, projectionMatrix;
var modelViewMatrixLoc, projectionMatrixLoc;
var eye;
const at = vec3(0.0, 0.0, 0.0);
const up = vec3(0.0, 1.0, 0.0);



function quad(a, b, c, d, e) {
    pointsArray.push(vertices[a]);
    colorsArray.push(vertexColors[a]);
    pointsArray.push(vertices[b]);
    colorsArray.push(vertexColors[a]);
    pointsArray.push(vertices[c]);
    colorsArray.push(vertexColors[a]);
    pointsArray.push(vertices[a]);
    colorsArray.push(vertexColors[a]);
    pointsArray.push(vertices[c]);
    colorsArray.push(vertexColors[a]);
    pointsArray.push(vertices[d]);
    colorsArray.push(vertexColors[a]);
}

function colorCube()
{
    quad( 1, 2, 3, 4, 0);
    quad(1, 0, 4, 3, 2)
    quad( 3, 4, 9, 8);
    quad( 4, 0, 5, 9);
    quad( 5, 6, 1, 0);
    quad( 7, 2, 1, 6 );
    quad( 2, 7, 8, 3, );
    quad( 6, 5, 9, 8, 7);
    quad( 6, 7, 8, 9, 5);
}

document.getElementById("animate_button").onclick = () => {
    x1 = parseFloat(document.getElementById("x1").value);
    y1 = parseFloat(document.getElementById("y1").value);
    z1 = 0.0 - parseFloat(document.getElementById("z1").value);
    x2 = parseFloat(document.getElementById("x2").value);
    y2 = parseFloat(document.getElementById("y2").value);
    z2 = 0.0 - parseFloat(document.getElementById("z2").value);

    phi = x1;
    theta = y1;
    far = z1;

    animation_flag = true;
    animation_speed = false;
}

document.getElementById("animate_button2").onclick = () => {
    x1 = parseFloat(document.getElementById("x1").value);
    y1 = parseFloat(document.getElementById("y1").value);
    z1 = 0.0 - parseFloat(document.getElementById("z1").value);
    x2 = parseFloat(document.getElementById("x2").value);
    y2 = parseFloat(document.getElementById("y2").value);
    z2 = 0.0 - parseFloat(document.getElementById("z2").value);

    phi = x1;
    theta = y1;
    far = z1;

    animation_flag = true;
    animation_speed = true;
}

document.getElementById("fovSlider").onchange = function(event) {
    fovy = event.target.value;
};

window.onload = function init() {
    canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    gl.viewport( 0, 0, canvas.width, canvas.height );

    aspect =  canvas.width/canvas.height;

    gl.clearColor( 1.0, 1.0, 1.0, 1.0 );

    gl.enable(gl.DEPTH_TEST);

    //
    //  Load shaders and initialize attribute buffers
    //
    var program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );

    colorCube();

    var cBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, cBuffer);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(colorsArray), gl.STATIC_DRAW );

    var vColor = gl.getAttribLocation( program, "vColor" );
    gl.vertexAttribPointer( vColor, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vColor);

    var vBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(pointsArray), gl.STATIC_DRAW );

    var vPosition = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition );

    modelViewMatrixLoc = gl.getUniformLocation( program, "modelViewMatrix" );
    projectionMatrixLoc = gl.getUniformLocation( program, "projectionMatrix" );

    render();
}

const defineLine = () => {
    if (animation_speed === false) {
        if (phi > x2) {
            phi = parseFloat(phi.toPrecision(4)) - 0.002;
        }  if (phi < x2) {
            phi = parseFloat( phi.toPrecision(4)) + 0.002;
        }  if (phi === x2) {
            ;
        }

        if (theta > y2) {
            theta = parseFloat(theta.toPrecision(4)) - 0.002;
        } else if (theta  < y2) {
            theta = parseFloat(theta.toPrecision(4)) + 0.002;
        } else if (theta === y2) {
            ;
        }

        if (far > z2) {
            far = parseFloat(far.toPrecision(4)) - 0.002;

        } else if (far < z2) {
            far = parseFloat(far.toPrecision(4)) + 0.002;

        } else if (far === z2) {
            ;
        }
    } else if (animation_speed === true) {
        if (phi > x2) {
            phi = parseFloat(phi.toPrecision(3)) - 0.01;
        }  if (phi < x2) {
            phi = parseFloat( phi.toPrecision(3)) + 0.01;
        }  if (phi === x2) {
            ;
        }

        if (theta > y2) {
            theta = parseFloat(theta.toPrecision(3)) - 0.01;
        } else if (theta  < y2) {
            theta = parseFloat(theta.toPrecision(3)) + 0.01;
        } else if (theta === y2) {
            ;
        }

        if (far > z2) {
            far = parseFloat(far.toPrecision(3)) - 0.01;

        } else if (far < z2) {
            far = parseFloat(far.toPrecision(3)) + 0.01;

        } else if (far === z2) {
            ;
        }
    }
}

var render = function(){
    if (animation_flag) {
        defineLine();
    }

    gl.clear( gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    eye = vec3(radius*Math.sin(phi), radius*Math.sin(theta),
        radius*Math.sin(far));

    modelViewMatrix = lookAt(eye, at , up);
    projectionMatrix = perspective(fovy, aspect, near, far);

    gl.uniformMatrix4fv( modelViewMatrixLoc, false, flatten(modelViewMatrix) );
    gl.uniformMatrix4fv( projectionMatrixLoc, false, flatten(projectionMatrix) );

    gl.drawArrays( gl.TRIANGLES, 0, NumVertices );
    requestAnimationFrame(render);

}


var canvas=document.getElementById("canvas");
var ctx=canvas.getContext("2d");
var BB=canvas.getBoundingClientRect();
var offsetX=BB.left;
var offsetY=BB.top;
var WIDTH = canvas.width;
var HEIGHT = canvas.height;
var reader = new FileReader();


let canvasHistory = [];

let step = -1;

function undo() {
    if (step >= 0) {
        step--;
        ctx.clearRect(0, 0, WIDTH, HEIGHT);
        let canvasPic = new Image();
        canvasPic.src = canvasHistory[step];
        canvasPic.addEventListener('load', () => {
            ctx.drawImage(canvasPic, 0, 0);
        });
    } else {
        console.log('continue to cancel');
    }
}


function redo() {
    if (step < canvasHistory.length - 1) {
        step++;
        let canvasPic = new Image();
        canvasPic.src = canvasHistory[step];
        canvasPic.addEventListener('load', () => {
            ctx.clearRect(0, 0, WIDTH, HEIGHT);
            ctx.drawImage(canvasPic, 0, 0);
        });
    } else {
        console.log('Already the latest record');
    }
}

function KeyPress(e) {
    var fun = window.event? event : e
    if (fun.keyCode === 90 && fun.ctrlKey) {
        undo();
    } else if (fun.keyCode === 90 && fun.altKey) {
        redo();
    }
}

document.onkeydown = KeyPress;

var dragok = false;
var startX;
var startY;

// an array of objects that define different shapes
var shapes=[];

var currentShapeStatus = 0;

function reloadPage() {
    location.reload();
}

function selectShape() {
    currentShapeStatus = 0;
}

function moveShape() {
    currentShapeStatus = 1;
}

function rotateShape() {
    currentShapeStatus = 3;
}

function scaleShape() {
    currentShapeStatus = 2;
}

function pushRect() {
    shapes.push({x:20, y:300, width:40, height: 80, fill:"green", isDragging:false, numSide:4, rad:0, square:false});
}

function drawRectangle(){
    currentShapeStatus = 4;
    ctx.fillStyle="green";
    ctx.fillRect(20, 300, 40, 80)
    pushRect();
}

function pushCir() {
    shapes.push({x:10, y:300, r:20, fill:"pink", isDragging:false, numSide: 0, oval:false});
}

function drawCircle() {
    ctx.save()
    currentShapeStatus = 5
    ctx.beginPath();
    ctx.arc(20, 300, 20, 0, 2 * Math.PI);
    ctx.fillStyle="pink";
    ctx.fill();
    ctx.strokeStyle="pink";
    ctx.stroke();
    pushCir();
    ctx.restore();
}

function pushEll() {
    shapes.push({x:100, y:100, rx:15, ry:30, rotation:0, fill:"purple", isDragging:false, numSide: 0, oval:true});
}

function drawEllipse() {
    ctx.save()
    currentShapeStatus = 9;
    ctx.beginPath();
    ctx.ellipse(100, 100, 15, 30, 0, 0, 2 * Math.PI);
    ctx.fillStyle="purple";
    ctx.fill();
    ctx.strokeStyle="purple";
    pushEll();
    ctx.restore();
}

function pushPoly() {
    shapes.push({Xcenter:25, Ycenter:25, size:20, fill:"red", isDragging:false, numSide:parseInt(document.getElementById("numPoly").value), rad:0});
}

function drawPolygon() {
    currentShapeStatus = 7;
    var numberOfSides = parseInt(document.getElementById("numPoly").value);
    var polySides = numberOfSides;
    var size = 20, Xcenter = 25, Ycenter = 25;
    ctx.beginPath();
    ctx.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
    for (var i = 1; i <= numberOfSides;i += 1) {
        ctx.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
    }
    ctx.fillStyle="red"
    ctx.fill()
    pushPoly();
}

function pushStraightLine() {
    shapes.push({Xcenter:80, Ycenter:80, size:50, fill:"black", isDragging:false, straight:true, numSide:2, rad:0})
}

function drawStrLine() {
    currentShapeStatus = 10;
    var numberOfSides = 2;
    var size = 50, Xcenter = 80, Ycenter = 80;
    ctx.beginPath();
    ctx.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
    for (var i = 1; i <= numberOfSides;i += 1) {
        ctx.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
    }
    ctx.fillStyle="black"
    ctx.fill()
    ctx.stroke();
    pushStraightLine();
}

function pushCurvedLine() {
    shapes.push({Xcenter:180, Ycenter:120, size:60, fill:"black", isDragging:false, curved:true, numSide:2, rad:0,
        x1:120, y1:120, cpx:150, cpy:190, x2:180, y2:120});
}

function drawCurve() {
    currentShapeStatus = 11;
    var numberOfSides;
    var size = 60, Xcenter = 180, Ycenter = 120;
    ctx.beginPath();
    ctx.moveTo(120, 120);
    ctx.quadraticCurveTo(150, 190, 180, 120);
    ctx.stroke();
    pushCurvedLine();
}

function pushPolyLine() {
    shapes.push({fill:"black", size:20, isDragging:false, polyline:true, rad:0,
        x1:170, y1:150, x2:200, y2:200, x3:230, y3:150});
}

function drawPolyLine(){
    currentShapeStatus = 13;
    ctx.beginPath();
    ctx.moveTo(170, 150);
    ctx.lineTo(200, 200);
    ctx.lineTo(230, 150 )
    ctx.stroke();
    pushPolyLine();
}

function pushSquare() {
    shapes.push({Xcenter:50, Ycenter:25, size:20, fill:"blue", isDragging:false, numSide:4, rad:0 , square:true});

}

function drawSquare() {
    currentShapeStatus = 8;
    var numberOfSides = 4;
    var size = 20, Xcenter = 50, Ycenter = 25;
    ctx.beginPath();
    ctx.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
    for (var i = 1; i <= numberOfSides;i += 1) {
        ctx.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
    }
    ctx.fillStyle="blue"
    ctx.fill()
    ctx.stroke();
    pushSquare();
}

function pushTri() {
    shapes.push({Xcenter:100, Ycenter:100, size:20, fill:"orange", isDragging:false, numSide:3, rad:0});
}

function drawTriangle() {
    currentShapeStatus = 6
    var numberOfSides = 3;
    polySides = numberOfSides;
    var size = 20, Xcenter = 100, Ycenter = 100;
    ctx.beginPath();
    ctx.moveTo (Xcenter +  size * Math.cos(0), Ycenter +  size *  Math.sin(0));
    for (var i = 1; i <= numberOfSides;i += 1) {
        ctx.lineTo (Xcenter + size * Math.cos(i * 2 * Math.PI / numberOfSides), Ycenter + size * Math.sin(i * 2 * Math.PI / numberOfSides));
    }
    ctx.fillStyle="orange"
    ctx.fill()
    pushTri();
}

canvas.onmousedown = myDown;
canvas.onmouseup = myUp;
canvas.onmousemove = myMove;

function rect(r) {
    ctx.save();
    ctx.fillStyle=r.fill;
    ctx.translate(r.x + r.width/2, r.y + r.height/2)
    ctx.rotate(r.rad);
    ctx.translate(-r.x - r.width/2, -r.y - r.height/2)
    ctx.fillRect(r.x,r.y,r.width,r.height);
    ctx.restore();
}

function circle(c) {
    ctx.save();
    ctx.fillStyle=c.fill;
    ctx.beginPath();
    ctx.arc(c.x,c.y,c.r,0,Math.PI*2);
    ctx.closePath();
    ctx.fill();
    ctx.restore();
}

function ellipse(e) {
    ctx.save();
    ctx.fillStyle=e.fill;
    ctx.beginPath();
    ctx.ellipse(e.x,e.y,e.rx,e.ry,e.rotation, 0, 2*Math.PI*2);
    ctx.fill();
    ctx.restore();
}

function tri(t) {
    ctx.save();
    ctx.fillStyle = t.fill;
    ctx.beginPath();
    ctx.translate(t.Xcenter, t.Ycenter);
    ctx.rotate(t.rad);
    ctx.translate(-t.Xcenter , -t.Ycenter );
    ctx.moveTo(t.Xcenter + t.size * Math.cos(0), t.Ycenter + t.size *  Math.sin(0));
    for (var i = 1; i <= t.numSide ;i += 1) {
        ctx.lineTo (t.Xcenter + t.size * Math.cos(i * 2 * Math.PI / t.numSide),
            t.Ycenter + t.size * Math.sin(i * 2 * Math.PI / t.numSide));
    }
    ctx.fill();
    ctx.restore();
}

function poly(p) {
    ctx.save();
    ctx.fillStyle = p.fill;
    ctx.beginPath();
    ctx.translate(p.Xcenter, p.Ycenter);
    ctx.rotate(p.rad);
    ctx.translate(-p.Xcenter , -p.Ycenter );
    ctx.moveTo(p.Xcenter +  p.size * Math.cos(0), p.Ycenter +  p.size *  Math.sin(0));
    for (var i = 1; i <= p.numSide ;i += 1) {
        ctx.lineTo (p.Xcenter + p.size * Math.cos(i * 2 * Math.PI / p.numSide),
            p.Ycenter + p.size * Math.sin(i * 2 * Math.PI / p.numSide));
    }
    ctx.fill();
    ctx.restore();
}

function straightLine(st) {
    ctx.save();
    ctx.fillStyle = st.fill;
    ctx.beginPath();
    ctx.translate(st.Xcenter, st.Ycenter);
    ctx.rotate(st.rad);
    ctx.translate(-st.Xcenter , -st.Ycenter );
    ctx.moveTo(st.Xcenter +  st.size * Math.cos(0), st.Ycenter +  st.size *  Math.sin(0));
    for (var i = 1; i <= st.numSide ;i += 1) {
        ctx.lineTo (st.Xcenter + st.size * Math.cos(i * 2 * Math.PI / st.numSide),
            st.Ycenter + st.size * Math.sin(i * 2 * Math.PI / st.numSide));
    }
    ctx.fill();
    ctx.stroke();
    ctx.restore();
}

function polyLine(pl){
    ctx.save();
    ctx.fillStyle = pl.fill;
    ctx.beginPath();
    ctx.translate(pl.x2, pl.y2);
    ctx.rotate(pl.rad);
    ctx.translate(-pl.x2 , -pl.y2 );
    ctx.moveTo(pl.x1, pl.y1);
    ctx.lineTo(pl.x2, pl.y2);
    ctx.lineTo(pl.x3, pl.y3 )
    ctx.stroke();
    ctx.restore();
}

function curvedLine(cr) {
    ctx.save();
    ctx.fillStyle = cr.fill;
    ctx.beginPath();
    // var size = 60, Xcenter = 180, Ycenter = 120;
    ctx.translate(cr.cpx, cr.cpy);
    ctx.rotate(cr.rad);
    ctx.translate(-cr.cpx , -cr.cpy );
    ctx.beginPath();
    ctx.moveTo(cr.x1, cr.y1);
    ctx.quadraticCurveTo(cr.cpx, cr.cpy, cr.x2, cr.y2);
    ctx.stroke();
    ctx.restore();
}

function changeCurvature () {
    currentShapeStatus = 12;
}

function square(sq) {
    ctx.save();
    ctx.fillStyle = sq.fill;
    ctx.beginPath();
    ctx.translate(sq.Xcenter, sq.Ycenter);
    ctx.rotate(sq.rad);
    ctx.translate(-sq.Xcenter , -sq.Ycenter );
    ctx.moveTo(sq.Xcenter +  sq.size * Math.cos(0), sq.Ycenter +  sq.size *  Math.sin(0));
    for (var i = 1; i <= sq.numSide ;i += 1) {
        ctx.lineTo (sq.Xcenter + sq.size * Math.cos(i * 2 * Math.PI / sq.numSide),
            sq.Ycenter + sq.size * Math.sin(i * 2 * Math.PI / sq.numSide));
    }
    ctx.fill();
    ctx.restore();
}

// clear the canvas
function clear() {
    ctx.clearRect(0, 0, WIDTH, HEIGHT);
}

// redraw the scene
function draw() {

    clear();
    // redraw each shape in the shapes[] array
    for(var i=0;i<shapes.length;i++){
        // decide if the shape is a rect or circle
        // (it's a rect if it has a width property)
        if(shapes[i].numSide === 4 && shapes[i].square === false){
            rect(shapes[i]);
        } else if (shapes[i].oval === false){
            circle(shapes[i]);
        } else if (shapes[i].numSide === 3) {
            tri(shapes[i]);
        } else if (shapes[i].numSide >= 5) {
            poly(shapes[i]);
        } else if (shapes[i].numSide === 4 && shapes[i].square === true) {
            square(shapes[i]);
        } else if (shapes[i].oval === true) {
            ellipse(shapes[i]);
        } else if (shapes[i].straight === true) {
            straightLine(shapes[i]);
        } else if (shapes[i].curved === true) {
            curvedLine(shapes[i]);
        } else if (shapes[i].polyline === true) {
            polyLine(shapes[i]);
        }
    }

}

// handle mousedown events
function myDown(e){
    if (currentShapeStatus === 1 || currentShapeStatus === 2 || currentShapeStatus === 3 || currentShapeStatus === 12) {
        e.preventDefault();
        e.stopPropagation();

        var mx=parseInt(e.clientX-offsetX);
        var my=parseInt(e.clientY-offsetY);

        dragok=false;
        for(var i=0;i<shapes.length;i++){
            var s=shapes[i];
            if(s.numSide === 4 && s.square === false) {
                if(mx>s.x && mx<s.x+s.width && my>s.y && my<s.y+s.height){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.numSide === 0 && s.oval === false) {
                var dx=s.x-mx;
                var dy=s.y-my;
                // test if the mouse is inside this circle
                if(dx*dx+dy*dy<s.r*s.r){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.numSide === 3) {
                var dx=s.Xcenter-mx;
                var dy=s.Ycenter-my;
                // test if the mouse is inside this circle
                if(dx*dx+dy*dy<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.numSide >= 5 || s.square === true || s.straight === true) {
                var dx=s.Xcenter-mx;
                var dy=s.Ycenter-my;
                // test if the mouse is inside this circle
                if(dx*dx+dy*dy<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.oval === true) {
                var dx=s.x-mx;
                var dy=s.y-my;
                // test if the mouse is inside this circle
                if(dx*dx+dy*dy<s.rx*s.ry){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.curved === true) {
                var dx=s.cpx-mx;
                var dy=s.cpy-my;

                if(dx*dx+dy*dy<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                }
            } else if (s.polyline === true) {
                var dx1=s.x1-mx;
                var dy1=s.y1-my;
                var dx2=s.x2-mx;
                var dy2=s.y2-my;
                var dx3=s.x3-mx;
                var dy3=s.y3-my;

                if(dx1*dx1+dy1*dy1<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                } else if(dx2*dx2+dy2*dy2<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                } else if(dx3*dx3+dy3*dy3<s.size*s.size){
                    dragok=true;
                    s.isDragging=true;
                }
            }
        }
        // save the current mouse position
        startX=mx;
        startY=my;
    }

}

// handle mouseup events
function myUp(e){
    if (currentShapeStatus === 1 || currentShapeStatus === 2 || currentShapeStatus === 3 || currentShapeStatus === 12) {
        // tell the browser we're handling this mouse event
        e.preventDefault();
        e.stopPropagation();

        // clear all the dragging flags
        dragok = false;
        for(var i=0;i<shapes.length;i++){
            shapes[i].isDragging=false;
        }
    }
}


// handle mouse moves
function myMove(e){
    if (currentShapeStatus === 1) {

        if (dragok){

            e.preventDefault();
            e.stopPropagation();

            // get the current mouse position
            var mx=parseInt(e.clientX-offsetX);
            var my=parseInt(e.clientY-offsetY);

            // calculate the distance the mouse has moved
            var dx=mx-startX;
            var dy=my-startY;

            for(var i=0;i<shapes.length;i++){
                var s=shapes[i];
                if(s.isDragging){
                    s.x+=dx;
                    s.y+=dy;
                    s.Xcenter +=dx;
                    s.Ycenter +=dy;
                    s.cpx += dx;
                    s.cpy += dy;
                    s.x1 += dx;
                    s.y1 += dy;
                    s.x2 += dx;
                    s.y2 += dy;
                    s.x3 += dx;
                    s.y3 += dy;
                }
            }
            step++;
            if (step < canvasHistory.length) {
                canvasHistory.length = step; // truncating the array
            }
            draw();
            canvasHistory.push(canvas.toDataURL()); // Add a new draw to the history

            startX=mx;
            startY=my;
        }
    } else if (currentShapeStatus === 2) {
        if (dragok) {
            e.preventDefault();
            e.stopPropagation();

            var mx=parseInt(e.clientX-offsetX);
            var my=parseInt(e.clientY-offsetY);

            var dx=mx-startX;
            var dy=my-startY;

            for(var i=0;i<shapes.length;i++){
                var s=shapes[i];
                if(s.isDragging){
                    s.size += dy;
                    s.height += dy;
                    s.width += dx;
                    s.r += dy;
                    s.rx +=dx;
                    s.ry +=dy;

                    s.x1 -= dx;
                    s.y1 -= dy;
                    s.x2 += dx;
                    s.y2 += dy;
                    s.x3 -= dx;
                    s.y3 -= dy;
                }
            }
            step++;
            if (step < canvasHistory.length) {
                canvasHistory.length = step; // truncating the array
            }
            draw();
            canvasHistory.push(canvas.toDataURL()); // Add a new draw to the history

            startX=mx;
            startY=my;
        }
    } else if (currentShapeStatus === 3) {
        if (dragok) {
            e.preventDefault();
            e.stopPropagation();

            var mx=parseInt(e.clientX-offsetX);
            var my=parseInt(e.clientY-offsetY);

            var dx=mx-startX;
            var dy=my-startY;

            for(var i=0;i<shapes.length;i++){
                var s=shapes[i];
                if(s.isDragging){
                    s.rad = Math.atan2(my, mx) * 180 / Math.PI;
                    s.rotation = Math.atan2(my, mx) * 180 / Math.PI;
                }
            }
            step++;
            if (step < canvasHistory.length) {
                canvasHistory.length = step; // truncating the array
            }
            draw();
            canvasHistory.push(canvas.toDataURL()); // Add a new draw to the history

            startX=mx;
            startY=my;
        }
    } else if (currentShapeStatus === 12) {
        if (dragok) {

            // tell the browser we're handling this mouse event
            e.preventDefault();
            e.stopPropagation();

            // get the current mouse position
            var mx = parseInt(e.clientX - offsetX);
            var my = parseInt(e.clientY - offsetY);

            // calculate the distance the mouse has moved
            // since the last mousemove
            var dx = mx - startX;
            var dy = my - startY;

            // move each rect that isDragging
            // by the distance the mouse has moved
            // since the last mousemove
            for (var i = 0; i < shapes.length; i++) {
                var s = shapes[i];
                if (s.isDragging) {
                    // s.x+=dx;
                    // s.y+=dy;
                    // s.Xcenter +=dx;
                    // s.Ycenter +=dy;
                    s.cpx += dx;
                    s.cpy += dy;
                    // s.x1 += dx;
                    // s.y1 += dy;
                    // s.x2 += dx;
                    // s.y2 += dy;
                }
            }
            step++;
            if (step < canvasHistory.length) {
                canvasHistory.length = step; // truncating the array
            }
            draw();
            canvasHistory.push(canvas.toDataURL()); // Add a new draw to the history
            startX = mx;
            startY = my;
        }
    }
}

function saveImage() {
    var imageName = "YourDrawing";
    imageName += ".jpeg"
    var savedImage = document.getElementById("SaveImage");
    var image = document
        .getElementById("canvas")
        .toDataURL("image/jpeg")
        .replace("image/jpeg", "image/octet-stream");
    savedImage.setAttribute("download", imageName);
    savedImage.setAttribute("href", image);
}


async function downloadCanvas(el) {
    const imageURI = canvas.toDataURL("image/jpeg");
    el.href = imageURI;
}

document.getElementById('save').addEventListener('click', function () {
    var canvasContents = canvas.toDataURL(); // a data URL of the current canvas image
    var data = { image: canvasContents, date: Date.now() };
    var string = JSON.stringify(data);

    var file = new Blob([string], {
        type: 'application/json'
    });

    var a = document.createElement('a');
    a.href = URL.createObjectURL(file);
    a.download = 'data.json';
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
});

document.getElementById('load').addEventListener('change', function () {
    if (this.files[0]) {
        reader.readAsText(this.files[0]);
    }
});

reader.onload = function () {
    var data = JSON.parse(reader.result);
    var image = new Image();
    image.onload = function () {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ctx.drawImage(image, 0, 0);
    }
    image.src = data.image;
};
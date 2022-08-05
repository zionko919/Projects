var my_canvas = document.getElementById("my_canvas");
var ctx = my_canvas.getContext("2d");

function DDA() {
    ctx.save();
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)

    var l_X1, l_X2, l_Y1, l_Y2;

    l_X1 = parseFloat(document.getElementById("l_X1").value);
    l_Y1 = parseFloat(document.getElementById("l_Y1").value);
    l_X2 = parseFloat(document.getElementById("l_X2").value);
    l_Y2 = parseFloat(document.getElementById("l_Y2").value);

    if (l_X2 < l_X1) {
        var temp = l_X1;
        l_X1 = l_X2;
        l_X2 = temp;
        temp = l_Y1;
        l_Y1 = l_Y2;
        l_Y2 = temp;
    }

    var x;
    var dy = l_Y2 - l_Y1;
    var dx = l_X2 - l_X1;
    var m = dy / dx;
    var y = l_Y1;
    var new_y;
    ctx.beginPath();
    ctx.fillRect(x,y, 1,1);
    for(x = l_X1; x <= l_X2; x++) {
        new_y = Math.round(y);
        y = y + m;
        ctx.fillRect(x, new_y, 1,1);
    }
    ctx.stroke();
    ctx.restore();
}

function MP_line() {
    ctx.save();
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)

    var mp_X1, mp_X2, mp_Y1, mp_Y2;

    mp_X1 = parseFloat(document.getElementById("l_X1").value);
    mp_Y1 = parseFloat(document.getElementById("l_Y1").value);
    mp_X2 = parseFloat(document.getElementById("l_X2").value);
    mp_Y2 = parseFloat(document.getElementById("l_Y2").value);

    if (mp_X2 < mp_X1) {
        var temp = mp_X1;
        mp_X1 = mp_X2;
        mp_X2 = temp;
        temp = mp_Y1;
        mp_Y1 = mp_Y2;
        mp_Y2 = temp;
    }

    var dy = mp_Y2 - mp_Y1;
    var dx = mp_X2 - mp_X1;
    var d = 2 * dy - dx;
    var incrE = 2 * dy;
    var incrNE = 2 * (dy - dx);
    var x = mp_X1;
    var y = mp_Y1;
    ctx.beginPath();
    // ctx.moveTo(x, y);
    ctx.fillRect(x,y, 1,1);
    var x22 = Math.abs(mp_X2);
    while (x < x22) {
        // ctx.lineTo(x, y);
        ctx.fillRect(x, y, 1,1);
        if (d <= 0) {
            d = d + incrE;
            x++;
        } else {
            d = d + incrNE;
            x++;
            y++;
        }
        // ctx.lineTo(x, y);
    }
    ctx.stroke();
    ctx.restore();
}

function circlePoints(xC, yC) {
    ctx.fillRect(xC,yC, 1, 1);
    ctx.fillRect(yC, xC, 1, 1);
    ctx.fillRect(yC, -xC, 1, 1);
    ctx.fillRect(xC, -yC, 1, 1);
    ctx.fillRect(-xC, -yC, 1, 1);
    ctx.fillRect(-yC,-xC, 1, 1);
    ctx.fillRect(-yC,xC, 1, 1);
    ctx.fillRect(-xC, yC, 1, 1);
}

function mp_circle() {
    ctx.save()
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)

    var cir_X, cir_Y, cir_Radius;

    cir_X = parseFloat(document.getElementById("cir_X").value);
    cir_Y = parseFloat(document.getElementById("cir_Y").value);
    cir_Radius = parseFloat(document.getElementById("cir_R").value);

    var x = 0;
    var y = cir_Radius;
    var d = 5.0/4.0 - cir_Radius;

    ctx.beginPath();
    ctx.translate(cir_X, cir_Y);
    circlePoints(x, y)
    while (y > x) {
        if (d < 0) {
            d = d + 2.0 * x + 3.0;
        } else {
            d = d + 2.0 * (x - y) + 5.0;
            y--;
        }
        x++;
        circlePoints(x, y)
    }
    ctx.stroke();
    ctx.restore();
}

function ellipsePoints(xC, yC) {
    ctx.fillRect(xC,yC, 1, 1);
    ctx.fillRect(-xC, yC, 1, 1);
    ctx.fillRect(xC, -yC, 1, 1);
    ctx.fillRect(-xC, -yC, 1, 1);
}

function mp_ellipse() {
    ctx.save()
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)


    var ell_X, ell_Y;
    var a, b;

    ell_X = parseFloat(document.getElementById("ell_X").value);
    ell_Y = parseFloat(document.getElementById("ell_Y").value);
    a = parseFloat(document.getElementById("ell_a").value);
    b = parseFloat(document.getElementById("ell_b").value);
    ctx.translate(ell_X, ell_Y);

    var x = 0;
    var y = b;
    var d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    var d2 = ((b * b) * (x + 0.5) * (x + 0.5)) + ((a * a) * (y - 1) * (y - 1)) - (a * a * b * b);

    ctx.beginPath();

    ellipsePoints(x, y)
    while (((a * a) * (y - 0.5)) > ((b * b) * (x + 1))) {
        if (d1 < 0) {
            d1 = d1 + ((b * b) * (2 * x + 3));
        } else {
            d1 = d1 + ((b * b) * (2 * x +3)) + ((a * a) * (-2 * y * 2));
            y--;
        }
        x++;
        ellipsePoints(x, y)
    }
    while (y > 0) {
        if (d2 < 0) {
            d2 = d2 + ((b * b) * (2 * x + 2)) + ((a * a) * (-2 * y + 3));
            x++;
        }
        else {
            d2 = d2 + ((a * a) * (-2 * y + 3));
        }
        y--;
        ellipsePoints(x, y);
    }
    ctx.stroke();
    ctx.restore();
}

function bezier() {
    ctx.save()
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)

    var num;
    var x1, x2, x3, x4, y1, y2, y3, y4;

    x1 = parseFloat(document.getElementById("c_X1").value);
    x2 = parseFloat(document.getElementById("c_X2").value);
    x3 = parseFloat(document.getElementById("c_X3").value);
    x4 = parseFloat(document.getElementById("c_X4").value);
    y1 = parseFloat(document.getElementById("c_Y1").value);
    y2 = parseFloat(document.getElementById("c_Y2").value);
    y3 = parseFloat(document.getElementById("c_Y3").value);
    y4 = parseFloat(document.getElementById("c_Y4").value);
    num = parseFloat(document.getElementById("curve_n").value);

    if(isNaN(num)) {
        num = 100;
    }

    var i, x, y, z;
    var delta = 1.0/num;
    var t;

    x = x1;
    y = y1;
    t = 0.0;

    ctx.beginPath();

    drawTXY(t, x, y);
    for (i = 0; i < num; i++) {
        t += delta;
        var t2 = t * t;
        var t3 = t2 * t;
        var q1 = (1 - t);
        var q2 = q1 * q1;
        var q3 = q2 * q1;

        x = q3 * x1 + (3 * t * q2) * x2 + (3 * t2 * q1) * x3 + t3 * x4;
        y = q3 * y1 + (3 * t * q2) * y2 + (3 * t2 * q1) * y3 + t3 * y4;
        drawTXY(t, x, y);
    }
    ctx.stroke();
    ctx.restore();
}

function hermite() {
    ctx.save()
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)


    var num;
    var x1, x2, x3, x4, y1, y2, y3, y4;

    x1 = parseFloat(document.getElementById("c_X1").value);
    x2 = parseFloat(document.getElementById("c_X2").value);
    x3 = parseFloat(document.getElementById("c_X3").value);
    x4 = parseFloat(document.getElementById("c_X4").value);
    y1 = parseFloat(document.getElementById("c_Y1").value);
    y2 = parseFloat(document.getElementById("c_Y2").value);
    y3 = parseFloat(document.getElementById("c_Y3").value);
    y4 = parseFloat(document.getElementById("c_Y4").value);
    num = parseFloat(document.getElementById("curve_n").value);

    if(isNaN(num)) {
        num = 100;
    }

    var i, x, y, z;
    var delta = 1.0/num;
    var t;

    x = x1;
    y = y1;
    t = 0.0;

    ctx.beginPath();

    drawTXY(t, x, y);
    for(i = 0; i < num; i++) {
        t += delta;
        var t2 = t * t;
        var t3 = t2 * t;

        x = ((2 * t3) - (3 * t2) + 1) * x1 + ((-2 * t3) + (3 * t2)) * x2 + (t3 - (2 * t2) + t) * x3 + (t3 - t2) * x4;
        y = ((2 * t3) - (3 * t2) + 1) * y1 + ((-2 * t3) + (3 * t2)) * y2 + (t3 - (2 * t2) + t) * y3 + (t3 - t2) * y4;
        drawTXY(t, x, y);
    }
    ctx.stroke();
    ctx.restore();

}

function b_spline() {
    ctx.save()
    ctx.clearRect(0, 0, my_canvas.width, my_canvas.height);
    ctx.translate(200, 200)


    var num;
    var x1, x2, x3, x4, y1, y2, y3, y4;

    x1 = parseFloat(document.getElementById("c_X1").value);
    x2 = parseFloat(document.getElementById("c_X2").value);
    x3 = parseFloat(document.getElementById("c_X3").value);
    x4 = parseFloat(document.getElementById("c_X4").value);
    y1 = parseFloat(document.getElementById("c_Y1").value);
    y2 = parseFloat(document.getElementById("c_Y2").value);
    y3 = parseFloat(document.getElementById("c_Y3").value);
    y4 = parseFloat(document.getElementById("c_Y4").value);
    num = parseFloat(document.getElementById("curve_n").value);


    if(isNaN(num)) {
        num = 100;
    }

    var i, x, y, z;
    var delta = 1.0/num;
    var t;

    x = x1;
    y = y1;
    t = 0.0;

    ctx.beginPath();

    drawTXY(t, x, y);
    for (i = 0; i < num; i++) {
        t += delta;
        var t2 = t * t;
        var t3 = t2 * t;

        x = (((1 - t3) / 6) * x1) + (((3 * t3 - 6 * t2 + 4) / 6) * x2)+(((-3 * t3 + 3 * t2 + 3 * t + 1) / 6) * x3) + ((t3 / 6) * x4);
        y = (((1 - t3) / 6) * y1) + (((3 * t3 - 6 * t2 + 4) / 6) * y3)+(((-3 * t3 + 3 * t2 + 3 * t + 1) / 6) * y3) + ((t3 / 6) * y4);

        drawTXY(t, x, y);
    }
    ctx.stroke();
    ctx.restore();
}

function drawTXY(t, x, y) {
    // ctx.fillRect(x, y, 1, 1,);
    ctx.lineTo(x, y);
    // document.write("t: " + t + " x: " + x + " y:" + y +" ***");
}
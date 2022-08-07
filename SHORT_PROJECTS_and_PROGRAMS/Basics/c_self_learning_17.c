/***********************************************
 Self Learning C - Basic 17
 This program will draw some shapes.
 using arc() and drawing fuctions.
 ***********************************************/

#include <stdio.h>
#include <draw.h>
#include <math.h>

void grid(void);
void drawVerticalLine(void);
void drawHorizontalLine(void);
void greenSquare(void);
void unfilledBlackCircle(void);
void filledYellowHalfCircle(void);
void filledBlueHalfCircle(void);
void smiley(void);
void unfilledRedTriangle(void);
void rowBlueCyanSquares(void);
void blueSquaresLoop(void);
void cyanSquaresLoop(void);



int main(int argc, char * argv[])
{
    grid();
    greenSquare();
    unfilledBlackCircle();
    filledYellowHalfCircle();
    filledBlueHalfCircle();
    unfilledRedTriangle();
    smiley();
    rowBlueCyanSquares();
    return 0;
}

void grid(void)
{
    drawVerticalLine();     // draws vertical lines 
    drawHorizontalLine();   // draws horizontal lines
}

void drawVerticalLine(void)
{
    // starts at 0 
    int x = 0;
    // x <= 360 since the width of the grid ends at 360
    for (x=0;x<=360;x+=10){ // x+=10 since the grid is spaced every 10 units
        draw_begin();
        draw_setColor("gray");
        draw_moveTo(0+x,0);
        draw_lineTo(0+x,260);
        draw_finish(0);       
    }
    return;
}

void drawHorizontalLine(void)
{
    // starts at 0
    int y = 0;
    // y <= 260 since the height of the grid ends at 260
    for(y=0;y<=260;y+=10){  // y+=10 since the grid is spaced every 10 units
        draw_begin();
        draw_setColor("gray");
        draw_moveTo(0,0+y);
        draw_lineTo(360,0+y);
        draw_finish(0);
    }
    return;
}

void greenSquare(void)
{
    draw_begin();           // step1: Begin drawing a path
    draw_setColor("green"); // step2: Set the color for this path
    draw_moveTo(10, 10);    // step3: Move to the starting point, at coordinates (100, 100)
    draw_lineTo(10, 50);    // step4: Draw a vertical line going down (same x position, new y position)
    draw_lineTo(50, 50);    // step5: Draw a horizontal line going right (new x position, same y position)
    draw_lineTo(50, 10);    // step6: Draw a vertical line going up (same x position, new y position)
    draw_lineTo(10, 10);    // step7: Draw a horizontal line back to the starting point going left (starting x position, starting y position)
    draw_finish(1);         // step8: Render this path, fill(1)  or unfill(0)
    return;
}

void unfilledBlackCircle(void)
{
    draw_begin();
    draw_setColor("black");
    // (x coordinate of circle center, y coordinate of circle center, radius, angle of start point of arc, angle of end point of arc, FALSE( meaning not anticlockwise)
    draw_arc(100, 40, 30, 0, M_PI * 2, 0);  
    draw_finish(0);
    return;
}

void filledYellowHalfCircle(void)
{
    draw_begin();
    draw_setColor("yellow");
    draw_arc(140, 40, 30, M_PI, M_PI * 2, 0);
    draw_finish(1);
    return;
}

void filledBlueHalfCircle(void)
{
    draw_begin();
    draw_setColor("blue");
    draw_arc(200, 40, 30, M_PI/2, M_PI *3/ 2, 1);
    draw_finish(1);
    return;
}

void smiley(void)
{
    // Head
    draw_begin(); 
    draw_setColor("blue");
    draw_arc(75, 175, 50, 0, M_PI*2, 1);
    draw_finish(0);
    
    // Mouth
    draw_begin();
    draw_setColor("blue");
    draw_arc(75, 175, 35, M_PI, M_PI*2, 1);
    draw_finish(0);
    
    // Left eye
    draw_begin();
    draw_setColor("blue");
    draw_arc(60, 165, 5, 0, M_PI*2, 1);
    draw_finish(0);
    
    // Right eye
    draw_begin();
    draw_setColor("blue");
    draw_arc(90, 165, 5, 0, M_PI*2, 1);
    draw_finish(0);
    return;
}

void unfilledRedTriangle(void)
{
    draw_begin();     
    draw_setColor("red");    
    draw_moveTo(250, 20);    
    draw_lineTo(300, 40);    
    draw_lineTo(250, 60);  
    draw_lineTo(250, 20);    
    draw_finish(0);    
    return;
}

void rowBlueCyanSquares(void)
{
    int num_squares;
    int num_blue;
    int num_cyan;
    printf("How many squares should display in blue/cyan row: ");
    scanf(" %d", &num_squares);
    if (num_squares % 2 == 0){
        num_blue = num_squares/2;
        num_cyan = num_squares/2;
    }
    else{
        num_blue = num_squares/2 + 1;
        num_cyan = num_squares - num_blue;
    }
    blueSquaresLoop(num_blue);
    cyanSquaresLoop(num_cyan);
    
    return;
}

void blueSquaresLoop(int num){
    // Blue Squares 
    int count = 0;
    int blueStartingPointX = 110;
    int blueStartingPointY = 100;
    while(count < num){
        draw_begin();
        draw_setColor("blue");
        draw_moveTo(blueStartingPointX, blueStartingPointY);
        draw_lineTo(blueStartingPointX + 20, blueStartingPointY);
        draw_lineTo(blueStartingPointX + 20, blueStartingPointY + 20);
        draw_lineTo(blueStartingPointX, blueStartingPointY + 20);
        draw_lineTo(blueStartingPointX, blueStartingPointY);
        draw_finish(1);
        blueStartingPointX += 40;
        count += 1;
    }
    return;
}

void cyanSquaresLoop(int num){
     // Cyan Squares
    int count = 0;
    int cyanStartingPointX = 130;
    int cyanStartingPointY = 100;
    while(count < num){
        draw_begin();
        draw_setColor("cyan");
        draw_moveTo(cyanStartingPointX, cyanStartingPointY);
        draw_lineTo(cyanStartingPointX + 20, cyanStartingPointY);
        draw_lineTo(cyanStartingPointX + 20, cyanStartingPointY + 20);
        draw_lineTo(cyanStartingPointX, cyanStartingPointY + 20);
        draw_lineTo(cyanStartingPointX, cyanStartingPointY);
        draw_finish(1);
        cyanStartingPointX += 40;
        count += 1;
    }
    return;
}
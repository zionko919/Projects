/***********************************************
/* Self Learning C - Basic 19

 This program is designed to learn about 
 FUCTIONS and Top-Down method.
 ***********************************************/



#include <stdio.h>
#include <math.h>   // needed for M_PI
#include <draw.h>

void blueAndCyanArcs(void); // It will draw 'Open Blue Arc' and 'Closed Cyan Arc'
void arc(void);
void degreesToRadians(int x, int y, int radius, double startingAngle, double endingAngle, 
int clockwise, int filled, int dark);
void square(int x, int y, int size, int isDark); // draws a square
void rowOfSquares(int x, int y, int size, int length, int isDark);  // draws a row of squares
void checkerboard(int x, int y, int size, int length, int isDark);  // draws a ckeckerboard


int main(int argc, char * argv[])
{
    blueAndCyanArcs();
    checkerboard(10, 10, 20, 8, 1);
    checkerboard(140, 140, 11, 5, 0);
    
    return 0;
}




void blueAndCyanArcs(void){
    int starting_angles, ending_angles;
    double starting_radians, ending_radians;
    
    printf("Enter the starting angle: ");
    scanf("%d", &starting_angles);
    printf("Enter the ending angle: ");
    scanf("%d", &ending_angles);

    //converts the user's input into radians and stores them into starting_radians and ending_radians.
    starting_radians = degreesToRadians(starting_angles);
    ending_radians = degreesToRadians(ending_angles);
    
    arc(220, 50, 30, starting_radians, ending_radians, 0 , 0, 1);     // draws open blue arc
    arc(220, 150, 15, (M_PI*3/2), (M_PI*2), 1, 1, 0);   // draws closed cyan arc
    return;
}

void arc(int x, int y, int radius, double startingAngle, double endingAngle, 
int clockwise, int filled, int dark){
    draw_begin();

    // a variable 'dark' decides the color (0 = cyan, 1 = blue).
    if(dark == 0){
        draw_setColor("cyan");
    }
    else{
        draw_setColor("blue");
    }
    draw_arc(x, y, radius, startingAngle, endingAngle, clockwise);

    // a variable 'filled' decides the open/close state of the arc (0 = open, 1 = close).
    if (filled==1){
        draw_finish(1);
    }
    else{
        draw_finish(0);
    }
    return;
}

//  converts user's input into usable radians
void degreesToRadians(int num_degree){
    double radians;
    radians = (2*M_PI*num_degree)/360; // The equation was given from the instruction
    return radians;
}


// draws a checkerboard
void checkerboard(int x, int y, int size, int length, int isDark)
{   
    int blueCount = 0; // a counter for a row that starts with a blue square
    int cyanCount = 0; // a counter for a row that starts with a cyan square
    int blue_y = y;
    int cyan_y = y;

    // If the length is an odd number, then the starting row color and the ending row color has to be the same.
    // Same goes for the starting column color and the ending column color. 
    // The number of the starting color square has one more square.
    if(length%2 == 1){
        // if the starting color is cyan, it ends with cyan
        if(isDark == 0){
            while(blueCount < length/2){
                rowOfSquares(x, blue_y + size, size, length, 1);
                blueCount += 1;
                blue_y += 2 * size;
            }
            while(cyanCount < (length/2+1)){
                rowOfSquares(x, cyan_y, size, length, 0);
                cyanCount += 1;
                cyan_y += 2 * size;
            }
            return;
        }
        // if the starting color is blue, it ends with blue    
        else if(isDark == 1){
            while(blueCount < length/2+1){
                rowOfSquares(x, blue_y, size, length, isDark);
                blueCount += 1;
                blue_y += 2 * size;
            }
            while(cyanCount < (length/2)){
                rowOfSquares(x, cyan_y + size, size, length, 0);
                cyanCount += 1;
                cyan_y += 2 * size;
            }
            return;    
        }
    }

    // If the length is an even number, then the starting row color and the ending row color has to be different.
    // Same goes for the starting column color and the ending column color. 
    // the number of the starting square and the ending square is equal.
    else if(length%2 == 0){
        // if the starting color is cyan, it ends with blue.
        if(isDark == 0){
            while(blueCount < length/2){
                rowOfSquares(x, blue_y + size, size, length, 1);
                blueCount += 1;
                blue_y += 2 * size;
            }
            while(cyanCount < (length/2)){
                rowOfSquares(x, cyan_y, size, length, 0);
                cyanCount += 1;
                cyan_y += 2 * size;
            }
            return;
        }
        // if the starting color is blue, then it ends with cyan
        else if(isDark == 1){
            while(blueCount < length/2){
                rowOfSquares(x, blue_y, size, length, isDark);
                blueCount += 1;
                blue_y += 2 * size;
            }
            while(cyanCount < (length/2)){
                rowOfSquares(x, cyan_y + size, size, length, 0);
                cyanCount += 1;
                cyan_y += 2 * size;
            }
            return;   
        }     
    }
}   

void rowOfSquares(int x, int y, int size, int length, int isDark)
{
    int blueCount = 0;
    int cyanCount = 0;
    int blue_x = x;
    int cyan_x = x;
    // If the length is an odd number, then the starting row color and the ending row color has to be different.
    if(length%2 == 1){
        // if the starting color is cyan, it ends with cyan.
        if(isDark == 0){
            while(blueCount < length/2){
                square(blue_x + size, y, size, 1);
                blueCount += 1;
                blue_x += 2 * size;
            }
            while(cyanCount < (length/2+1)){
                square(cyan_x, y, size, 0);
                cyanCount += 1;
                cyan_x += 2 * size;
            }
            return;
        }    
        // if the starting color is blue, it ends with blue.
        else if(isDark == 1){
            while(blueCount < length/2+1){
                square(blue_x, y, size, isDark);
                blueCount += 1;
                blue_x += 2 * size;
            }
            while(cyanCount < (length/2)){
                square(cyan_x + size, y, size, 0);
                cyanCount += 1;
                cyan_x += 2 * size;
            }
            return;    
        }
    }
    // If the length is an even number, then the starting row color and the ending row color has to be different.
    else if(length%2 == 0){
        // if the starting color is cyan, it ends with blue.
        if(isDark == 0){
            while(blueCount < length/2){
                square(blue_x + size, y, size, 1);
                blueCount += 1;
                blue_x += 2 * size;
            }
            while(cyanCount < (length/2)){
                square(cyan_x, y, size, 0);
                cyanCount += 1;
                cyan_x += 2 * size;
            }
            return;
        }
        // if the starting color is blue, it ends with cyan.
        else if(isDark == 1){
            while(blueCount < length/2){
                square(blue_x, y, size, isDark);
                blueCount += 1;
                blue_x += 2 * size;
            }
            while(cyanCount < (length/2)){
                square(cyan_x + size, y, size, 0);
                cyanCount += 1;
                cyan_x += 2 * size;
            }
            return;   
        }     
    }
}            
    


void square(int x, int y, int size, int isDark){
    draw_begin();               // Begin drawing the path 
    // decides the color
    if(isDark == 1){
        draw_setColor("blue");      
    }
    else{
        draw_setColor("cyan");      
    }
    draw_moveTo(x, y);          // Move to the top­left corner, our starting positino
    draw_lineTo(x + size, y);   // Draw the top line 
    draw_lineTo(x + size, y + size);    // Draw the right side line 
    draw_lineTo(x, y + size);   // Draw the bottom line 
    draw_lineTo(x, y);      // Finally, close the path by drawing the left side line 
    draw_finish(1);         // Render this square, filled
    return;
}
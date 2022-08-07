/***********************************************
    Self Learning C - Basic 22
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <draw.h>

// FORWARD DECLARATIONS
int exercise1(void);
void exercise2(void);
void exercise3(void);
int stringCompare(char * pStr1, char * pStr2);
char * getToken(char * pSource, char delim, char * pDest, int destLen);
void processDrawCommand(char source[]);

int main(int argc, char * argv[])
{
    if (exercise1() != 0)
    {
        return 1;
    }
    
    if (exercise2() != 0)
    {
        return 1;
    }
    
    exercise3();
    return 0;
}

int exercise1(void)
{
    int     i;
    int     ret = 0;    // assume success; changes if any test fails.
    int     compare;
    char *  testA[]   = { "a", "a", "b", "abc", "ab",  "abc", "" };
    char *  testB[]   = { "a", "b", "a", "ab",  "abc", "abc", "" };
    int     testVal[] = {  0,  -1,   1,   99,   -99,    0,     0 };
   
    printf("BEGIN EXERCISE 1\n");
   
    // Run each of the tests, comparing an element from the testA array
    // against the same-index element from the testB array. The expected
    // result from stringCompare() is in the same-index element of the
    // testVal array.
    for (i = 0; i < sizeof(testA) / sizeof(char *); i++)
    {
        // Call the stringCompare function with this test's values
        compare = stringCompare(testA[i], testB[i]);
        //printf("%d\n", compare);
        
        // Did we get the expected result?
        if (compare != testVal[i])
        {
            // Nope. Show 'em which test failed.
            printf("Bad comparison %d: expected %d, got %d\n",
                   i, testVal[i], compare);
            ret = 1;
        }
    }   
   
    // Exercise complete.
    printf("END EXERCISE 1\n\n");
    
    // Let the caller know if it succeeded
    return ret;
}



/**
 * Compare two strings. Return a value less than, equal to, or greater than
 * zero depending upon whether the first string (pStr1) is lexicographically
 * less than, equal to, or greater than the second string (pStr2).
 * 
 * The strings are compared character-by-character, until there is a difference,
 * or until the characters being compared are both the null terminator, '\0'.
 * At that point, the difference of the ascii values between the two characters
 * being compared is returned (character from second string subtracted from
 * character from first string).
 * 
 * @param pStr1
 *   The first string to be compared
 * 
 * @param pStr2
 *   The second string to be compared
 * 
 * @return
 *   0 if the two strings are identical in length and contents
 *  <0 if the first string is lexicographically less than the second string
 *  >0 if the first string is lexicographically greater than the second string
 */
int stringCompare(char * pStr1, char * pStr2)
{
    // COMPLETE THIS FUNCTION
    // (WRITE THE CODE HERE)
    int i;
    int x, y;
    for (i = 0; pStr1[i] != '\0'; i++){
        if (pStr1[i] != pStr2[i]){
            x = pStr1[i] - pStr2[i];
            return x;
        }
    }
    y = pStr1[i] - pStr2[i];
    return y;
}




/**
 * Read from a file and split each line of text into its constituent tokens
 */
void exercise2(void)
{
    FILE *  inputFile;
    char    line[64];
    char *  pNextSource;
    char    token[32];
    
    
    printf("BEGIN EXERCISE 2\n");

    // Open the file /public/lab10ex2.txt for reading. Store the handle in
    // the variable inputFile.
    // (WRITE THE CODE HERE)
    inputFile = fopen("/public/lab10ex2.txt", "r");
    

    // Test to ensure the file was successfully opened. If opening the file
    // failed, display an error message, and exit the program with an exit
    // code of 1.
    // (WRITE THE CODE HERE)
    if (inputFile == NULL){
        printf("Error, Failed to open the file.\n");
        exit(1);
    }
    
    
    // Read each line from the file into the character array 'line'. Print out
    // the entire line, and also split the line into comma-separated tokens,
    // and print each token.
    // (WRITE THE CODE HERE)
    
    while (fgets(line, sizeof(line), inputFile) != NULL){
        printf("Line: [%s]\n", line);
        
        pNextSource = getToken(line, ',', token, sizeof(token));
        
        while(pNextSource != NULL)
        {
            printf("Token: [%s]\n", token);
            pNextSource = getToken(pNextSource, ',', token, sizeof(token));
        }
    }
    
    
    // Close the open file
    // (WRITE THE CODE HERE)
    fclose(inputFile);
    
    

    // Exercise complete.
    printf("END EXERCISE 2\n\n");
    
    
    // (CHANGE THIS TO RETURN THE VALUE 0, WHEN INSTRUCTED TO DO SO)
    return 0;
}



/**
 * Obtain the next token from a string. A token ends at the
 * first occurrence of the specified delimiter character, or at newline ('\n')
 * or end of string ('\0').
 * 
 * @param pSource
 *   Pointer to the source string, i.e., the first character of the token to
 *   be copied into destBuf
 * 
 * @param delim
 *   The delimiter character
 * 
 * @param dest
 *   The destination buffer into which the token will be placed
 * 
 * @param destLenRemaining
 *   The number of bytes available to place characters in the destination buffer
 * 
 * @return
 *   If a token was found (i.e., pSource was not pointing at a null terminator),
 *   then a pointer to the beginning of the next token is returned.
 * 
 *   If pSource was invalid or was pointing at a null terminator, then NULL
 *   is returned to indicate that there are no more tokens in this source
 *   string.
 */
char * getToken(char * pSource, char delim, char * pDest, int destLenRemaining) 
{
    // If there are no remaining characters in the source...
    if (pSource == NULL || *pSource == '\0' || *pSource=='\n')
    {
        // ... then null terminate the destination (assuming there is at least
        // one byte of space in it), ...
        if (destLenRemaining > 0)
        {
            *pDest = '\0';
        }
        
        // ... and return NULL to indicate that there are no more tokens.
        return NULL;
    }
    
    // While there's space in the destination buffer (including leaving space
    // for a trailing null byte in all cases) and there are more characters
    // in the source, and we haven't yet hit a delimiter...
    while (destLenRemaining > 1 &&
           *pSource != '\0' &&
           *pSource != delim &&
           *pSource != '\n')
    {
        // ... then copy this character from the source to the destination buffer.
        // (WRITE CODE HERE)
        *pDest = *pSource;
        
        // Point to the next character in the source
        // (WRITE CODE HERE)
        pSource++;
        
        // Point to the next character position in the destination buffer
        // (WRITE CODE HERE)
        pDest++;
        
        // We just consumed a byte of the destination buffer. Decrement the
        // indicator of remaining space in the destination buffer.
        --destLenRemaining;
    }
    
    // Null terminate the destination buffer.
    // (WRITE CODE HERE)
    *pDest = '\0';
        
    // If we're looking at a delimiter character (rather than the null byte at
    // the end of the source string)...
    if (*pSource == delim)
    {
        // ... then advance the source pointer past the delimiter, to point to
        // the first character of the next token.
        ++pSource;
    }
    
    // Return a pointer to the beginning of the next token (which might be
    // the pointer to the null terminator) so that it can be passed in as
    // pSource on the next call to this function. If the pointer to the null
    // terminator is returned, then the next call to getToken() will detect
    // it (at the beginning of the function), and return NULL.
    return pSource;
}



/**
 * Draw according to drawing commands stored in a file
 */
void exercise3(void)
{
    FILE *  inputFile;
    char    line[64];
    int i = 0;
    char    line_from_file[64];

    
    printf("BEGIN EXERCISE 3\n");

    // Open the file /public/lab10ex3.txt for reading. Store the handle in the
    // variable inputFile.
    // (WRITE THE CODE HERE)
    inputFile = fopen("/public/lab10ex3.txt", "r");

    // Test to ensure the file was successfully opened. If opening the file
    // failed, display an error message, and exit the program with an exit
    // code of 1.
    // (WRITE THE CODE HERE)
    if (inputFile == NULL){
        printf("Error, failed to open the file.\n");
        exit(1);
    }
    
    // Read each line from the file into the character array 'line'. Pass
    // each line of text to the processDrawCommand function.
    // (WRITE THE CODE HERE)
    while (fgets(line_from_file, sizeof(line_from_file), inputFile) != NULL){
        line[i] = line_from_file;
        if (line[0] != '/'){
            processDrawCommand(line_from_file);
        }
        i++;
    }
        
    // Close the input file
    // (WRITE THE CODE HERE)
    fclose(inputFile);

    // Exercise complete.
    printf("END EXERCISE 3\n\n");
}


/**
 * Process a single drawing command. The command and its arguments are in a
 * string, provided here, each separated by slashes.
 * 
 * @param command
 *   The command and its arguments, slash-separated
 */
void processDrawCommand(char commandAndArgs[])
{
    int     x;
    int     y;
    int     width;
    int     height;
    int     radius;
    int     isFilled;
    int     isAntiClockwise;
    double  startAngle;
    double  endAngle;
    char *  pNextToken;
    char    token[32];

    // Show the line we're parsing
    printf("%s", commandAndArgs);
    
    // Retrieve the first token (the function to call) into 'token'.
    pNextToken = getToken(commandAndArgs, '/', token, sizeof(token));
    
    // Determine which function was requested, and process it.
    if (stringCompare(token, "begin") == 0)
    {
        // There are no additional arguments to begin
        draw_begin();
    }
    else if (stringCompare(token, "moveTo") == 0)
    {
        // Retrieve the x coordinate as a token and convert it to an integer
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        x = atoi(token);
        
        // Retrieve the y coordinate as a token and convert it to an integer
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        y = atoi(token);
        
        // Call the function
        draw_moveTo(x, y);
    }
    else if (stringCompare(token, "lineTo") == 0)
    {
        // COMPLETE THIS BLOCK
        // (WRITE CODE HERE)
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        x = atoi(token);
        
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        y = atoi(token);
        
        draw_lineTo(x, y);

    }
    else if (stringCompare(token, "arc") == 0)
    {
        // Retrieve the x coordinate as a token and convert it to an integer
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        x = atoi(token);
        
        // Retrieve the y coordinate as a token and convert it to an integer
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        y = atoi(token);
        
        // Retrieve the radius as a token and convert it to an integer
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        radius = atoi(token);
        
        // Retrieve the start angle in degrees as a token and convert it to
        // radians as a double
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        startAngle = atoi(token) * M_PI * 2 / 360;
        
        // Retrieve the end angle in degrees as a token and convert it to
        // radians as a double
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        endAngle = atoi(token) * M_PI * 2 / 360;
        
        // Retrieve the indicator of anticlockwise or not ("true" or "false")
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        isAntiClockwise = stringCompare(token, "true") == 0;
        
        // Call the function
        draw_arc(x, y, radius, startAngle, endAngle, isAntiClockwise);
    }
    else if (stringCompare(token, "finish") == 0)
    {
        // COMPLETE THIS BLOCK
        // (WRITE CODE HERE)
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        isFilled = stringCompare(token, "true") == 0;
        draw_finish(isFilled);

    }
    else if (stringCompare(token, "setColor") == 0)
    {
        // Retrieve the color
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        
        // Call the function
        draw_setColor(token);
    }
    else if (stringCompare(token, "clearRectangle") == 0)
    {
        // COMPLETE THIS BLOCK
        // (WRITE CODE HERE)
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        x = atoi(token);
        
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        y = atoi(token);
        
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        width = atoi(token);
        
        pNextToken = getToken(pNextToken, '/', token, sizeof(token));
        height = atoi(token);
        
        draw_clearRectangle(x, y, width, height);
    }
    
    else if (*token == '\0' || *token == ' ' || *token == '#')
    {
        // We found an empty line or a comment. Just skip it.
        // Comments have first character being # or space.
    }
}

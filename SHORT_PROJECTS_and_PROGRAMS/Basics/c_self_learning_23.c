/***********************************************
    Self Learning C - Basic 23
 ***********************************************/

#include <stdio.h>
#include <ctype.h>


// Forward Declarations
char * encodeCaesar(char * src, char * dest);
char * decodeCaesar(char * src, char * dest);
char * encodeSubstitution(char * lcEncodingKey, char * src, char * dest);
char * decodeSubstitution(char * lcEncodingKey, char * src, char * dest);
int testEncodeDecode(char * p1, char * p2);


int main(int argc, char * argv[])
{
    // Test strings to be encoded
    char        src1[50] = "abcdwxyz";
    char        src2[50] = "My secret password is: l3t ME PL@y!";
    char        src3[50] = "Ciphers are fun!";
    
    // lowercase encoding key for substitution cipher
    char        lcEncodingKey[] = "qwertyuiopasdfghjklzxcvbnm";
    
    // buffers to hold encoded and decoded strings
    char        encoded[50];
    char        decoded[50];


    // *****************************************
    // DO NOT CHANGE ANYTHING IN THIS FUNCTION!
    // *****************************************
    
    printf("Begin test with src1...\n");
    
    // Encode the string in src1 using Caesar encoding, and print the result
    printf("Caesar encoding '%s' yields '%s'\n",
            src1, encodeCaesar(src1, encoded));

    // Decode the encoded string and print the result.
    printf("Caesar decoding '%s' yields '%s'\n", 
            encoded, decodeCaesar(encoded, decoded));

    // Confirm that the decoded string matches the original
    if (testEncodeDecode(decoded, src1) != 0)
    {
        printf("Error: Caesar encode/decode src1 does not work properly!\n");
        return 1;
    }

    printf("Successfully encoded/decoded src1 using Caesar cipher.\n\n");
    
    printf("Begin test with src2...\n");
    
    // Encode the string in src2 using Caesar encoding, and print the result
    printf("Caesar encoding '%s' yields '%s'\n", 
            src2, encodeCaesar(src2, encoded));

    // Decode the encoded string and print the result.
    printf("Caesar decoding '%s' yields '%s'\n", 
            encoded, decodeCaesar(encoded, decoded));
    
    // Confirm that the decoded string matches the original
    if (testEncodeDecode(decoded, src2) != 0)
    {
        printf("Error: Caesar encode/decode src2 does not work properly!\n");
        return 1;
    }

    printf("Successfully encoded/decoded src2 using Caesar cipher.\n\n");
    
    printf("Begin test with src3...\n");
    
    // Encode the string in src3 using the substitution cipher, and print the result
    printf("Substitution encoding '%s' yields '%s'\n", 
           src3, encodeSubstitution(lcEncodingKey, src3, encoded));

    // Decode the encoded string and print the result
    printf("Substitution decoding '%s' yields '%s'\n", 
           encoded, decodeSubstitution(lcEncodingKey, encoded, decoded));
    
    // Confirm that the decoded string matches the original
    if (testEncodeDecode(decoded, src3) != 0)
    {
        printf("Error: Substitution encode/decode src3 does not work properly!\n");
        return 1;
    }

    printf("Successfully encoded/decoded src2 using Substitution cipher.\n\n");
    
    return 0;
}



/**
 * Encode a string using Caesar encoding.
 * 
 * @param src
 *   Address of the string to be encoded
 * 
 * @param dest
 *   Address of a memory buffer at least as long as the src string, into
 *   which the Caesar-encoded (encrypted) string will be placed.
 * 
 * @return
 *   The address of the first character of the Caesar-encoded (encrypted) string
 */
char * encodeCaesar(char * src, char * dest)
{
    int         offset;
    char *      destStart = dest;
    
    // lowercase encoding key
    char        lcEncodingKey[] = "defghijklmnopqrstuvwxyzabc";
        
    // For each character in the source string...
    for (; *src; ++src, ++dest)
    {
        // Determine the offset of this character from the beginning of
        // the alphabet, by subtracting the ASCII value of 'a' from this
        // character. For example, if *src is 'a', then (*src - 'a') will
        // yield 0 because the ASCII values of *src (which is 'a') and 'a'
        // are both 97. If *src is 'd', then (*src - 'a') will yield 3, 
        // because the ASCII value of 'd' is 100 and the ascii value of 'a'
        // is 97, and (100 - 97) is 3.
        
        if(isalpha(*src) == 1) {    // check if *src is alphabet
            if(islower(*src) == 1) {    // check if *src is lowercase
                offset = *src - 'a';
                *dest = lcEncodingKey[offset]; // Obtain the lowercase replacement character and assign it to the current position in the destination.
            }
            else if(isupper(*src) == 1) {   //check if *src is uppercase
                offset = *src - 'A';
                *dest = lcEncodingKey[offset];
                *dest = toupper(*dest);
            }
        }
        else {
            *dest = *src;
        }
    }
    
    // Null-terminate the destination buffer
    *dest = '\0';
    
    // Return the beginning of the destination buffer
    return destStart;
}

/**
 * Decode a string that was encoded using Caesar encoding.
 * 
 * @param src
 *   Address of the string to be decoded
 * 
 * @param dest
 *   Address of a memory buffer at least as long as the src string, into
 *   which the decoded (decrypted) string will be placed.
 * 
 * @return
 *   The address of the first character of the decoded (decrypted) string
 */
char * decodeCaesar(char * src, char * dest)
{
    int         offset;
    char        lcDecodingKey[] = "xyzabcdefghijklmnopqrstuvw";
    char *      destStart = dest;
    
    // For each character in the source string...
    for (; *src; ++src, ++dest) {
        // Determine the offset of this character from the beginning of
        // the alphabet, by subtracting the ASCII value of 'a' from this
        // character. For example, if *src is 'a', then (*src - 'a') will
        // yield 0 because the ASCII values of *src (which is 'a') and 'a'
        // are both 97. If *src is 'd', then (*src - 'a') will yield 3, 
        // because the ASCII value of 'd' is 100 and the ascii value of 'a'
        // is 97, and (100 - 97) is 3.
        if(isalpha(*src) == 1) {
            if(islower(*src) == 1) {
                offset = *src - 'a'; // Obtain the lowercase replacement character and assign it to the current position in the destination.
                *dest = lcDecodingKey[offset];
            }
            else if(isupper(*src) == 1) {
                offset = *src - 'A';
                *dest = toupper(lcDecodingKey[offset]);
            }
        }
        else {
            *dest = *src;
        }
    }
    // Null-terminate the destination buffer
    *dest = '\0';
    
    // Return the beginning of the destination buffer
    return destStart;
}

/**
 * Encode a string using substitution cipher encoding
 * 
 * @param lcEncodingKey
 *   Address of the string containing the lowercase encoding key
 * 
 * @param src
 *   Address of the string to be encoded
 * 
 * @param dest
 *   Address of a memory buffer at least as long as the src string, into
 *   which the substitution-cipher-encoded (encrypted) string will be placed.
 * 
 * @return
 *   The address of the first character of the encoded (encrypted) string
 */
char * encodeSubstitution(char * lcEncodingKey, char * src, char * dest)
{
    char        ucEncodingKey[26];
    int offset;
    int i;
    char *destStart = dest;
    
    // You were given the lowercase encoding key. From it, create the
    // uppercase encoding key
    // (WRITE CODE HERE)
    for (i = 0; i < 26; i++){
        ucEncodingKey[i] = toupper(lcEncodingKey[i]);
    }

    // Implementation of the generalized substitution encoder.
    // (WRITE CODE HERE)
     for (; *src; ++src, ++dest) {
        if(isalpha(*src) == 1) {
            if(islower(*src) == 1) {
                offset = *src - 'a';
                *dest = lcEncodingKey[offset];
            }
            else if(isupper(*src) == 1) {
                offset = *src - 'A';
                *dest = ucEncodingKey[offset];
            }
        }
        else {
            *dest = *src;
        }
    }
    *dest = '\0';
    return destStart;
}

/**
 * Decode a string using substitution cipher decoding
 * 
 * @param lcEncodingKey
 *   Address of the string containing the lowercase encoding key.
 * 
 * @param src
 *   Address of the string to be decoded
 * 
 * @param dest
 *   Address of a memory buffer at least as long as the src string, into
 *   which the substitution-cipher-decoded (decrypted) string will be placed.
 * 
 * @return
 *   The address of the first character of the decoded (decrypted) string
 */
char * decodeSubstitution(char * lcEncodingKey, char * src, char * dest)
{
    char        lcDecodingKey[26];
    char        ucDecodingKey[26];
    int offset; 
    int i;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";     
    char        *destStart = dest;

    // Create the lower case decoding key from the lower case encoding key
    // (WRITE CODE HERE)
    for(i = 0; i < 26; i++) {
        offset = lcEncodingKey[i] - 'a';
        lcDecodingKey[offset] = alphabet[i];
    }

    // Create the uppercase decoding
    // (WRITE CODE HERE)
    for(i = 0; i < 26; i++) {
        ucDecodingKey[i] = toupper(lcDecodingKey[i]);
    }

    // Implementation of the generalized substitution decoder.
    // (WRITE CODE HERE)
    for (; *src; ++src, ++dest) {
        if(isalpha(*src) == 1) {
            if(islower(*src) == 1) {
                offset = *src - 'a';
                *dest = lcDecodingKey[offset];
            }
            if(isupper(*src) == 1) {
                offset = *src - 'A';
                *dest = ucDecodingKey[offset];
            }
        }
        else {
            *dest = *src;
        }
    }
    *dest = '\0';    
    return destStart;
}


/**
 * Determine if the encoded/decoded string is the same as the original string.
 */
int testEncodeDecode(char * p1, char * p2)
{
    // *****************************************
    // DO NOT CHANGE ANYTHING IN THIS FUNCTION!
    // *****************************************
   
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
    {
        ++p1, ++p2;
    }
    
    return *p1 != *p2;
}

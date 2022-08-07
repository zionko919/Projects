/* ******************************************************************************
 * Description: A program that encrypt and decrypt a photo with seed input.
 * File: PhotoMagic.cpp - has transform function that takes an image and FibLFSR
 * as arguments. It transforms image using the linear feedback shift register.
 * ******************************************************************************/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "LFSR.hpp"

using namespace sf;
using namespace std;

void transform(Image& image, FibLFSR* seed); // Function definition after main() function.

int main(int argc, char* argv[]) {
    // if statement for whether or not the user provided the command in correct format.
    if (argc != 4) {
        cout << "Error: Please use this format: $ ./PhotoMagic [Input-file] [Output-file] [Seed]" << endl;
        return -1;
    }

    // varaibles for inputs from the command entered.
    string inputFile(argv[1]);
    string outputFile(argv[2]);
    string seed(argv[3]);

    // Creating Image variables and testing out with if statements to validate the file.
    Image inputImage;
    Image outputImage;
    if (!inputImage.loadFromFile(inputFile)) {
        cout << "Error: Input image cannot be loaded." << endl;
        return -1;
    } else if (!outputImage.loadFromFile(inputFile)) {
        cout << "Error: Output image cannot be loaded." << endl;
        return -1;
    }

    Vector2u size = inputImage.getSize();   // to get the size of the original image. It is from the starter code

    RenderWindow inputWindow(VideoMode(size.x, size.y), "Input Image File");
    RenderWindow outputWindow(VideoMode(size.x, size.y), "Output Image File");

    // Setting up  input texture variables and loading them with matching images.
    Texture inputTex;
    inputTex.loadFromImage(inputImage);

    // Setting up input sprite variables and loading them with matching textures.
    Sprite inputSprite;
    inputSprite.setTexture(inputTex);

    // getting the seed.
    FibLFSR fibLfsr(seed);

    // transform function used
    transform(inputImage, &fibLfsr);

    // put transformed image into output image
    outputImage = inputImage;

    // Setting up  output texture variables and loading them with matching images.
    Texture outputTex;
    outputTex.loadFromImage(outputImage);

    // Setting up output sprite variables and loading them with matching textures.
    Sprite outputSprite;
    outputSprite.setTexture(outputTex);

    // While loop to display window with correct sprites. It is basically as same as the given starter code;
    // I just made it to show both input and output like the instruction .pdf.
    while (inputWindow.isOpen() && outputWindow.isOpen()) {
        Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                inputWindow.close();
            }
        }
        while (outputWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                outputWindow.close();
            }
        }

        inputWindow.clear();
        inputWindow.draw(inputSprite);
        inputWindow.display();

        outputWindow.clear();
        outputWindow.draw(outputSprite);
        outputWindow.display();

        // Saving the output image to the output file with the name from the command
        if (!outputImage.saveToFile(outputFile)) {
            return -1;
        }

    }   // End of while loop here

    return 0;
}

void transform(Image& image, FibLFSR* seed)
{
    Color pixel;    // pixel variable. From the starter code
    Vector2u size = image.getSize();   // to get the size of the original image. It is from the starter code
    int comparison;
    // Extract all that red, green, and blue. I used the starter code as a reference
    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            pixel = image.getPixel(x, y);
            comparison = seed->generate(9); //tap value 9 is from PS1a
            pixel.r ^= ((Uint8)comparison); // Uint8 data type for 0 to 255,
            comparison = seed->generate(9);
            pixel.g ^= ((Uint8)comparison);
            comparison = seed->generate(9);
            pixel.b ^= ((Uint8)comparison);
            image.setPixel(x, y, pixel);  // set those random generated pixels over the image.
        }
    }
}

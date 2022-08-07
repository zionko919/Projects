/*********************************************************
 Purpose: <To get familiar with basics of C++: Class>

  A program with a zip code class that encodes and decodes 
  five digit bar codes used by the US Postal Service on 
  envelopes
***********************************************************/


#include <iostream>
#include <string>

using namespace std;

class ZipCode
{
public:
//  constructors
    ZipCode(int initZip);
    ZipCode(string initBar);
//  accessor functions
    string getBarCode();
    int getZipCode();

private:
    int zipcode;

    // my own converting functions
    string convertZipToBar(int zipcodeInt);
    int convertBarToZip(string barcode);
    int checkDigitsA(string five_digits);
    string checkDigitsB(int zipDigit);

};

int main(int argc, char * argv[])
{
    ZipCode zip(99504),
            zip2("100101010011100001100110001"),
            zip3(12345),
            zip4(67890);

    cout << zip.getZipCode() << "'s bar code is '"
         << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
         << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
         << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
         << zip4.getBarCode() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an arbitrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
             << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;

    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
            { "100101010011100001100110000", "bad start/end character" },
            { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }

    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

// constructor that initiates zipcode;
ZipCode::ZipCode(int initZip)
{
    zipcode = initZip;
}

// constructor that initiates zipcode as a barcode;
ZipCode::ZipCode(string initBar)
{
    // Error checking codes
    if (initBar[0] != '1' || initBar[initBar.length() - 1] != '1') {
        cout << "Error! Wring start/end character in the barcode" << endl;
    } else if (initBar.length() != 27) {
        cout << "Error! The barcode does not contain 27 digits in total" << endl;
    }

    for (int i = 0; i < initBar.length(); i++) {
        if (initBar[i] != '1' && initBar[i] != '0') {
            cout << "Error! A barcode can only contain 0 and 1" << endl;
            break;
        }
    }

    int convertedZipcode;
    convertedZipcode = convertBarToZip(initBar);
    zipcode = convertedZipcode;
}

//  accessor functions that gets barcode
string ZipCode::getBarCode()
{
    string barcode;
    barcode = convertZipToBar(zipcode);
    return barcode;
}

//  accessor functions that gets zipcode
int ZipCode::getZipCode()
{
    return zipcode;
}

// This function will convert a volid barcode into a zipcode
int ZipCode::convertBarToZip(string barcode)
{
    int finalZipcode = 0;
    barcode.pop_back();     // deletes very first digit '1'
    barcode.erase(0,1); // deletes very last digit '1'

    string zipDigit1, zipDigit2, zipDigit3, zipDigit4, zipDigit5;

    // we know that there are 25 digits in a barcode. I divided them into five groups to get digits for zip.
    for (int i = 0; i < 5; i++) {
        zipDigit1 += barcode[i];
    }
    for (int i = 5; i < 10; i++) {
        zipDigit2 += barcode[i];
    }
    for (int i = 10; i < 15; i++) {
        zipDigit3 += barcode[i];
    }
    for (int i = 15; i < 20; i++) {
        zipDigit4 += barcode[i];
    }
    for (int i = 20; i < 25; i++) {
        zipDigit5 += barcode[i];
    }

    int zip1, zip2, zip3, zip4, zip5;
    zip1 = checkDigitsA(zipDigit1) * 10000;
    zip2 = checkDigitsA(zipDigit2) * 1000;
    zip3 = checkDigitsA(zipDigit3) * 100;
    zip4 = checkDigitsA(zipDigit4) * 10;
    zip5 = checkDigitsA(zipDigit5) * 1;

    finalZipcode = zip1 + zip2 + zip3 + zip4 + zip5;
    return finalZipcode;

}

// This function matches 7-4-2-1 codes to a correct integer value
int ZipCode::checkDigitsA(string five_digits)
{
    int digit;
    if (five_digits == "11000") {
        digit = 0;
    } else if (five_digits == "00011") {
        digit = 1;
    } else if (five_digits == "00101") {
        digit = 2;
    } else if (five_digits == "00110") {
        digit = 3;
    } else if (five_digits == "01001") {
        digit = 4;
    } else if (five_digits == "01010") {
        digit = 5;
    } else if (five_digits == "01100") {
        digit = 6;
    } else if (five_digits == "10001") {
        digit = 7;
    } else if (five_digits == "10010") {
        digit = 8;
    } else if (five_digits == "10100") {
        digit = 9;
    }
    return digit;
}

// This function converts a zipcode into a barcode
string ZipCode::convertZipToBar(int zipcodeInt)
{
    string aBarcode;
    int digit1, digit2, digit3, digit4, digit5;
    // These will get each zipcode digit's value
    digit1 = (zipcodeInt - (zipcodeInt % 10000)) /10000;
    digit2 = ((zipcodeInt % 10000) - (zipcodeInt % 1000)) / 1000;
    digit3 = ((zipcodeInt % 1000) - (zipcodeInt % 100)) / 100;
    digit4 = ((zipcodeInt % 100) - (zipcodeInt % 10)) / 10;
    digit5 = ((zipcodeInt % 10) - (zipcodeInt % 1)) / 1;

    aBarcode += '1';    // a barcode starts with 1
    // I just combine all strings
    aBarcode += checkDigitsB(digit1) + checkDigitsB(digit2) +  checkDigitsB(digit3)
            +  checkDigitsB(digit4) +  checkDigitsB(digit5);

    aBarcode += '1'; // a barcode ends with 1

    return aBarcode;
}

// This function matches a integer value to a 7-4-2-1 code
string ZipCode::checkDigitsB(int zipDigit)
{
    string code;
    if (zipDigit == 0) {
        code = "11000";
    } else if (zipDigit == 1) {
        code = "00011";
    } else if (zipDigit == 2) {
        code = "00101";
    } else if (zipDigit == 3) {
        code = "00110";
    } else if (zipDigit == 4) {
        code = "01001";
    } else if (zipDigit == 5) {
        code = "01010";
    } else if (zipDigit == 6) {
        code = "01100";
    } else if (zipDigit == 7) {
        code = "10001";
    } else if (zipDigit == 8) {
        code = "10010";
    } else if (zipDigit == 9) {
        code = "10100";
    }
    return code;
}
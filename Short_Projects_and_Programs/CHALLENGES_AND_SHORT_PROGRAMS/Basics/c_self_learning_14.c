/***********************************************
Self Learning C - Basic 14
This program converts values that are
length or weights. This is a newerrefinement version
of previous demonstration using pointers.
***********************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void conversion(void); // Asks the user to select between weights and lengths.
void convert_lengths(void); // Asks the user to select US or Metric units to convert lengths.
void convert_weights(void); // Asks the user to select US or Metric units to convert weights.

void length_to_metric(void);    // It indicates that the user have selected US to Metric conversion and calls three functions on below.
void us_len_value_input(double *pValue_ft, double *pValue_in); // It reads the length in feet and inches given by the user.
void len_us_metric_convert(double value_ft, double value_in, double *pValue_m, double *pValue_cm); // It actually does the calculation and converts US to Metric.
void metric_len_result_output(int feet, double inches, int meters, double centimeters); // It outputs the Metric value so the user can see.

void length_to_us(void);    // Similar to length_to_metric
void metric_len_value_input(double *pValue_m, double *pValue_cm);
void len_metric_us_convert(double value_m, double value_cm, double *pValue_ft, double *pValue_in);
void us_len_result_output(int meters, double centimeters, int feet, double inches);

void weight_to_metric(void);     // Similar to length_to_metric
void us_wt_value_input(double *pValue_lb, double *pValue_oz);
void wt_us_metric_convert(double value_lb, double value_oz, double *pValue_kg, double *pValue_g);
void metric_wt_result_output(int pounds, double ounces, int kilograms, double grams);

void weight_to_us(void);     // Similar to length_to_metric
void metric_wt_value_input(double *pValue_kg, double *pValue_g);
void wt_metric_us_convert(double value_kg, double value_g, double *pValue_lb, double *pValue_oz);
void us_wt_result_output(int kilograms, double grams, int pounds, double ounces);

void clear_keyboard_buffer(void);


// main function.
int main (int agrc, char const *argv[])
{
    printf("Welcome, I am a conversion program.\n");
    conversion();
    return 0;
}

// conversion function to make the user to select between converting length or weight or to quit the program.
void conversion(void)
{
    int choice;
    while (choice != 0) {
        printf("\nMAIN MENU - Select:\n(1) Convert lengths\n(2) Convert weights\n(0) Exit the program\nYour choice: ");
        scanf("%d", &choice);
        clear_keyboard_buffer();

        switch  (choice)
        {
            case 1: convert_lengths();
                break;

            case 2: convert_weights();
                break;

            case 0: printf("Good Bye!\n");
                break;

            default: printf("I do not understand. Please follow the instruction.\n");
                break;
        }
    }
    return;
}




// convert_lengths function let the user choose between US to METRIC conversion or METRIC to US Conversion or go back to the previous menu.
void convert_lengths(void)
{
    int user_unit;  
    printf("\n***You are converting lengths.***");

    while(user_unit != 0) {
        printf("\nSelect\n(1) feet/inches to meters/centimeters\n(2) meters/centimeters to feet/inches\n(0) to go back\nYour choice: " );
        scanf("%d", &user_unit);
        clear_keyboard_buffer();


        switch (user_unit)
        {
            case 1: length_to_metric();
                break;

            case 2: length_to_us();
                break;

            case 0: conversion();
                break;

            default: printf("I do not understand. Please follow the instruction.\n");
                break;
        }
    }
    return;
}

void length_to_metric(void)
{
    double value_ft, value_in;
    double value_m, value_cm;
    printf("\nYou have selected US to METRIC conversion in lengths.\n");    // Indicates the user's selection
    us_len_value_input(&value_ft, &value_in);   // Addresses pValue_ft and pValue_in pointers
    len_us_metric_convert(value_ft, value_in, &value_m, &value_cm); // Addresses pValue_m and pValue_cm pointers
    metric_len_result_output(value_ft, value_in, value_m, value_cm);    // Outputs the result on the screen
    return;
}

void us_len_value_input(double *pValue_ft, double *pValue_in)
{
    double feet, inches;
    printf("Enter feet: ");
    scanf("%lf", &feet);
    clear_keyboard_buffer();
    printf("Enter inches: ");
    scanf("%lf", &inches);
    clear_keyboard_buffer();
    *pValue_ft = feet;  // Stores User's feet input into pValue_ft so it can be addressed on length_to_metric function.
    *pValue_in = inches;     // Stores User's inches input into pValue_in so it can be addressed on length_to_metric function.
    return;
}

void len_us_metric_convert(double value_ft, double value_in, double *pValue_m, double *pValue_cm)
{
    double total_feet, total_meters, meters, centimeters;
    total_feet = value_ft + (value_in/12.0); // converts inches into feet first and find the total feet.
    total_meters = total_feet * 0.3048; // converts total feet into total meters.
    meters = floor(total_meters);   // used floor() to find just meters.
    centimeters = (total_meters - meters) * 100.0;  // by subtracting meters from total meters, you can find remaining that can be converted into centimeters.
    *pValue_m = meters; // stores meters into pValue_m so it can be addresses on length_to_metric function.
    *pValue_cm = centimeters; // stores centimeters into pValue_cm so it can be addresses on length_to_metric function.
    return;
}

void metric_len_result_output(int feet, double inches, int meters, double centimeters)
{
    printf("%d feet and %.2lf inches is equivalent to %d meter and %.2lf centimeters.\n", feet, inches, meters, centimeters);
    // It just prints out the result using values that is stored in variables on length_to_metric function.
    return;
}




void length_to_us(void)
{
    double value_m, value_cm;
    double value_ft, value_in;
    printf("\nYou have selected METRIC to US conversion in lengths.\n");
    metric_len_value_input(&value_m, &value_cm);
    len_metric_us_convert(value_m, value_cm, &value_ft, &value_in);
    us_len_result_output(value_m, value_cm, value_ft, value_in);
    return;
}

void metric_len_value_input(double *pValue_m, double *pValue_cm)
{
    double meters, centimeters;
    printf("Enter meters: ");
    scanf("%lf", &meters);
    clear_keyboard_buffer();
    printf("Enter centimeters: ");
    scanf("%lf", &centimeters);
    clear_keyboard_buffer();
    *pValue_m = meters;
    *pValue_cm = centimeters;
    return;

}

void len_metric_us_convert(double value_m, double value_cm, double *pValue_ft, double *pValue_in)
{
    double total_feet, total_meters, feet, inches;
    total_meters = value_m + (value_cm/100.0);
    total_feet = total_meters / 0.3048;
    feet = floor(total_feet);
    inches = (total_feet - feet) * 12.0;
    *pValue_ft = feet;
    *pValue_in = inches;
    return;
}
void us_len_result_output(int meters, double centimeters, int feet, double inches)
{
    printf("%d meter and %.2lf centimeters is equivalent to %d feet and %.2lf inches.\n", meters, centimeters, feet, inches);
    return;
}




void convert_weights(void)
{
    int user_unit;
    printf("\n***You are converting weights.***");

    while(user_unit != 0) {
        printf("\nSelect\n(1) pounds/ounces to kilograms/grams\n(2) kilograms/grams to pounds/ounces\n(0) to go back\nYour choice: " );
        scanf("%d", &user_unit);
        clear_keyboard_buffer();
        switch (user_unit)
        {
            case 1: weight_to_metric();
                break;

            case 2: weight_to_us();
                break;

            case 0: conversion();
                break;

            default: printf("I do not understand. Please follow the instruction.\n");
                break;
        }
    }
    return;
}

void weight_to_metric(void)
{
    double value_lb, value_oz;
    double value_kg, value_g;
    printf("\nYou have selected US to METRIC conversion in weights.\n");
    us_wt_value_input(&value_lb, &value_oz);
    wt_us_metric_convert(value_lb, value_oz, &value_kg, &value_g);
    metric_wt_result_output(value_lb, value_oz, value_kg, value_g);
    return;
}

void us_wt_value_input(double *pValue_lb, double *pValue_oz)
{
    double pounds, ounces;
    printf("Enter pounds: ");
    scanf("%lf", &pounds);
    clear_keyboard_buffer();
    printf("Enter ounces: ");
    scanf("%lf", &ounces);
    clear_keyboard_buffer();
    *pValue_lb = pounds;
    *pValue_oz = ounces;
    return;
}

void wt_us_metric_convert(double value_lb, double value_oz, double *pValue_kg, double *pValue_g)
{
    double total_pounds, total_kilograms, kilograms, grams;
    total_pounds = value_lb + (value_oz/16.0);
    total_kilograms = total_pounds / 2.2046;
    kilograms = floor(total_kilograms);
    grams = (total_kilograms - kilograms) * 1000.0;
    *pValue_kg = kilograms;
    *pValue_g = grams;
    return;
}

void metric_wt_result_output(int pounds, double ounces, int kilograms, double grams)
{
    printf("%d pounds and %.2lf ounces is equivalent to %d kilograms and %.2lf grams.\n", pounds, ounces, kilograms, grams);
    return;
}




void weight_to_us(void)
{
    double value_kg, value_g;
    double value_lb, value_oz;
    printf("\nYou have selected METRIC to US conversion in weights.\n");
    metric_wt_value_input(&value_kg, &value_g);
    wt_metric_us_convert(value_kg, value_g, &value_lb, &value_oz);
    us_wt_result_output(value_kg, value_g, value_lb, value_oz);
    return;
}

void metric_wt_value_input(double *pValue_kg, double *pValue_g)
{
    double kilograms, grams;
    printf("Enter kilograms: ");
    scanf("%lf", &kilograms);
    clear_keyboard_buffer();
    printf("Enter grams: ");
    scanf("%lf", &grams);
    clear_keyboard_buffer();
    *pValue_kg = kilograms;
    *pValue_g = grams;
    return;
}

void wt_metric_us_convert(double value_kg, double value_g, double *pValue_lb, double *pValue_oz)
{
    double total_kilograms, total_pounds, pounds, ounces;
    total_kilograms = value_kg + (value_g/1000);
    total_pounds = total_kilograms * 2.2046;
    pounds = floor(total_pounds);
    ounces = (total_pounds - pounds) * 16.0;
    *pValue_lb = pounds;
    *pValue_oz = ounces;
    return;
}

void us_wt_result_output(int kilograms, double grams, int pounds, double ounces)
{
    printf("%d kilograms and %.2lf grams is equivalent to %d pounds and %.2lf ounces.\n", kilograms, grams, pounds, ounces);
    return;
}



void clear_keyboard_buffer(void){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
    return;
}
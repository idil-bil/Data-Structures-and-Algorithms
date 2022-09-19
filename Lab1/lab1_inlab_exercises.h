/*
File:         lab1_inlab_exercises.h
Purpose:      Contains prototypes of functions
Author:       Idil Bil and Fatima Mustaq
Student #s:   21344189 and 56703960
CS Accounts:  y3c2z and g7v2l
Date:         September 14, 2021
*/

/* Function Prototypes
A function prototype tells the compiler
a) the name of the function you are writing
b) what type it returns (or void, if it returns nothing)
c) the type(s) of its arguments (or void if there are none)
*/

void reverse_array(int array[], int length);
int length(const char string[]);
int count_letters(const char string[], char letter);
int is_palindrome(const char string[]);
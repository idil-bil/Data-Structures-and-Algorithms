/*
File:         lab1_inlab_exercises.c
Purpose:      Exercises for lab 1
Author:       Idil Bil and Fatima Mustaq
Student #s:   21344189 and 56703960
CS Accounts:  y3c2z and g7v2l
Date:         September 14, 2021
*/

/* Preprocessor directives */
#include "lab1_inlab_exercises.h"
#include <stdlib.h> // For system command

/* See main.c for additional practices for C programming */

/*
Reverses the order of an array of integers
For example,
{ 1, 2, 3, 4 } -> {4, 3, 2, 1 }
{ 1, 2, 3 } -> { 3, 2, 1 }
{1} -> {1}
{} -> {}
PARAM:  array, an array of integers
PARAM:  length, the number of elements in array
PRE:    array is an array of integers
PRE:    length is the correct length of the array
POST:   the elements in array have been reversed in order
RETURN: N/A
*/
void reverse_array(int array[], int length) {

    int i = 0;
    int k=length;
    int temp;

    while (i < k) {
        temp = array[i];
        array[i] = array[k-1];
        array[k-1] = temp;

        i++;
        k--;
    }
}

/*
Returns the length of the specified C string (an array of
characters that ends with the null character '\0')
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of char (excluding the terminating null) in string
*/
int length(const char string[])
{
    int i = 0;
    int length = 0;
    while (string[i] != '\0') {
        length++;
        i++;
    }

    return length;
}

/*
Returns the number of occurrences of the specified char in the specified
char array (string)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PARAM:  letter_sought, a char
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of occurences of letter_sought in string
*/
int count_letters(const char string[], char letter)
{
    int i = 0;
    int count = 0;

    while (string[i] != '\0') {

        if (string[i] == letter) {
            count++;
        }
        i++;
    }

    return count;
}

/*
Determines if a string is a palindrome.  Skips spaces.
For example,
""     -> returns 1 (an empty string is a palindrome)
"the"  -> returns 0
"abba" -> returns 1
"Abba" -> returns 0
"never odd or even"
-> returns 1 ("neveroddoreven" reversed is the same!)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   no side-effects, e.g., nothing is printed or changed
RETURN: IF string is a palindrome THEN 1
ELSE IF string is not a palindrome THEN 0
*/
int is_palindrome(const char string[]) {
    int string_length = length(string);
    int i = 0, j = string_length - 1;

    for (i = 0; i <= j; i++, j--) {
        if (string[i] != ' ') {
            if (string[j] != ' ') {
                if (string[i] != string[j]) {

                    return 0;
                }
                else
                    j--;
            }
            else
                i++;
        }
        return 1;
    }
    return 1;
}
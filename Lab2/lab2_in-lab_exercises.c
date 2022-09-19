/*
 File:				lab2_in-lab_exercises.c
 Purpose:			Implementation of functions for lab 2 in-lab exercises
 Author:			Idil Bil - Fatima Mustaq
 Student #s:		21344189 and 56703960 
 CWLs:				y3c2z and g7v2l
 Date:				September 28, 2021
 */

#include "lab2_in-lab_exercises.h"
#include <stdlib.h>

/*
 * Let's start with something easy.  There are 3 unit tests
 * for this function.
 *
 * Swaps the contents of two integer variables using pointers
 *
 * PARAM:     first_int is a pointer to an int
 * PARAM:     second_int is a pointer to an int
 * PRE:       both pointers are valid pointers to int
 * POST:      the contents of two integer variables are swapped
 * RETURN:    VOID
 */
void swap_ints(int* first_int, int* second_int)
{
	int temp;

	temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}

/*
 * Now let's try something a little more challenging.
 *
 * Reverses the contents of the string passed to the
 * function.  Does not move the terminating null '\0'
 * character.
 *
 * PARAM:     string is a pointer to an array of char (a string)
 * PRE:       the array of char terminates with a null '\0'
 * POST:      the char array has been reversed
 * RETURN:    VOID
 */
void reverse_string(char* string)
{
    int length = 0;

    for (int i = 0; *(string + i) != '\0'; i++) {
        length++;
    }

    int i = 0;
    int temp;

    while (i < length) {
        temp = *(string + i);
        *(string + i) = *(string + length - 1);
        *(string + length - 1) = temp;

        i++;
        length--;
    }
}

/*
 * Let's see how well you read the lab document.
 *
 * Determines if candidate contains sample, and returns
 * 1 if  it does, and 0 if it does not.
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * PRE:       candidate != NULL; sample != NULL
 * POST:      N/A
 * RETURN:    IF candidate contains sample THEN 1
 *            ELSE 0.
 */
int contains_sample(char* candidate, char* sample)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (*(candidate + k) == '\0' && (sample + k) == '\0') {
        return 1;
    }

    for (i = 0; i < strlen(candidate); i++) {

        for (j = 0; j < strlen(sample); j++) {

            if ((candidate + i + j) != *(sample + j)) {
                break;

            }
        }

        if (j == strlen(sample))
            return 1;
    }

    return 0;
}

/*
 * Returns the first index where sample is located inside the
 * candidate.  For example:
 * IF candidate = "Hello", sample = "Hello", RETURNS 0
 * IF candidate = "soupspoon", sample = "spoon", RETURNS 4
 * IF candidate = "ACGTACGTA", sample = "CGT", RETURNS 1
 * IF candidate = "CGTACGTA", sample = "CGTT", returns -1
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * POST:      N/A
 * RETURN:    IF candidate contains sample
 *            THEN the index where the first letter of sample is inside candidate
 *            ELSE -1.
 */
int find_index(char* candidate, char* sample)
{
    char* result = strstr(candidate, sample);
    int i;
    int index = -1;
    int j = 0;

    if (result == NULL) {
        index = -1;
    }

    if (*(candidate + j) == '\0') {
        return 0;
    }
    else {
        for (i = 0; i < strlen(candidate); i++) {
            if (result == &candidate[i]) {
                index = i;
            }
        }
    }
    return index;
}
/*
 File:				lab2_in-lab_exercises.h
 Purpose:			Contains function prototypes
 Author:			Idil Bil - Fatima Mustaq
 Date: September 28, 2021
 */

 /*
  #pragma once is a non-standard but widely supported preprocessor
  directive designed to cause the current source file to be included
  only once in a single compilation. Thus, #pragma once serves the same
  purpose as #include guards, but with several advantages, including:
  a) writing less code
  b) avoiding name clashes
  c) improving (sometimes) compile speed.
  */
#pragma once

  /* Function Prototypes */
void swap_ints(int* first_int, int* second_int);
void reverse_string(char* string);
int contains_sample(char* candidate, char* sample);
int generate_score(char* candidate, char* sample);
int find_index(char* candidate, char* sample);

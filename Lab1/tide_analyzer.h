/*
File:         tide_analyzer.h
Purpose:      Contains prototypes
Author:			  Idil Bil - Fatima Mustaq
Date:		      September 21, 2021
*/

/********************************************************************
YOU MAY EDIT THIS FILE (BUT YOU DON'T NEED TO)
******************************************************************/

#pragma once

/* Insert function prototypes here */
FILE* open_file(FILE* file_pointer, char* fileName, char* mode);
void process_file(double array_to_populate[], FILE* pointer_to_data_file);
void run_analysis();

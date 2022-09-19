/*
 File:				pagerank.c
 Purpose:			Lab 5 take home
 Author:			Idil Bil and Leif Moen
 Student #s:		21344189 and 97685127
 CWLs:      		y3c2z and kitmee10
 Date:				November 30,2021
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define  BUFSIZE 256

int main(void) {
    /* Variables */
    Engine* ep = NULL; // A pointer to a MATLAB engine object
	mxArray* rslt = NULL;
	mxArray* ConnectivityMatrix = NULL;
	FILE* inputfile;
	FILE* dim_inputfile = NULL; //separate file pointer for matrix dimension
	char buffer[BUFSIZE + 1];
	int lines = 0;
	int c = 0;
	int ch;

	inputfile = fopen_s(&inputfile, "web.txt", "r");		//opens file and reads if can't gives error
	if (inputfile != 0){
		printf("File opened successfully \n");
	}
	else{
		printf("Error opening the file \n");
	}

	if (inputfile != NULL) {									//counts the amount of rows or columns
		while (fscanf(&inputfile, "%lf", dim_inputfile) != NULL) {		//the following 3 lines of code are taken from this website and edited: https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-5.php
			for (c = fgetc(inputfile); c != EOF; c = fgetc(inputfile)) {	
				if (c == '\n') {							//counts the number of rows
					lines = lines + 1;						//increments count if this character is new line
				}
			}
		}
	}
	else {													//closes the file if empty
		printf("File is empty\n");
		fclose(inputfile);
	}

	/* Starts a MATLAB process */
	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		system("pause");
		return 1;
	}

	ConnectivityMatrix = mxCreateDoubleMatrix(lines, lines, mxREAL);		//creates connectivity matrix
	while ((ch = fgetc("web.txt")) != EOF) {								//copies the contents of the file to the connectivity matrix (?)
		fputc(ch, ConnectivityMatrix);
	}

	//one if statement for every line of matlab command
	if (engEvalString(ep, "[rows, columns] = size(ConnectivityMatrix)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "dimension = size(ConnectivityMatrix, 1)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "columnsums = sum(ConnectivityMatrix, 1)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "p = 0.85")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "zerocolumns = find(columnsums~=0)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "D = sparse( zerocolumns, zerocolumns, 1./columnsums(zerocolumns), dimension, dimension)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "StochasticMatrix = ConnectivityMatrix * D")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "[row, column] = find(columnsums==0)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "StochasticMatrix(:, column) = 1./dimension")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "Q = ones(dimension, dimension)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "TransitionMatrix = p * StochasticMatrix + (1 - p) * (Q/dimension)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "PageRank = ones(dimension, 1)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "for i = 1:100 PageRank = TransitionMatrix * PageRank; end")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}
	if (engEvalString(ep, "PageRank = PageRank / sum(PageRank)")) {
		fprintf(stderr, "\nError  \n");
		system("pause");
		exit(1);
	}

	if ((rslt = engGetVariable(ep, "PageRank")) == NULL) {		//calls the result from matlab
		fprintf(stderr, "\nFailed\n");
		system("pause");
		exit(1);
	}

	if (engOutputBuffer(ep, buffer, BUFSIZE)) {
		fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
		system("pause");
		return 1;
	}
    buffer[BUFSIZE] = '\0';

    engEvalString(ep, "whos"); // whos is a handy MATLAB command that generates a list of all current variables
    printf("%s\n", buffer);

    mxDestroyArray(rslt);
	mxDestroyArray(ConnectivityMatrix);
    rslt = NULL;
	ConnectivityMatrix = NULL;

	if (engClose(ep)) {
	        fprintf(stderr, "\nFailed to close MATLAB engine\n");
	}

	return 0;
}

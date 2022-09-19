/*
 File:				multmatrix.c
 Purpose:			Lab 5 inlab
 Author:			Idil Bil and Leif Moen
 Student #s:		21344189 and 97685127
 CWLs:      		y3c2z and kitmee10
 Date:				November 29,2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define  BUFSIZE 256
#define Columns 3
#define Rows 3

int main(void) {
    /* Variables */
    Engine* ep = NULL; // A pointer to a MATLAB engine object
    mxArray* testArray = NULL, * result = NULL; // mxArray is the fundamental type underlying MATLAB data
    double matrixOne[3][3] = { { 1.0, 2.0, 3.0 }, {4.0, 5.0, 6.0 }, {7.0, 8.0, 9.0 } };
    double matrixTwo[3][3] = { {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}, {4.0, 4.0, 4.0} };
    char buffer[BUFSIZE + 1];
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
    int a, b = 0;
    double rslt[3][3];
    mxArray* testmatrixOne = NULL;

    /* Starts a MATLAB process */
    if (!(ep = engOpen(NULL))) {
        fprintf(stderr, "\nCan't start MATLAB engine\n");
        system("pause");
        return 1;
    }

    testArray = mxCreateDoubleMatrix(3, 3, mxREAL);
    testmatrixOne = mxCreateDoubleMatrix(3, 3, mxREAL);
    memcpy((void*)mxGetPr(testArray), (void*)matrixOne, 9 * sizeof(double));
    memcpy((void*)mxGetPr(testArray), (void*)matrixTwo, 9 * sizeof(double));

    if (engPutVariable(ep, "testArray", testArray)) {
        fprintf(stderr, "\nCannot write test array to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }

    if (engEvalString(ep, "testArrayEigen = eig(testArray)")) {
        fprintf(stderr, "\nError calculating eigenvalues  \n");
        system("pause");
        exit(1);
    }

    printf("\nThe first matrix was:\n");
    for (row1 = 0; row1 < Rows; row1++) {
        for (column1 = 0; column1 < Columns; column1++) {
            printf("%f     ", matrixOne[column1][row1]);
        }
        printf("\n");
    }

    printf("\nThe second matrix was:\n");
    for (row2 = 0; row2 < Rows; row2++) {
        for (column2 = 0; column2 < Columns; column2++) {
            printf("%f     ", matrixTwo[column2][row2]);
        }
        printf("\n");
    }


    if ((result = engGetVariable(ep, "testArrayEigen")) == NULL) {
        fprintf(stderr, "\nFailed to retrieve eigenvalue vector\n");
        system("pause");
        exit(1);
    }
    else {
        size_t sizeOfResult = mxGetNumberOfElements(result);
        size_t i = 0;
        printf("\nThe martix product is:\n");

        for (int i = 0; i < Rows; i++) {            //for loops to compute the product
            for (int j = 0; j < Columns; j++) {
                rslt[j][i] = 0;

                for (int k = 0; k < Rows; k++) {
                    rslt[j][i] += matrixOne[k][i] * matrixTwo[j][k];    //the row is stable for matrixOne and the column is stable for matrixTwo
                }
            }
        }
        for (a = 0; a < Rows; a++) {            //for loops to print the result
            for (b = 0; b < Columns; b++) {
                printf("%f     ", rslt[b][a]);
            }
            printf("\n");
        }
    }
        if (engOutputBuffer(ep, buffer, BUFSIZE)) {
            fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
            system("pause");
            return 1;
        }
        buffer[BUFSIZE] = '\0';

        engEvalString(ep, "whos"); // whos is a handy MATLAB command that generates a list of all current variables
        printf("%s\n", buffer);

        printf("  testmatrixOne\n");

        mxDestroyArray(testArray);
        mxDestroyArray(result);
        testArray = NULL;
        result = NULL;

        if (engClose(ep)) {
            fprintf(stderr, "\nFailed to close MATLAB engine\n");
        }

        system("pause"); // So the terminal window remains open long enough for you to read it
        return 0; // Because main returns 0 for successful completion
}


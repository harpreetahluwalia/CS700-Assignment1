
/**
 *  @file   main.cpp
 *  @brief  It is the main program file
 *  @author Harpreet Singh
 *  @date   26/09/2021
 ***********************************************/

/**

@mainpage Section 2

 @author Harpreet Singh
 @date   26/09/2021

This is the main page for the project.\n\n
Functionality : \n
1. Stores the exam scores in a two-dimensional array. The row subscript should be the student number and the column subscript should be the exam number.
2. Calculates the average score for each exam.
3. Uses the average score for each exam to calculate and display the students grade for that exam. If the student score is within plus or minus 5 points of the average, it gives a grade of C.
If the grade is more than 5 points above or below the average, it gives a grade of B or D.
If the grade is more than 15 points above or below the average, it gives a grade of A or F.
4. Writes each student name to the output file followed by the students score and grade on
each exam in a well-formatted fashion.

*/


// Including the supporting libraries
#include <iostream>
#include <fstream>
#include <iomanip>

// Including the header files
#include "readData.h"
#include "gradeAndAvgCalc.h"
#include "writeToFile.h"
//using namespace std;


/**
 * Module : main\n
 * Author : Harpreet Singh\n
 * Date of creation : 26/09/2021
*/
int main (){

    string line;
    int numOfStudent = 0;
    int numOfSub = 0;
    ifstream myfile ("grades_Section2.txt");   //Opening the file named "grades_Section2.txt"
    int j = -1;
    int flag = 0;


    if (myfile.is_open())    // checking whether file is successfully opened
    {
        /* method readAndStoreData() is created in readData.h header file
        * which reads the data from the given file.
        */
        readAndStoreData(line, numOfStudent, numOfSub, myfile, flag, j);

    }else{
        cout<<"Not able to open the fine."<<endl;
    }

    calcAvgofEach(numOfStudent, numOfSub);

    displayGrades(numOfStudent, numOfSub);

    writeToFile(numOfStudent,numOfSub);


    delete []avgMarks;
    delete []globalArr;

    getchar();
    return 0;

}




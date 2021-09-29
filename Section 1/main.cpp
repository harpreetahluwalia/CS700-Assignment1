
/**
 *  @file   main.cpp
 *  @brief  It is the main program file
 *  @author Harpreet Singh
 *  @date   25/09/2021
 ***********************************************/

/**
@mainpage Section 1

 @author Harpreet Singh
 @date   25/09/2021

This is the main page for the project.

1. Reads each data line from a text file.
2. Outputs each student name, average exam score, and letter grade in a well-formatted fashion to a console display.
3. Writes all information including each student data (name, the number of exam scores,
followed by all the exam scores), average exam score, and letter grade stored in a well-formatted fashion to an output file.
*/

/// Including the supporting libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Including the header files
#include "calcGrade.h"
#include "spaceIndex.h"
#include "writeToFile.h"
#include "calcAvg.h"


/**
 * Module : main
 * Author : Harpreet Singh
 * Date of creation : 25/09/2021
*/
int main(){

    string line;  ///< Creating the file named "grades_Section2.txt"

    ifstream myfile ("grades_Section1.txt"); ///< Opening the file named "grades_Section2.txt"
    string name[] = {};

    cout<<"\n ----------------------- Welcome to Section 1 ----------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout << left << setw(35) << " Name" << setw(25) << "Average Marks"<< setw(10)<< "Grade" <<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;


    if (myfile.is_open()){
        int i = 0;
        calcAvg(line, myfile, name, i);   // Calling calAvg function to calculate and store the average of marks in given file.
    }
    myfile.close();  // closing the file
    cout<<"--------------------------------------------------------------------------------"<<endl;

    getchar();
    return 0;

}


/**
 *  @file   calcAvg.h
 *  @brief  It consist reading data from file and calculating, storing and displaying average marks of each student from the file
 *  @author Harpreet Singh
 *  @date   25/09/2021
 ***********************************************/


/// Including Header Files
#include "calcGrade.h"
#include "spaceIndex.h"
#include "writeToFile.h"
#include <iomanip>
using namespace std;
#pragma once


/**
 * Method : calcAvg \n
 * @author Harpreet Singh
 * @brief It fetches data from file line by and stores its values. It also calculates and displays the average marks of each
 * student from the given file.
 * @param line  a string read from the given file file.
 * @param myfile  object of file stream
 * @param name[]  array to store name
 * @param i  an integer variable
*/

void calcAvg(string line, ifstream& myfile, string name[], int i){

    std::ofstream ofs;
    ofs.open("output_Section1.txt", std::ofstream::out | std::ofstream::trunc);  // Creating output file.
    ofs.close();

    while ( getline (myfile,line) )          // reading data line by line
    {
        string tempStr;
        string studentName;
        int numOfSub = 0;
        float marks = 0;
        string grade;
        int sIndex = 0;
        int flag = 0;
        std::vector<int> marksArr;

        tempStr = line;         // storing read line to temporary string variable tempStr
        bool dot = true;
        while (dot){            // creating a loop while boolean variable dot is true

            sIndex = spaceIndex(tempStr);  // calling spaceIndex function to get the index of first space in the given string.

            string splitString;
            splitString = tempStr.substr(0,sIndex); // creating substring till the first space index

            if (sIndex == 0) {
                splitString = tempStr.substr(0);
                dot = false;

            // if space index is 0 i.e. if there is no space in the given string, it will trigger boolean variable "dot"
            // and treat it as last iteration of the loop

            }
            if (isalpha(splitString[0])){
                studentName = studentName + " " + splitString;
                tempStr.erase(0,sIndex+1);

            }
            else if (isdigit(splitString[0])){
                if (flag == 0){
                    numOfSub = stoi(splitString);   // fetching no. of subject
                    tempStr.erase(0,sIndex+1);
                    flag++;

                }else{

                    marksArr.push_back(stoi(splitString));   // storing the marks of the student

                    marks = marks + stoi(splitString);   // adding marks of the student (will be used to get average later)

                    tempStr.erase(0,sIndex+1);   // erasing the temporary string till space index
                }
            }
        }
        float avgMarks = marks/numOfSub;  // calculating average marks
        grade = calcGrade(marks/numOfSub); // calling calcGrade function to get the grade of the student based on the average marks.

        cout << left << setw(35) << studentName << setw(25) <<fixed<< setprecision(2) <<avgMarks<< setw(80)<< grade << endl;

        writeToFile(studentName, numOfSub, marksArr, avgMarks, grade);  // calling writeToFile function to write the data to output file
    }
}

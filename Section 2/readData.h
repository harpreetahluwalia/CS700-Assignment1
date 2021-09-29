/**
 *  @file   readData.h
 *  @author Harpreet Singh
 *  @brief  Includes method related to reading data from file such as number of subjects, no. of students,
 *          marks of the each exam of all students
 *          and storing its values for further use such as calculation of average and grade for each exam.
 *  @date   26/09/2021
 ***********************************************/





#include <string>                              // Including supporting liberaries
#include <vector>

using namespace std;

/*
 * creating Array variables with dynamic memory allocation as size of
 * the array depends on the input from the given file.
*/

/// 2D Array variable that stores marks of student in each subject, created with dynamic memory allocation as size of the array depends on the input from the given file.
int ** globalArr;

/// avgMarks array that stores average marks of the student, created with dynamic memory allocation as size of the array depends on the input from the given file.
float* avgMarks;

/// studentName1 dynamic vector to store names of the students.
std::vector<string> studentName1;


/**
 * Method : spaceIndex
 * @author Harpreet Singh
 * @brief calculates and returns the index of first space in the given string
 * @param s string variable where space index will be found
*/
int spaceIndex(string s){

    for (int i = 0; i<s.size(); i++){
        if (s[i] == ' '){
            return i;
        }
    }
    return 0;
}

/**
 * Method : readNumofSub
  * @author Harpreet Singh
 * @brief Return the number of subjects from the given split string
 * and erase the substring till the next space index.
 * @param splitString It holds split string till the first space index.
 * @param flag an integer flag variable
 * @param tempStr It holds address of temporary string
 * @param sIndex It holds space index in the string
*/
int readNumofSub(string splitString, int flag, string& tempStr, int sIndex){

    int numOfSub = stoi(splitString);
    tempStr.erase(0,sIndex+1);  // erasing the substring till the next space index.
    return numOfSub;

}



/**
 * Method : readNumOfStudents
  *@author Harpreet Singh
 * @brief Return the number of Students from the given split string
 * and erase the substring till the next space index.
 * @param splitString It holds split string till the first space index.
 * @param flag an integer flag variable
 * @param tempStr It holds address of temporary string
 * @param sIndex It holds space index in the string
*/
int readNumofStudents(string splitString, int flag, string& tempStr, int sIndex){

    int numOfStudent = stoi(splitString);
    tempStr.erase(0,sIndex+1);
    return numOfStudent;
}

/**
 * Method : readAndStoreData
 * @author Harpreet Singh
 * @brief It reads data from given file line by line and stores the data such as number of students, number of
 * subjects, student names and marks of student from each subject. This data would be used later on to
 * calculate further required details such as average marks and grade.
 * @param line a string variable holding line read from file
 * @param numOfstudent Number of students which is passed by reference.
  * @param numOfSub Number of Subjects which is passed by reference.
  * @param myfile object of the filestream
  * @param flag an integer flag variable
  * @param j an integer variable used in loop
  *
*/
void readAndStoreData(string line, int& numOfStudent, int& numOfSub,ifstream& myfile,int flag, int j){


    while ( getline (myfile,line) )
    {
        string tempStr = line;     // storing line from input file to a temporary string variable.
        int sIndex = 0;

        string studentName;
        int marks;

        int i =0;

        bool dot = true;
        while (dot){       // creating a loop while boolean variable dot is true

            sIndex = spaceIndex(tempStr);     // calling spaceIndex function to get the index of first space in the given string.

            string splitString;
            splitString = tempStr.substr(0,sIndex);    // creating substring till the first space

            if (sIndex == 0) {
                if (tempStr.size() < 4){
                    splitString = tempStr.substr(0);
                    dot = false;
                }else{
                    tempStr.erase(0,sIndex+1);

                }
                        // if space index is 0 i.e. if there is no space in the given string, it will trigger boolean variable "dot"
                        // and treat it as last iteration of the loop

                }

            if (flag == 0){
                numOfStudent = readNumofStudents(splitString,flag, tempStr, sIndex);
                flag++;
                continue;

            }else if(flag == 1){
                numOfSub = readNumofSub(splitString,flag, tempStr, sIndex);
                flag++;


                /* now that we have fetched the values of no. of students and no. of subjects
                 * we will dynamically allocate memory to the arrays to store marks and average marks.
                */

                globalArr = new int*[numOfStudent];
                for(i = 0; i < numOfStudent; i++)
                globalArr[i] = new int[numOfSub];

                avgMarks = new float[numOfSub];
                continue;
            }

            else if (isalpha(splitString[0])){
                    // if given split string is alphabet, it will store it's value to studentName variable and concatenate it
                    // with space delimiter throughout inner most loop making it "First + Middle + Last name".
                    // it also erases from tempStr after reading and storing to studentName variable.

                studentName = studentName + " " + splitString;
                tempStr.erase(0,sIndex+1);

            }
            else if (isdigit(splitString[0])){
                marks = marks + stoi(splitString);
                tempStr.erase(0,sIndex+1);
                                                            // if given split string is digit, it will store its value to marks array
                                                            // with index variable i and j which be incremented in inner and outer loop respectively.
                                                            // it also erases from tempStr after reading and storing to array.
                globalArr[j][i] = stoi(splitString);
                i++;
            }
        }

        j = j+1;        // incrementing j variable to be used inside loop.
        studentName1.push_back(studentName);      // storing full student name (fetched in inner loop) to studentName1 array for further use.

    }
    myfile.close();   // closing the file

}

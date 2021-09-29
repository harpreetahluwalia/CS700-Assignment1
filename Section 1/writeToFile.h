
/**
 *  @file   writeToFile.h
 *  @brief  consist methods to write the data to output file in well formatted fashion.
 *  @author Harpreet Singh
 *  @date   25/09/2021
 ***********************************************/


#pragma once
int flag2 = 0;

/**
 * Method : writeToFile
*  @author Harpreet Singh
 * @brief It creates the output file and write data into it in well formatted fashion.
 * @param studentName It holds the name of the student
 * @param numOfSub It holds the number of subjects
 * @param avgMarks It stores the marks of the student
 * @param grade It holds grade of the student.
  *
*/
void writeToFile(string studentName, int numOfSub, std::vector <int> marksArr, float avgMarks, string grade ){
    ofstream outfile;
    outfile.open("output_Section1.txt", ios_base::app);

    if (outfile.is_open())
    {
        if (flag2 == 0){

            outfile<<"\n ------------------------------------------------- Welcome to Section 1 ------------------------------------------------------------"<<endl;
            outfile<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            outfile << left << setw(25) << " Name" << setw(15) << "No. of scores"<< setw(15)<< "Average Score" << setw(20) << "Grade" << setw(30) << "Marks in each subject " << endl;
            outfile<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;

            flag2++;
        }

        // writing data to file
        outfile << left << setw(25) << studentName << setw(15)<< numOfSub << setw(15) <<fixed<< setprecision(2)<< avgMarks << setw(20)<< grade ;
        for (int i = 0; i < marksArr.size(); i++){
            outfile << left << setw(5) << marksArr[i] ;
        }
        outfile << endl;
    }
}


/**
 *  @file   writeToFile.h
 *  @brief  consist methods to write the data to output file in well formatted fashion.
 *  @author Harpreet Singh
 *  @date   26/09/2021
 ***********************************************/

/**
 * Method : writeToFile
 * @brief It creates the output file and write data into it in well formatted fashion.
 * @param numOfStudent Number of the students
 * @param numOfSub Number of Subjects
*/

void writeToFile(int numOfStudent, int numOfSub){
    int flag2 = 0;
    ofstream outfile;
    outfile.open("output_section2.txt", ios_base::trunc);
    if (outfile.is_open())
    {
        if (flag2 == 0){
            outfile<<"\n ------------------------------------------------------------------------- Welcome to Section 2 ----------------------------------------------------------------------------------------"<<endl;
            outfile<<"\n Total no. of Students : "<<numOfStudent<<setw(125)<<"\t"<<"Total no. of Subjects : "<<numOfSub<<endl;
            outfile<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            outfile<<left<<setw(30)<<" Name of Student "<<"\tMarks (Grade) - Marks and Grades of each exam"<<endl;
            outfile<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            flag2++;
        }


        for (int j =0; j<numOfStudent; j++ ){
            outfile<<left<<setw(30)<<studentName1[j+1]<<"\t";
            for (int i =0 ; i<numOfSub; i++){
                int marks = globalArr[j][i];
                float avg = avgMarks[i];
                string grade = gradeCalc(marks,avg);     //  calls gradeCalc function with marks and avg to get the grade for the particular student and subject.
                outfile<<setw(3)<<globalArr[j][i]<<" ("<<grade<<") "<<" \t";
            }
            outfile<<"\n";
        }
        outfile<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    }
}

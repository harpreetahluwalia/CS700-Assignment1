

/**
 *  @file   gradeAndAvgCalc.h
 *  @author Harpreet Singh
 *  @brief  Consist methods to calculate and display grades, in well formatted fashion, of each exam of every student based on the average score of each exam.
 *  @date   26/09/2021
 ***********************************************/



/**
 * Method : gradeCalc
 * @author Harpreet Singh
 * @brief It calculates and returns the grade for student based on given average
 * and marks for the student for particular subject
 * @param marks Marks of the student
 * @param avg Average of the subject
 *
 */

string gradeCalc(int marks,float avg){

    if (marks < avg-15){
        return "F";
    }else if(marks < avg-5){
        return "D";
    }else if(marks >= avg-5 & marks <= avg+5){
        return "C";
    }else if (marks > avg+5 & marks < avg+15){
        return "B";
    }else if (marks > avg+15){
        return "A";
    }
}

/**
 * Method : calcAvgofEach
 * @author Harpreet Singh
 * @brief It calculates average of each exam and stores it into the avgMarks array.
 * @param numOfStudent Number of the students
 * @param numOfSub Number of Subjects
*/
void calcAvgofEach(int numOfStudent, int numOfSub){
    for (int i = 0; i<numOfSub; i++){
        int sum = 0;
        for (int j = 0; j<numOfStudent; j++){
            sum = sum + globalArr[j][i];
        }
        float avg = float(sum) / numOfStudent;    //typecast sum integer value to float to get floating average.
        avgMarks[i] = avg;
    }

}

/**
 * Method : displayGrades
 * @author Harpreet Singh
 * @brief  It display grades of every student in each subject along with marks in well formatted fashion. .
 * @param numOfStudent Number of the students
 * @param numOfSub Number of Subjects
*/
void displayGrades(int numOfStudent, int numOfSub){
    cout<<"\n ------------------------------------------------------------------------- Welcome to Section 2 ----------------------------------------------------------------------------------------"<<endl;
    cout<<"\n Total no. of Students : "<<numOfStudent<<setw(125)<<"\t"<<"Total no. of Subjects : "<<numOfSub<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<left<<setw(30)<<" Name of Student "<<"\tMarks (Grade) - Marks and Grades of each exam"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    for (int j =0; j<numOfStudent; j++ ){
        cout<<left<<setw(30)<<studentName1[j+1]<<"\t";
        for (int i =0 ; i<numOfSub; i++){
            int marks = globalArr[j][i];
            float avg = avgMarks[i];
            string grade = gradeCalc(marks,avg);            //  calls gradeCalc function with marks and avg to get the grade for the particular student and subject.
            cout<<setw(3)<<globalArr[j][i]<<" ("<<grade<<") "<<" \t";
        }
        cout<<"\n";
    }

    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

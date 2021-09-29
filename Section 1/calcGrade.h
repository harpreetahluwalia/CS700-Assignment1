
/**
 *  @file   calcGrade.h
 *  @brief  consist method to calculate grades of the student based on the average marks.
 *  @author Harpreet Singh
 *  @date   25/09/2021
 ***********************************************/



/// including supporting libraries
#include<iostream>
#include<string>
#pragma once

/**
 * Method : calcGrade
 *  @author Harpreet Singh
 * @brief It calculates and returns the grade for student based on given average marks.
 * @param marks - average marks of the student.
*/
string calcGrade(float marks){
    if (marks > 95 && marks <= 100 ){
        return "A";
    }else if (marks > 91.67 && marks <= 95 ){
        return "A-";
    }else if (marks > 88.3 && marks <= 91.67 ){
        return "B+";
    }else if (marks > 85 && marks <= 88.3){
        return "B";
    }else if (marks > 81.67 && marks <= 85 ){
        return "B-";
    }else if (marks > 78.33 && marks <= 81.67 ){
        return "C+";
    }else if (marks > 75 && marks <= 78.33 ){
        return "C";
    }else if (marks > 71.67 && marks <= 75 ){
        return "C-";
    }else if (marks > 68.33 && marks <= 71.67 ){
        return "D+";
    }else if (marks > 65 && marks <= 68.33 ){
        return "D";
    }else if (marks > 61.67 && marks <= 65 ){
        return "D-";
    }else {
        return "F";
    }
}

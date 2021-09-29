
/**
 *  @file   spaceIndex.h
 *  @brief  It calculates and returns the index of first space in the given string.
 *  @author Harpreet Singh
 *  @date   25/09/2021
 ***********************************************/




#include<iostream>
#pragma once


/**
 * Method : spaceIndex
 *  @author Harpreet Singh
 * @brief : calculates and returns the index of first space in the given string
 * @param s a string where space index will be found
*/
int spaceIndex(string s){

    for (int i =0; i<s.size(); i++){
        if (s[i] == ' '){
            return i;
        }
    }
    return 0;
}

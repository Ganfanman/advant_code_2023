//
// Created by Ruixuan on 2023/12/3.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>

int StrLen(std::string str);

std::string RevString(std::string str);

int Trebuchet(std::string path);

int GetNum(std::string str);

// To get number from one line of string including number in English
std::vector<char> GetNumPlus(std::string str);

int TrebuchetPlus(std::string path);

#endif //UTILITY_H

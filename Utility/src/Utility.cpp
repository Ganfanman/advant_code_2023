//
// Created by Ruixuan on 2023/12/3.
//

#include "Utility.h"
#include <fstream>
#include <sstream>
#include <vector>

// To reverse a string
std::string RevString(std::string str)
{
    int str_len = StrLen(str);
    char new_str[str_len];
    new_str[str_len] = '\0';

    for(int i{0}; i < str_len; i++)
    {
        new_str[i] = str[str_len - 1 - i];
    }

    return new_str;
}

// To get string length
int StrLen(std::string str)
{
    int count{0};

    while(str[count] != '\0')
    {
        count++;
    }

    return count;
}

// To get the sum of number from file
int Trebuchet(std::string path)
{
    std::ifstream file;
    std::string data;
    int sum{0};

    file.open(path, std::ios::in);

    if(!file.is_open())
    {
        std::cerr << "file is not opened from " << path << std::endl;
    }
    else
    {
        while(std::getline(file, data))
        {
            int first_num{10*GetNum(data)};
            int second_num{GetNum(RevString(data))};
            sum += (first_num + second_num);
        }

        std::stringstream ss;
        ss << file.rdbuf();
        data = ss.str();
    }

    file.close();

    return sum;
}

// To get number from one line of string
int GetNum(std::string str)
{
    int number{0};

    if (str.empty())
    {
        std::cout << "invalid string" << std::endl;
    }
    else
    {
        int itr{0};
        while((str[itr] < 48 || str[itr] > 57) && str[itr] != '\0')
        {
            itr++;
        }

        if(str[itr] == '\0')
        {
            std::cout << "No number" << std::endl;
        }
        else
        {
            number = str[itr] - 48;
        }
    }

    return number;
}

// To get number from one line of string including number in English
std::vector<char> GetNumPlus(std::string str)
{
    std::vector<char> number;
    int str_len = StrLen(str);

    if (str.empty())
    {
        std::cout << "invalid string" << std::endl;
    }
    else
    {
        for(int i{0}; i < str_len; i++)
        {
            if((str[i] >= 48 && str[i] <= 57))
            {
                number.push_back(str[i]);
            }
            else
            {
                char letter = str[i];
                switch (letter)
                {
                    case 'o':
                        if ((i + 2 < str_len) && (str.substr(i, 3) == "one"))
                        {
                            number.push_back('1');
                        }
                        break;
                    case 't':
                        if ((i + 2 < str_len) && (str.substr(i, 3) == "two"))
                        {
                            number.push_back('2');
                        }
                        else if((i + 4 < str_len) && (str.substr(i, 5) == "three"))
                        {
                            number.push_back('3');
                        }
                        break;
                    case 'f':
                        if ((i + 3 < str_len) && (str.substr(i, 4) == "four"))
                        {
                            number.push_back('4');
                        }
                        else if ((i + 3 < str_len) && (str.substr(i, 4) == "five"))
                        {
                            number.push_back('5');
                        }
                        break;

                    case 's':
                        if ((i + 2 < str_len) && (str.substr(i, 3) == "six"))
                        {
                            number.push_back('6');
                        }
                        else if ((i + 4 < str_len) && (str.substr(i, 5) == "seven"))
                        {
                            number.push_back('7');
                        }
                        break;

                    case 'e':
                        if ((i + 4 < str_len) && (str.substr(i, 5) == "eight"))
                        {
                            number.push_back('8');
                        }
                        break;

                    case 'n':
                        if ((i + 3 < str_len) && (str.substr(i, 4) == "nine"))
                        {
                            number.push_back('9');
                        }
                        break;

                    default:
                        break;
                }
            }
        }
    }

    return number;
}

int TrebuchetPlus(std::string path)
{
    std::ifstream file;
    std::string data;
    int sum{0};

    file.open(path, std::ios::in);

    if(!file.is_open())
    {
        std::cerr << "file is not opened from " << path << std::endl;
    }
    else
    {
        while(std::getline(file, data))
        {
            std::vector<char> number;
            number = GetNumPlus(data);
            if(number.empty())
            {
                std::cout << "no number in this line" << std::endl;
            }
            else
            {
                sum += (10 * (number.front() - 48) + (number.back() - 48));
            }
        }
    }

    file.close();

    return sum;
}
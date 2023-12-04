//
// Created by Ruixuan on 2023/12/4.
//

#include "FindColorBall.h"
#include <iostream>

int FindColorBall(std::string str, std::string color)
{
    int ball_num{0};
    size_t pos_color{0};

    if(str.find(color) != std::string::npos)
    {
        pos_color = str.find(color);

        if(str[pos_color - 3] != ' ')
        {
            ball_num = 10*(str[pos_color - 3] - 48) + (str[pos_color - 2] - 48);
        }
        else
        {
            ball_num = str[pos_color - 2] - 48;
        }
    }

    return ball_num;
}
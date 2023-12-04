//
// Created by Ruixuan on 2023/12/4.
//

#include <iostream>
#include <fstream>
#include "GamePower.h"
#include "FindColorBall.h"

int GamePower(std::string path)
{
    std::ifstream data_file;
    std::string data;
    int power_num{0};

    data_file.open(path, std::ios::in);

    if(!data_file.is_open())
    {
        std::cerr << "file is not opened from " << path << std::endl;
    }
    else
    {
        while(std::getline(data_file, data))
        {
            int red{0}, blue{0}, green{0};
            data.append(";");

            while(data.find(";") != std::string::npos)
            {
                int red_temp{0}, blue_temp{0}, green_temp{0};
                int pos_begin{0};
                size_t pos_semicolon{data.find(";")};

                std::string temp{data.substr(pos_begin, pos_semicolon)};

                red_temp = FindColorBall(temp, "red");
                blue_temp = FindColorBall(temp, "blue");
                green_temp = FindColorBall(temp, "green");

                if(red_temp > red)
                {
                    red = red_temp;
                }

                if(blue_temp > blue)
                {
                    blue = blue_temp;
                }

                if(green_temp > green)
                {
                    green = green_temp;
                }

                data.erase(pos_begin, (pos_semicolon + 1));

            }

            power_num += red*blue*green;

        }
    }

    return power_num;
}
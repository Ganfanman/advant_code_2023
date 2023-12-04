//
// Created by Ruixuan on 2023/12/4.
//

#include "CubeConundrum.h"
#include "FindColorBall.h"
#include <fstream>


int CubeConundrum(std::string path)
{
    std::ifstream data_file;
    std::string data;
    int game_ID{1};
    int sum_ID{0};
    int flag{1};

    data_file.open(path, std::ios::in);

    if(!data_file.is_open())
    {
        std::cerr << "file is not opened from " << path << std::endl;
    }
    else
    {
        while(std::getline(data_file, data))
        {
            data.append(";");

            flag = 1;

            while(data.find(";") != std::string::npos)
            {
                int red{0}, blue{0}, green{0};
                int pos_begin{0};
                size_t pos_semicolon{data.find(";")};

                std::string temp{data.substr(pos_begin, pos_semicolon)};

                red = FindColorBall(temp, "red");
                blue = FindColorBall(temp, "blue");
                green = FindColorBall(temp, "green");

                if(red > 12 || green > 13 || blue > 14)
                {
                    flag = 0;
                    break;
                }

                data.erase(pos_begin, (pos_semicolon + 1));

            }

            if(flag == 1)
            {
                sum_ID += game_ID;
            }

            game_ID++;

        }
    }

    return sum_ID;
}

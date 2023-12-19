#define DOT 46

#include "PartNumberSum.h"

#include <iostream>
#include <fstream>

int PartNumberSum(std::string path)
{
    int pn_sum{0};
    int pn{0};
    int num_len{0};
    int num_end{0};
    bool is_first_line{true};
    bool is_num{false};
    bool is_pn{false};

    std::ifstream engine_ratio;
    std::string engine_line_last{"\0"}, engine_line{"\0"}, engine_line_next{"\0"};

    engine_ratio.open(path, std::ios::in);

    if(!engine_ratio.is_open())
    {
        std::cout << "The engine file is not open!" << std::endl;
    }
    else
    {
        std::getline(engine_ratio, engine_line);

        engine_line.insert(0, ".");
        engine_line.push_back('.');

        while(std::getline(engine_ratio, engine_line_next))
        {
            engine_line_next.insert(0, ".");
            engine_line_next.push_back('.');

            if(is_first_line) // at the first line
            {
                for(int i{0}; i < engine_line.length(); i++)
                {
                    engine_line_last.push_back('.');
                }

                is_first_line = false;
            }

            for(int i{0}; i < engine_line.length(); i++)
            {
                pn = 0;
                num_len = 0;
                is_num = false;
                is_pn = false;

                while(engine_line.at(i) < 58 && engine_line.at(i) > 47) // is number
                {
                    is_num = true;
                    num_len += 1;
                    pn = 10*pn + engine_line.at(i) - 48;
                    i++;
                }

                if(is_num)
                {
                    i--;
                    if(engine_line.at(i - num_len) != DOT || engine_line.at(i + 1) != DOT)
                    {
                        is_pn = true;
                    }else
                    {
                        for(int j{i - num_len}; j <  i + 2; j++)
                        {
                            if((engine_line_last.at(j) != DOT && (engine_line_last.at(j) < 48 || engine_line_last.at(j) > 57)) || (engine_line_next.at(j) != DOT && (engine_line_next.at(j) < 48 || engine_line_next.at(j) > 57)))
                            {
                                is_pn = true;
                                break;
                            }
                        }
                    }
                }

                if(is_pn)
                {
                    pn_sum += pn;
                }
            }

            engine_line_last = engine_line;
            engine_line = engine_line_next;
        }

        // for last line
        for(int i{0}; i < engine_line.length(); i++)
        {
            pn = 0;
            num_len = 0;
            is_num = false;
            is_pn = false;

            while(engine_line.at(i) < 58 && engine_line.at(i) > 47) // is number
            {
                is_num = true;
                num_len += 1;
                pn = 10*pn + engine_line.at(i) - 48;
                i++;
            }

            if(is_num)
            {
                i--;
                if(engine_line.at(i - num_len) != DOT || engine_line.at(i + 1) != DOT)
                {
                    is_pn = true;
                }else
                {
                    for(int j{i - num_len}; j <  i + 2; j++)
                    {
                        if(engine_line_last.at(j) != DOT && (engine_line_last.at(j) < 48 || engine_line_last.at(j) > 57))
                        {
                            is_pn = true;
                            break;
                        }
                    }
                }
            }

            if(is_pn)
            {
                pn_sum += pn;
            }
        }

        engine_ratio.close();
    }

    return pn_sum;
}
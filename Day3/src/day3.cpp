//
// Created by Ruixuan on 2023/12/17.
//

#define PATH "../Utility/data/day3.txt"

#include <iostream>
#include "PartNumberSum.h"

int main()
{
    int sum{0};

    sum = PartNumberSum(PATH);

    std::cout << sum << std::endl;

    return 0;
}


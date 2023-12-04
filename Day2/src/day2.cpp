//
// Created by Ruixuan on 2023/12/3.
//

#define DATA_PATH "../Utility/data/day2.txt"

#include <iostream>
#include "CubeConundrum.h"
#include "GamePower.h"

int main()
{
    int sum{};

    int power_sum{};

    sum = CubeConundrum(DATA_PATH);

    power_sum = GamePower(DATA_PATH);

    std::cout << sum << std::endl;
    std::cout << power_sum << std::endl;

    return 0;
}
//
// Created by Ruixuan on 2023/12/3.
//

#include <iostream>

#include "Utility.h"

#define DATA_PATH "../Utility/data/input.txt"

int main(){
    int sum1{}, sum2;

    sum1 = Trebuchet(DATA_PATH);
    sum2 = TrebuchetPlus(DATA_PATH);

    std::cout << sum1 << std::endl;
    std::cout << sum2 << std::endl;

    return 0;
}
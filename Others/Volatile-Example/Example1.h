#pragma once

#include <iostream>

namespace Example1 {

int address = 5;

volatile int* hardwareRegister = (int*) &address; // Адрес аппаратного регистра, например 0x40000000

void test1()
{
    *hardwareRegister = 5;
    int value = *hardwareRegister; // Чтение значения из регистра

    std::cout << "register value: " << value << std::endl;
}

} // namespace Example1

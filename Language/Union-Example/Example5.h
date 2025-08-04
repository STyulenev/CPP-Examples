#pragma once

#include <iostream>

/*
 * Передача больших объемов данных
 *
 * Иногда объединения полезны для передачи большого объема данных между функциями или потоками, когда заранее неизвестно
 * точный тип передаваемых данных. Использовать объединение таким способом удобно, если известно, что объект достаточно большой
 * и важен выбор правильного способа хранения.
 *
 */
namespace Example5
{

union BigData
{
    long l;
    double d;
    void *ptr;
};

BigData process_data(BigData bd)
{
    if ((long)bd.l > 0) {
        return bd;  // Возвращаем исходные данные
    } else {
        bd.d = 3.14;
        return bd;
    }
}

void test()
{
    BigData bd;
    bd.l = 1000;
    bd = process_data(bd);
    std::cout << "Processed result: " << bd.l << std::endl;
}

} // namespace Example5

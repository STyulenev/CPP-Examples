#pragma once

#include <string>

/*
 * Класс-продукт содержит несколько методов построения, которые будут вызываны в конкретном строителе
 * для задействования построения объекта
 */
class Product
{
public:
    Product();
    ~Product();

    void makeA(const std::string& part);
    void makeB(const std::string& part);
    void makeC(const std::string& part);

    /*
     * Полезный метод, который будет использоваться после построения
     */
    std::string get();
    // ...

private:
    std::string partA;
    std::string partB;
    std::string partC;
    // ...

};

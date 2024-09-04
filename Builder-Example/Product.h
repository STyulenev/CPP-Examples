#pragma once

#include <string>

class Product
{
public:
    Product();
    ~Product();

    void makeA(const std::string& part);
    void makeB(const std::string& part);
    void makeC(const std::string& part);
    std::string get();
    // ...

private:
    std::string partA;
    std::string partB;
    std::string partC;
    // ...

};

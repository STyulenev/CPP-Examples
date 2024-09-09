#pragma once

class Resource
{
private:
    int value;

public:
    Resource();

    void reset();
    int getValue();
    void setValue(int number);

};

#pragma once

class CustomClass
{
public:
    CustomClass(int data = 0);
    ~CustomClass();

    void setData(int data);
    int getData() const;

private:
    int m_data_;
    // ...

};

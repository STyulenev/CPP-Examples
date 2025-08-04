#pragma once

#include <iostream>
#include <variant>

/*
 * Объединение с различимыми тегами (tagged unions)
 *
 * При хранении разных типов полезно указывать, какой именно тип хранится в данный момент. Обычно это делается с помощью дополнительной
 * переменной («тега»), которая хранит информацию о текущем состоянии объединения. Этот подход предотвращает случайное неправильное чтение
 * поля другого типа.
 *
 */
namespace Example2
{

enum class TypeTag
{
    INT,
    FLOAT
};

struct TaggedUnion
{
    TypeTag tag;

    union Data
    {
        int i;
        float f;
    } data;

    std::variant<int, float> get()
    {
        switch(tag) {
        case TypeTag::INT:
            return data.i;
        case TypeTag::FLOAT:
            return data.f;
        }
    }

    template<class T>
    void set(T value)
    {
        if (std::is_same<T, int>::value)
        {
            tag = TypeTag::INT;
            data.i = value;
        }
        else if (std::is_same<T, float>::value)
        {
            tag = TypeTag::FLOAT;
            data.f = value;
        }
        else
        {
            // ...
        }
    }

    void print()
    {
        switch(tag) {
        case TypeTag::INT:
            std::cout << "Stored integer: " << data.i << std::endl;
            break;
        case TypeTag::FLOAT:
            std::cout << "Stored float: " << data.f << std::endl;
            break;
        }
    }
};

void test()
{
    TaggedUnion tu;

    tu.tag = TypeTag::INT;
    tu.data.i = 42;
    tu.print();

    tu.tag = TypeTag::FLOAT;
    tu.data.f = 3.14f;
    tu.print();

    tu.set(6);
    tu.print();

    tu.set(6.1f);
    auto w = tu.get();
    try
    {
        std::cout << "data = " << std::get<float>(w) << std::endl;
    }
    catch (const std::bad_variant_access& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

} // namespace Example2

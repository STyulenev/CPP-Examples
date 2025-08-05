#pragma once

#include <iostream>

/*
 *
 * Использование enum в шаблонах
 *
 */
namespace Example2
{

// Использование enum в шаблонах для выбора нужного метода
namespace Ex1
{

struct Value {};
struct Color {};
struct Size {};
struct Point {};

enum class Property
{
    Color,
    StrokeColor,
    Opacity,
    Size,
    Position,
};

class Dom
{
public:
    template<Property prop, typename AnyValue>
    void setValue(const std::string& obj, AnyValue value)
    {
        setValue(std::integral_constant<Property, prop>{}, obj, value);
    }

private:
    // Специализированные скрытые методы
    void setValue(std::integral_constant<Property, Property::Color> type, const std::string &obj, Color col)
    {
        std::cout << "- update color property" << std::endl;
    }

    void setValue(std::integral_constant<Property, Property::StrokeColor> type, const std::string &obj, Color col)
    {
        std::cout << "- update stroke color property" << std::endl;
    }

    void setValue(std::integral_constant<Property, Property::Size> type, const std::string &obj, Size size)
    {
        std::cout << "- update size property" << std::endl;
    }

};

} // namespace Ex1

// Использование enum для выбора нужного метода в шаблоне
void test1()
{
    Ex1::Dom domObj;

    domObj.setValue<Ex1::Property::Color>("layer1.rect1", Ex1::Color());  // Ок
    //domObj.setValue<Ex1::Property::Color>("layer1.rect1", Ex1::Size()); // Ошибка
    domObj.setValue<Ex1::Property::Size>("layer1.rect1", Ex1::Size());    // Ок
}

namespace Ex2
{

    class Types
    {
    public:
        enum Values
        {
            TYPE_0 = 0,
            TYPE_1 = 1
            // ...
        };

        // ...
    };

    class IBase {
    public:
        virtual int getType() const = 0;
        // ...

    };

    template <int iType>
    class AbstractBase : public IBase
    {
    public:
        AbstractBase() = default;

        int getType() const override
        {
            return staticType();
        }

    private:
        static int staticType()
        {
            return iType;
        }

    };

    class Type0 : public AbstractBase<Types::TYPE_0>
    {
    public:
            // ...
    };

    class Type1 : public AbstractBase<Types::TYPE_1>
    {
    public:
            // ...
    };

} // namespace Ex2

// Использование enum для типизации класса
void test2()
{
    using namespace Ex2;

    Type0 type0;
    Type1 type1;

    std::cout << "Type: " << type0.getType() << std::endl;
    std::cout << "Type: " << type1.getType() << std::endl;
}

} // namespace Example2

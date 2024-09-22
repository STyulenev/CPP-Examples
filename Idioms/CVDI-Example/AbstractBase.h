#pragma once

/*
 * Абстрактный класс с CVDI (Calling Virtuals During Initialization, вызов виртуальных методов во время инициализации)
 *
 * Иногда желательно вызывать виртуальные функции производных классов во время инициализации производного объекта.
 * Правила языка явно запрещают это делать, поскольку вызов функций-членов производного объекта до инициализации
 * производной части объекта опасен. Не проблема, если виртуальная функция не обращается к членам данных конструируемого
 * объекта, но общего способа гарантировать это не существует.
 *
 * Пример без CVDI:
 * class AbstractBase {
 * };
 *
 * template <class ClassType>
 * class InitTimeCaller : public AbstractBase {
 * protected:
 *     InitTimeCaller () {
 *         ClassType::method_1();
 *         ClassType::method_2();
 *     }
 * };
 *
 * class ConcreteClass : public InitTimeCaller<ConcreteClass>
 * {
 * public:
 *     ConcreteClass() : InitTimeCaller<ConcreteClass> () {
 *         cout << "ConcreteClass()" << std::endl;
 *     }
 *     static void method_1() {
 *         cout << "ConcreteClass::method_1" << std::endl;
 *     }
 *     static void method_2() {
 *         cout << "ConcreteClass::method_2" << std::endl;
 *     }
 * };
 */
class AbstractBase
{
public:
    AbstractBase(int parameter);
    virtual ~AbstractBase();

    /*
     * Метод для инициализации виртуальных методов при создании экземпляра класса, но вне конструктора
     */
    void initialization();

    virtual void method_1() const = 0;
    virtual void method_2() const = 0;
    // ...

private:
    int m_parameter;
    // ...

};

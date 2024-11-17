#pragma once

/*!
 * \brief Абстрактный Класс определяет шаблонного метода, который содержит заданный алгоритм
 */
class AbstractClass
{
public:
    /*!
     * \brief Шаблонный метод с заданным алгоритмом работы
     */
    void TemplateMethod() const;

protected:
    /*!
     * \brief Базовые реализованные по умолчанию методы
     */
    void baseAction1() const;
    void baseAction2() const;
    void baseAction3() const;

    /*!
     * \brief Пользовательские обязательные функции
     */
    virtual void requiredAction1() const = 0;
    virtual void requiredAction2() const = 0;

    /*!
     * \brief Пользовательские не обязательные функции
     */
    virtual void optionalAction1() const;
    virtual void optionalAction2() const;

};

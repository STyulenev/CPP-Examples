#pragma once

#include <string>

/*!
 * \brief Базовый класс-компонент
 */
class Component
{
protected:
    Component* parent_;

public:
    Component();
    virtual ~Component();

    void setParent(Component* parent);
    Component* getParent() const;

    virtual void add(Component* component);
    virtual void remove(Component* component);

    /*!
   * \brief Метод проверяет компонент на вложенность
   */
    virtual bool IsComposite() const;

    /*!
   * \brief Метод для полезных действий
   */
    virtual std::string someAction() const = 0;

};

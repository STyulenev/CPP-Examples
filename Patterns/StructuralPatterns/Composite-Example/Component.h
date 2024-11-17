#pragma once

#include <string>

/*
 * Базовый класс-компонент для создания элемента дерева компонентов.
 */
class Component
{
protected:
    Component* parent_;

public:
    Component();
    virtual ~Component();

    /*
     * Метод для установления родителя
     */
    void setParent(Component* parent);

    /*
     * Метод для получения указателя на родителя
     */
    Component* getParent() const;

    /*
     * Метод для добавления нового листа/ветки
     */
    virtual void add(Component* component);

    /*
     * Метод для удаления листа/ветки
     */
    virtual void remove(Component* component);

    /*
     * Метод проверяет компонент на вложенность
     */
    virtual bool isComposite() const;

    /*
     * Метод для полезных действий
     */
    virtual std::string someAction() const = 0;

};

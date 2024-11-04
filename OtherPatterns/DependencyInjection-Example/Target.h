#pragma once

class Logic;

/*
 * Целевой класс, который имеет внешнюю зависимость от интерфейса Logic
 */
class Target
{
public:
    Target(Logic* logic = nullptr);
    ~Target();

    void setLogic(Logic* logic);

    void action();

private:
    Logic* m_logic;

};

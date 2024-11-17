#include "Target.h"

#include "Logic.h"

Target::Target(Logic* logic)
{
    if (logic == nullptr)
        m_logic = new ConcreteLogic1();
}

Target::~Target()
{
    delete m_logic;

    // ...
}

void Target::setLogic(Logic* logic)
{
    delete m_logic;

    m_logic = logic;
}

void Target::action()
{
    m_logic->someAction();
}

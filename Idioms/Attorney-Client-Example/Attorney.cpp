#include "Attorney.h"

#include "AbstractBase.h"

void Attorney::callAction1(AbstractBase& b, int value)
{
    return b.action1(value);
}

void Attorney::callAction2(AbstractBase& b)
{
    b.action2();
}

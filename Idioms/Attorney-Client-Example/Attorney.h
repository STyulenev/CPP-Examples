#pragma once

class AbstractBase;

/*
 * Класс-адвокат предназначен для доступа к закрытым членам класса AbstractBase. При этом все его методы закрыты
 * и лишь дружественные классы/функции могут обратиться к его закрытым членам, которые затем могут вызвать закрытые
 * члены класса AbstractBase.
 */
class Attorney
{
    // Список дружественных классов/функций
    friend int main();
    // ...

private:
    // Список статических методов для вызова дружественными классами/функциями
    static void callAction1(AbstractBase& b, int value);
    static void callAction2(AbstractBase& b);
    // ...

};
